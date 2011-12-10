/*
 * Catmull.h
 *
 *  Created on: 9 Nov 2011
 *      Author: mikey
 */

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
	void draw();
	int returnSizeOfVertexArray();
	int returnSizeOfEdgeArray();
	int returnSizeOfFaceArray();
	Vertex * returnVertexArrayPtr();
	Edge * returnEdgeArrayPtr();
	QFace * returnFaceArrayPtr();
};

#endif /* CATMULL_H_ */
