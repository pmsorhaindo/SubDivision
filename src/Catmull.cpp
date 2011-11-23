/*
 * Catmull.cpp
 *
 *  Created on: 9 Nov 2011
 *      Author: mikey
 */

#include "Catmull.h"

Catmull::Catmull() {
	// TODO Auto-generated constructor stub

}

Catmull::Catmull(int v, int e, int f){
	//TODO split setUpCube!
	Face faceArray[f];
	Edge edgeArray[e];
	Vertex vertexArray[v];

	//assign pointers to arrays
	//Vertex * vertexArrayPtr;
	vertexArrayPtr = vertexArray;
	//Face * faceArrayPtr;
	faceArrayPtr = faceArray;
	//Edge * edgeArrayPtr;
	edgeArrayPtr = edgeArray;

}

Catmull::~Catmull() {
	// TODO Auto-generated destructor stub
}
