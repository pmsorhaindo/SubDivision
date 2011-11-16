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

Catmull::Catmull(Vertex * vArray, Edge * eArray, Face * fArray){
	SetUpCube unitCube  = SetUpCube();
	unitCube.getFaceArray();
	//TODO split setUpCube!
}

Catmull::~Catmull() {
	// TODO Auto-generated destructor stub
}
