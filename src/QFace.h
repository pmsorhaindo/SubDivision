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
	Edge a;
	Edge b;
	Edge c;
	Edge d;
	Vertex QFacePoint;

public:
	QFace();
	QFace(Edge newA, Edge newB, Edge newC, Edge newD);
	virtual ~QFace();
	Edge getEdgeA();
	Edge getEdgeB();
	Edge getEdgeC();
	Edge getEdgeD();
	Vertex calcCentroid();
	void setCentroid();
	Vertex getCentroid();
};

#endif /* QFACE_H_ */
