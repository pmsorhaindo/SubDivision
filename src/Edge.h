/*
Copyright (C) <2012> <Paul-Michael Sorhaindo>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
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
