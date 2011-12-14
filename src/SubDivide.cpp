/*
 * SubDivide.cpp
 *
 *  Created on: 14 Dec 2011
 *      Author: mikey
 */

#include "SubDivide.h"

SubDivide::SubDivide() {
	iterations = 0;
	type = 0;
	cube = new SetUpCube;
}

void SubDivide::apply(int newtype) {
	type = newtype;

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

}

void SubDivide::draw() {

	if(iterations == 0){
		cube->draw();
	}
	else if (iterations>0&&type==1)
	{
		currentCatmull->draw();
	}
	else if (iterations>0&&type==2)
	{
		currentButterfly->draw();
	}
}

SubDivide::~SubDivide() {
	// TODO Auto-generated destructor stub
}
