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
