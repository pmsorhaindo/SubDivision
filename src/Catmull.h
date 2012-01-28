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
// Name        : Catmull.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class implements and stiches up Catmull-Clark Subdivison. - in C++, Ansi-style
//============================================================================

#ifndef CATMULL_H_
#define CATMULL_H_
#include "Face.h"
#include "GeometryOps.h"
class Catmull {
//Take a Face-Edge-Vertex data structure and Subdivide
private:
	Vertex * vertexArrayPtr;
	Edge * edgeArrayPtr;
	QFace * faceArrayPtr;

	QFace * faceArray;
	Edge * edgeArray;
	Vertex * vertexArray;

	int sizeOfFaceArray;
	int sizeOfEdgeArray;
	int sizeOfVertexArray;
	float rotAng;

public:
	Catmull();
	Catmull(int passedVertices, int passedEdges, int passedFaces, Vertex *ova, Edge *oea, Face *ofa);
	Catmull(Vertex * vArray, Edge * eArray, Face * fArray);
	Catmull(int passedVertices, int passedEdges, int passedFaces, Vertex *ova, Edge *oea, QFace *ofa);
	virtual ~Catmull();
	void draw(bool faces, bool lines, bool points);
	int returnSizeOfVertexArray();
	int returnSizeOfEdgeArray();
	int returnSizeOfFaceArray();
	Vertex * returnVertexArrayPtr();
	Edge * returnEdgeArrayPtr();
	QFace * returnFaceArrayPtr();
};

#endif /* CATMULL_H_ */
