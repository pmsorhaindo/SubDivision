//============================================================================
// Name        : Edge.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This allows for the storage of Edges. These are comprised of two Vertex's
//               a start point A, and an end point B. - in C++, Ansi-style
//============================================================================

#ifndef EDGE_H_
#define EDGE_H_
#include "Vertex.h"

class Face;
class Edge {

private:
	Vertex * a;
	Vertex * b;
	Face * joinsFace1;
	Face * joinsFace2;
	Vertex midPoint;
	Vertex edgePoint;
	bool reversed;

public:
	Edge();
	Edge(Vertex * newa, Vertex * newb);
	virtual ~Edge();
	Vertex * getVertexA();
	Vertex * getVertexB();
	void setJoinsFace(Face *a, Face *b);
	Face * getFacesJoined1();
	Face * getFacesJoined2();
	void calcEdgeMidPoint();
	Vertex getEdgeMidPoint();
	void setEdgePoint (Vertex v);
	Vertex getEdgePoint();

};

#endif /* EDGE_H_ */
