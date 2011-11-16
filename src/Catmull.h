/*
 * Catmull.h
 *
 *  Created on: 9 Nov 2011
 *      Author: mikey
 */

#ifndef CATMULL_H_
#define CATMULL_H_
#include "SetUpCube.h"

class Catmull {
//Take a Face-Edge-Vertex data structure and Subdivide
private:
	Vertex * vArray;
	Edge * eArray;
	Face * fArray;

public:
	Catmull();
	Catmull(Vertex * vArray, Edge * eArray, Face * fArray);
	virtual ~Catmull();
};

#endif /* CATMULL_H_ */
