//============================================================================
// Name        : Face.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This allows for the storage of Triangular faces. To store four sided faces
//               I use a seperate class called QFace. - in C++, Ansi-style
//============================================================================

#ifndef FACE_H_
#define FACE_H_
#include "Edge.h"

class Face {

private:
	Edge *a;
	Edge *b;
	Edge *c;
	Vertex facePoint;
	bool edgeAReversed;
	bool edgeBReversed;
	bool edgeCReversed;

public:
	Face();
	Face(Edge * newA, Edge * newB, Edge * newC);
	Face(Edge * newA, bool revA, Edge * newB, bool revB, Edge * newC, bool revC);
	virtual ~Face();
	Edge* getEdgeA();
	Edge* getEdgeB();
	Edge* getEdgeC();
	void setCentroid();
	Vertex getCentroid();
	bool getEdgeADirection();
	bool getEdgeBDirection();
	bool getEdgeCDirection();
	Vertex * getPointA();
	Vertex * getPointB();
	Vertex * getPointC();
};

#endif /* FACE_H_ */
