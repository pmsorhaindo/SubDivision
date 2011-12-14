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

void SubDivide::apply(int type) {

	if(iterations == 0&&type==1){
		currentCatmull = new Catmull(cube->returnSizeOfVertexArray(),cube->returnSizeOfEdgeArray(),cube->returnSizeOfFaceArray(),cube->getVertexArray(),cube->getEdgeArray(),cube->getFaceArray());
	}
	else if (iterations == 0&&type==2){
		currentButterfly = new Butterfly(cube->returnSizeOfVertexArray(),cube->returnSizeOfEdgeArray(),cube->returnSizeOfFaceArray(),cube->getVertexArray(),cube->getEdgeArray(),cube->getFaceArray());
	}
	else if (iterations>0&&type==1)
	{

	}
	else if (iterations>0&&type==2)
	{
		currentButterfly->draw();
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
