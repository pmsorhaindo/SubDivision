//============================================================================
// Name        : Butterfly.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class implements and stiches up Butterfly Subdivison. - in C++, Ansi-style
//============================================================================

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
	void draw(bool faces = true, bool lines = false, bool points = false);
	int returnSizeOfVertexArray();
	int returnSizeOfEdgeArray();
	int returnSizeOfFaceArray();
	Vertex * returnVertexArrayPtr();
	Edge * returnEdgeArrayPtr();
	Face * returnFaceArrayPtr();
};

#endif /* BUTTERFLY_H_ */
