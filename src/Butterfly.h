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
// Name        : Butterfly.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class implements and stiches up Butterfly Subdivison. - in C++, Ansi-style
//============================================================================

#ifndef BUTTERFLY_H_
#define BUTTERFLY_H_
#include "GeometryOps.h"
#include <iostream>

class Butterfly {

private:
	Face * faceArray;
	Edge * edgeArray;
	Vertex * vertexArray;
	float rotAng;
	int sizeOfVertexArray;
	int sizeOfEdgeArray;
	int sizeOfFaceArray;

public:
	Butterfly();
	Butterfly(int v, int e, int f, Vertex *ova, Edge *oea, Face *ofa);
	virtual ~Butterfly();
	Vertex getNewEdgePoint(Edge * edgeToWork,Edge * oldEdges, int numberOfEdges, Face * oldFaces, int numberOfOldFaces);
	void draw(bool faces = true, bool lines = false, bool points = false);
	int returnSizeOfVertexArray();
	int returnSizeOfEdgeArray();
	int returnSizeOfFaceArray();
	Vertex * returnVertexArrayPtr();
	Edge * returnEdgeArrayPtr();
	Face * returnFaceArrayPtr();
};

#endif /* BUTTERFLY_H_ */
