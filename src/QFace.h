//============================================================================
// Name        : QFace.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This allows for the storage of Four sided faces. To store three sided faces
//               I use a seperate class called Face. - in C++, Ansi-style
//============================================================================

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
