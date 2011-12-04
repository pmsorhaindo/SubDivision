/*
 * Face.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

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
	Vertex calcCentroid();
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
