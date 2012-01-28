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
// Name        : SetUpCube.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : Generates and draws a basic unit cube centered over the
//               origin (0,0,0). - in C++, Ansi-style
//============================================================================

#ifndef SETUPCUBE_H_
#define SETUPCUBE_H_
#include "Face.h"
#include "GeometryOps.h"

class SetUpCube {

private:
	Vertex v1,v2,v3,v4,v5,v6,v7,v8;
	Edge a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s;
	Face one,two,three,four,five,six,seven,eight,nine,ten,eleven,twelve;
	Face faceArray[12];
	Edge edgeArray[18];
	Vertex vertexArray[8];
	float rotAng;
	Vertex * vertexArrayPtr;
	Face * faceArrayPtr;
	Edge * edgeArrayPtr;
	int sizeOfEdgeArray;
	int sizeOfVertexArray;
	int sizeOfFaceArray;

public:
	SetUpCube();
	virtual ~SetUpCube();
	Face * getFaceArray();
	Edge * getEdgeArray();
	Vertex * getVertexArray();
	void draw(bool faces, bool lines, bool points);
	Vertex * returnVertexArrayPtr();
	Edge * returnEdgeArrayPtr();
	Face * returnFaceArrayPtr();
	int returnSizeOfVertexArray();
	int returnSizeOfEdgeArray();
	int returnSizeOfFaceArray();
};

#endif /* SETUPCUBE_H_ */
