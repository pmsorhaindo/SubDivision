//============================================================================
// Name        : SubDivide.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : Organizes my subdivision program to run
//               both implementations recursively. - in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SubDivide.h"

using namespace std;

/*
 * Creates an initial unit cubeof 12 triangles
 * whose center is the origin.
 */
SubDivide::SubDivide() {
	iterations = 0;
	type = 0;
	cube = new SetUpCube;
}

/*
 * Applies Subdivision to the current shape by renaming the last shape as the first shape.
 * and creating a new current shape which is a subdivided last shape.
 * The iteration count is also incremented.
 */
void SubDivide::apply(int newtype) {
	if(type == 0)
	{
		type = newtype;
	}

	if(iterations == 0&&type==1){
		currentCatmull = new Catmull(cube->returnSizeOfVertexArray(),cube->returnSizeOfEdgeArray(),cube->returnSizeOfFaceArray(),cube->returnVertexArrayPtr(),cube->returnEdgeArrayPtr(),cube->returnFaceArrayPtr());
		iterations++;
	}
	else if (iterations == 0&&type==2){
		currentButterfly = new Butterfly(cube->returnSizeOfVertexArray(),cube->returnSizeOfEdgeArray(),cube->returnSizeOfFaceArray(),cube->returnVertexArrayPtr(),cube->returnEdgeArrayPtr(),cube->returnFaceArrayPtr());
		iterations++;
	}
	else if (iterations>0&&type==1)
	{
		lastCatmull = currentCatmull;
		currentCatmull = new Catmull(lastCatmull->returnSizeOfVertexArray(),lastCatmull->returnSizeOfEdgeArray(),lastCatmull->returnSizeOfFaceArray(),lastCatmull->returnVertexArrayPtr(),lastCatmull->returnEdgeArrayPtr(),lastCatmull->returnFaceArrayPtr());
		iterations++;
	}
	else if (iterations>0&&type==2)
	{
		lastButterfly = currentButterfly;
		currentButterfly = new Butterfly(lastButterfly->returnSizeOfVertexArray(),lastButterfly->returnSizeOfEdgeArray(),lastButterfly->returnSizeOfFaceArray(),lastButterfly->returnVertexArrayPtr(),lastButterfly->returnEdgeArrayPtr(),lastButterfly->returnFaceArrayPtr());
		iterations++;
	}

	cout << "Type C to apply Catmull-Clark\nType B to apply Butterfly\nType P to toggle Points\nType L to toggle Lines/Edges\nType O to toggle Faces\n" <<
			"or press the Spacebar to Print the status to the screen...\n\n";
}

/*
 * Depending on the number of iterations and the type of the value held
 */
void SubDivide::draw(bool faces, bool lines, bool points) {

	if(iterations == 0){
		cube->draw(faces,lines,points);
	}
	else if (iterations>0&&type==1)
	{
		currentCatmull->draw(faces,lines,points);
	}
	else if (iterations>0&&type==2)
	{
		currentButterfly->draw(faces,lines,points);
	}
}

/*
 * The following function prints on demand the status of the subdivison class,
 * printing to the console the Subdivision scheme used and the number of iterations.
 */
void SubDivide::printState() {
	if(type==0)
	{
		cout << "Status: Unit Cube, unsubdivided.\n";
	}
	else if(type==1)
	{
		cout << "Status: Unit Cube, Subdivision Scheme Catmull-Clark, Iterations " << iterations << endl;
	}
	else if(type==2)
	{
		cout << "Status: Unit Cube, Subdivision Scheme Butterfly, Iterations " << iterations << endl;
	}
}

SubDivide::~SubDivide() {
	// Destructor
}
