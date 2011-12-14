//============================================================================
// Name        : Cube.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : Subdivision of a Unit Cube in C++, Ansi-style
//============================================================================

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
#include <iostream>
#include "SetUpCube.h"
#include "Catmull.h"
#include "Butterfly.h"
#include "SubDivide.h"

using namespace std;

#define RUN_GRAPHICS_DISPLAY 0x00 ;
/*
 *  An instance of the Subdivide class is created.
 *  This creates a unit cube for display with the default constructor and allows
 *  access to my implementations of Catmull-Clark and Butterfly Subdivision
 */
SubDivide sub = SubDivide();

// Global switches to choose whether to draw the lines, points and faces.
bool faces = true;
bool lines = true;
bool points= true;

Uint32 display (Uint32 interval , void *param) {
	SDL_Event event;
	event.type=SDL_USEREVENT;
	event.user.code=RUN_GRAPHICS_DISPLAY;
	event.user.data1=0;
	event.user.data2=0;
	SDL_PushEvent(&event);
	return interval;
}

void display () {
	//Simple draw call - the decision of what to draw is made by the Subdivision class.
	sub.draw(faces,lines,points);
	SDL_GL_SwapBuffers();
}


int main(int argc,char * * argv ) {
	// Some boilerplate SDL and OpenGL code -taken from lecture 1.
	SDL_Surface * surf ;
	Uint32 width = 640 ;
	Uint32 height = 480 ;
	Uint32 colour_depth = 16 ; // in bits
	Uint32 delay = 1000/60; // in milliseconds
	// Initialise SDL - when using C/C++ it's common to have to
	// initialise libraries by calling a function with in them .
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER) <0) {
		cout << "Failed to initialise SDL: " << SDL_GetError ( ) << endl;
		SDL_Quit ();
	}
	// When we close a window quit the SDL application
	atexit(SDL_Quit) ;
	// Create a new window with an OpenGL surface
	if (!(surf = SDL_SetVideoMode (width,height,colour_depth,SDL_OPENGL))) {
		cout << "Failed to initialise video mode : " << SDL_GetError () << endl;
		SDL_Quit ();
	}

	// Set the state of our new OpenGL context
	glViewport (0,0,(GLsizei)(width),(GLsizei)(height));
	glMatrixMode (GL_PROJECTION) ;
	glLoadIdentity () ;
	gluPerspective(45.0f,(GLfloat)(width)/(GLfloat)(height),1.0f,1000.0f);
	glMatrixMode (GL_MODELVIEW) ;
	glLoadIdentity();
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearColor(0.0f,0.0f,0.0f,0.5f); // Black Background
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable (GL_DEPTH_TEST); // Enables Depth Testing
	glDepthFunc (GL_LEQUAL); //  The Type Of Depth Testing To Do
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ) ; // Really Nice Perspective Calculation
	SDL_AddTimer (delay,display,NULL) ; //Call the function "display (Uint32 interval, void * param )" every delay milliseconds

	// Add the main event loop
	SDL_Event event;

	while (SDL_WaitEvent(&event) ) {
		switch (event.type) {
			case SDL_QUIT:
			SDL_Quit();
			break;
			case SDL_USEREVENT:
			display ();
			break;
		}

		// A SDL keyboard handling loop.
		// Assisted by http://sdl.beuc.net/sdl.wiki/Handling_the_Keyboard
		while( SDL_PollEvent( &event ) ){
			switch( event.type ){
				case SDL_KEYDOWN:
				cout << "Key press detected\n";
				switch (event.key.keysym.sym){

					//Apply catmull clark on a 'c' key press
					case SDLK_c:
						sub.apply(1);
						break;
					//Apply Butterfly on a 'b' key press
					case SDLK_b:
						sub.apply(2);
						break;

					// Reversing/switching the current values of lines points and faces.
					// Toggle lines on 'l'
					case SDLK_l:
						lines = !lines;
						break;
					// Toggle points on 'p'
					case SDLK_p:
						points = !points;
						break;
					// Toggle faces on 'f'
					case SDLK_o:
						faces = !faces;
						break;

					default:
						break;
				}

				case SDL_KEYUP:
					cout << "Key release detected\n";
					break;

				/* SDL_QUIT event (window close) */
				case SDLK_ESCAPE:
					void SDL_Quit(void);
					break;

				case SDL_QUIT:
					void SDL_Quit(void);
					break;

				default:
					break;
			}
		}
	}
	return 0;
}
