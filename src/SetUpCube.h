/*
 * SetUpCube.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

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
	void draw();
	Vertex * returnVertexArrayPtr();
	Edge * returnEdgeArrayPtr();
	Face * returnFaceArrayPtr();
	int returnSizeOfVertexArray();
	int returnSizeOfEdgeArray();
	int returnSizeOfFaceArray();
};

#endif /* SETUPCUBE_H_ */
