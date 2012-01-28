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
// Name        : Face.h
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
