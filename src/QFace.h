/*
 * QFace.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#ifndef QFACE_H_
#define QFACE_H_
#include "Edge.h"

class QFace {


private:
	Edge *a;
	Edge *b;
	Edge *c;
	Edge *d;
	Vertex QFacePoint;
	bool edgeAReversed;
	bool edgeBReversed;
	bool edgeCReversed;
	bool edgeDReversed;

public:
	QFace();
	QFace(Edge * newA, bool revA, Edge * newB, bool revB, Edge * newC, bool revC, Edge * newD, bool revD);
	virtual ~QFace();
	Edge * getEdgeA();
	Edge * getEdgeB();
	Edge * getEdgeC();
	Edge * getEdgeD();
	Vertex calcCentroid();
	void setCentroid();
	Vertex getCentroid();
	bool getEdgeADirection();
	bool getEdgeBDirection();
	bool getEdgeCDirection();
	bool getEdgeDDirection();
	Vertex * getPointA();
	Vertex * getPointB();
	Vertex * getPointC();
	Vertex * getPointD();
};

#endif /* QFACE_H_ */
