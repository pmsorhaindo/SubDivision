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
	Edge a;
	Edge b;
	Edge c;
	Vertex facePoint;

public:
	Face();
	Face(Edge newA, Edge newB, Edge newC);
	virtual ~Face();
	Edge getEdgeA();
	Edge getEdgeB();
	Edge getEdgeC();
	Vertex calcCentroid();
	void setCentroid();
	Vertex getCentroid();
};

#endif /* FACE_H_ */
