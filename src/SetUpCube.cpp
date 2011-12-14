//============================================================================
// Name        : SetUpCube.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : Generates and draws a basic unit cube centered over the
//               origin (0,0,0). - in C++, Ansi-style
//============================================================================

#include <GL/gl.h>
#include <GL/glu.h>
#include "SetUpCube.h"
#include <iostream>

using namespace std;
//TODO Rename from SetupCube?
SetUpCube::SetUpCube() {

	//cout<<"cube starts setting up!\n";
	vertexArray[0] = Vertex(-0.5f,-0.5f,0.5f);
	vertexArray[1] = Vertex(0.5f,-0.5f,0.5f);
	vertexArray[2] = Vertex(0.5f,0.5f,0.5f);
	vertexArray[3] = Vertex(-0.5f,0.5f,0.5f);
	vertexArray[4] = Vertex(-0.5f,-0.5f,-0.5f);
	vertexArray[5] = Vertex(0.5f,-0.5f,-0.5f);
	vertexArray[6] = Vertex(0.5f,0.5f,-0.5f);
	vertexArray[7] = Vertex(-0.5f,0.5f,-0.5f);
	//cout<< "cube Vertices set up\n";

	edgeArray[0] = Edge(&vertexArray[3],&vertexArray[2]); // a 1
	edgeArray[1] = Edge(&vertexArray[2],&vertexArray[6]); // b 2
	edgeArray[2] = Edge(&vertexArray[6],&vertexArray[7]); // c 3
	edgeArray[3] = Edge(&vertexArray[7],&vertexArray[3]); // d 4
	edgeArray[4] = Edge(&vertexArray[2],&vertexArray[7]); // e 5
	edgeArray[5] = Edge(&vertexArray[1],&vertexArray[2]); // f 6
	edgeArray[6] = Edge(&vertexArray[0],&vertexArray[1]); // g 7
	edgeArray[7] = Edge(&vertexArray[0],&vertexArray[3]); // h 8
	edgeArray[8] = Edge(&vertexArray[2],&vertexArray[0]); // i 9
	edgeArray[9] = Edge(&vertexArray[0],&vertexArray[4]); // j 10
	edgeArray[10] = Edge(&vertexArray[5],&vertexArray[1]); // k 11
	edgeArray[11] = Edge(&vertexArray[4],&vertexArray[5]); // l 12
	edgeArray[12] = Edge(&vertexArray[4],&vertexArray[1]); // m 13
	edgeArray[13] = Edge(&vertexArray[7],&vertexArray[4]); // n 14
	edgeArray[14] = Edge(&vertexArray[5],&vertexArray[6]); // o 15
	edgeArray[15] = Edge(&vertexArray[4],&vertexArray[6]); // p 16
	edgeArray[16] = Edge(&vertexArray[3],&vertexArray[4]); // q 17
	edgeArray[17] = Edge(&vertexArray[2],&vertexArray[5]); // r 18
	//cout<< "cube Edges set up\n";

	faceArray[0] = Face(&edgeArray[2],false,&edgeArray[4],true,&edgeArray[1],false); //top back g
	faceArray[1] = Face(&edgeArray[3],false,&edgeArray[0],false,&edgeArray[4],false); //top front g a
	faceArray[2] = Face(&edgeArray[7],false,&edgeArray[0],false,&edgeArray[8],false); // front top g a
	faceArray[3] = Face(&edgeArray[8],false,&edgeArray[6],false,&edgeArray[5],false); //front bottom g a
	faceArray[4] = Face(&edgeArray[9],false,&edgeArray[12],false,&edgeArray[6],true); // bottom front g
	faceArray[5] = Face(&edgeArray[12],true,&edgeArray[11],false,&edgeArray[10],false); //bottom back g
	faceArray[6] = Face(&edgeArray[11],false,&edgeArray[14],false,&edgeArray[15],true); // back bottom g
	faceArray[7] = Face(&edgeArray[13],false,&edgeArray[15],false,&edgeArray[2],false); //Back top a
	faceArray[8] = Face(&edgeArray[3],true,&edgeArray[13],false,&edgeArray[16],true); // left top
	faceArray[9] = Face(&edgeArray[16],false,&edgeArray[9],true,&edgeArray[7],false); //left bottom
	faceArray[10] = Face(&edgeArray[14],true,&edgeArray[17],true,&edgeArray[1],false); // right top
	faceArray[11] = Face(&edgeArray[17],false,&edgeArray[10],false,&edgeArray[5],false); // right bottom a
	cout<< "cube Faces set up\n";

	sizeOfEdgeArray = 18;
	sizeOfVertexArray = 8;
	sizeOfFaceArray = 12;


	//angle variable to rotate the cube.
	rotAng = 0.0f;

	//assign pointers to arrays
	//Vertex * vertexArrayPtr;
	vertexArrayPtr = vertexArray;
	//Face * faceArrayPtr;
	faceArrayPtr = faceArray;
	//Edge * edgeArrayPtr;
	edgeArrayPtr = edgeArray;

	//MAKE NEW FACE EDGE VERTEX STRUCTURE¬!"!!!!!
	//ok here we go..
	Vertex newVertexArray[50];
	Vertex *newVertexArrayPtr = newVertexArray;

	int totalNewVerts = 0;
	int totalNewEdges = 0;
	int totalNewFaces = 0;
}

