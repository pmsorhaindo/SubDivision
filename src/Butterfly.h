/*
 * Butterfly.h
 *
 *  Created on: 11 Dec 2011
 *      Author: mikey
 */

#ifndef BUTTERFLY_H_
#define BUTTERFLY_H_
#include "GeometryOps.h"
#include <iostream>

class Butterfly {

private:
	Face * faceArray;
	Edge * edgeArray;
	Vertex * vertexArray;
	float rotAng;
	int sizeOfVertexArray;
	int sizeOfEdgeArray;
	int sizeOfFaceArray;

public:
	Butterfly();
	Butterfly(int v, int e, int f, Vertex *ova, Edge *oea, Face *ofa);
	virtual ~Butterfly();
	Vertex getNewEdgePoint(Edge * edgeToWork,Edge * oldEdges, int numberOfEdges, Face * oldFaces, int numberOfOldFaces);
	void draw();
};

#endif /* BUTTERFLY_H_ */
