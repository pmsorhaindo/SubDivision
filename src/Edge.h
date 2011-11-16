/*
 * Edge.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#ifndef EDGE_H_
#define EDGE_H_
#include "Vertex.h"

class Face;
class Edge {

private:
	Vertex a;
	Vertex b;
	Face * joinsFace1;
	Face * joinsFace2;
	Vertex midPoint;

public:
	Edge();
	Edge(Vertex newa, Vertex newb);
	virtual ~Edge();
	Vertex getVertexA();
	Vertex getVertexB();
	void setJoinsFace(Face *a, Face *b);
	Face * getFacesJoined1();
	Face * getFacesJoined2();
	void calcEdgeMidPoint();
	Vertex getEdgeMidPoint();

};

#endif /* EDGE_H_ */