SetUpCube::~SetUpCube() {
	// TODO Auto-generated destructor stub
}

Face * SetUpCube::getFaceArray(){
	return faceArray;
}

/*
 * Drawing function loads translates and rotates the OpenGL camera and draws the faces
 * lines and points if their respective parameters which are passed are true.
 */
void SetUpCube::draw(bool faces, bool lines, bool points){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
		// Reset The Current Modelview Matrix
		glLoadIdentity();
		// put the thing somewhere between the near and far clipping panes
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(rotAng,0.0f,0.5f,1.0);

		if(faces){
			// For each face get each unique point in the Face get its X,Y and Z values for use in glVertex3f within GL_TRIANGLES.
			for(int i=0;i<12;i++)
				{
				glBegin(GL_TRIANGLES);
				//OpenGL must be counter clockwise!

				if(i%2==1)
				{
					glColor3f(1.0f,0.0f,0.0f); //Red
				}
				else
				{
					glColor3f(0.0f,0.0f,1.0f); //Blue
				}

				if(faceArray[i].getEdgeADirection())
				{
					glVertex3f(faceArray[i].getEdgeA()->getVertexB()->getX(),faceArray[i].getEdgeA()->getVertexB()->getY(),faceArray[i].getEdgeA()->getVertexB()->getZ());
					glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ()); //
				}
				else
				{
					glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ());
					glVertex3f(faceArray[i].getEdgeA()->getVertexB()->getX(),faceArray[i].getEdgeA()->getVertexB()->getY(),faceArray[i].getEdgeA()->getVertexB()->getZ());
				}

				if(faceArray[i].getEdgeBDirection())
				{
					glVertex3f(faceArray[i].getEdgeC()->getVertexB()->getX(),faceArray[i].getEdgeB()->getVertexA()->getY(),faceArray[i].getEdgeB()->getVertexA()->getZ());
				}
				else
				{
					glVertex3f(faceArray[i].getEdgeC()->getVertexA()->getX(),faceArray[i].getEdgeB()->getVertexB()->getY(),faceArray[i].getEdgeB()->getVertexB()->getZ());
				}
				glEnd();
			}
		}

		// Drawing code for lines. If requested.
		if(lines)
		{
			for (int j =0; j<sizeOfEdgeArray;j++)
			{
				glBegin(GL_LINES);
				glColor3f(1.0f,1.0f,1.0f);

				glVertex3f(edgeArray[j].getVertexA()->getX(),edgeArray[j].getVertexA()->getY(),edgeArray[j].getVertexA()->getZ());
				glVertex3f(edgeArray[j].getVertexB()->getX(),edgeArray[j].getVertexB()->getY(),edgeArray[j].getVertexB()->getZ());

				glEnd();
			}
		}

		// Drawing code for points. If requested.
		if (points)
		{
			for (int j =0; j<sizeOfVertexArray;j++)
			{
				glBegin(GL_POINTS);
				//OpenGL must be counter clockwise!

				glColor3f(1.0f,1.0f,0.0f);

				glVertex3f(vertexArray[j].getX(),vertexArray[j].getY(),vertexArray[j].getZ());

				glEnd();
			}
		}

		rotAng += 0.2;
}

// Returning pointers and sizes of arrays for use on the next iteration of Subdivision.
Face * SetUpCube::returnFaceArrayPtr()
{
	return faceArrayPtr;
}

Edge * SetUpCube::returnEdgeArrayPtr()
{
	return edgeArrayPtr;
}

Vertex * SetUpCube::returnVertexArrayPtr()
{
	return vertexArrayPtr;
}

int SetUpCube::returnSizeOfVertexArray(){
	return sizeOfVertexArray;
}

int SetUpCube::returnSizeOfEdgeArray(){
	return sizeOfEdgeArray;
}

int SetUpCube::returnSizeOfFaceArray(){
	return sizeOfFaceArray;
}
