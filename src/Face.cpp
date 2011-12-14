//============================================================================
// Name        : Face.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This allows for the storage of Triangular faces. To store four sided faces
//               I use a seperate class called QFace. - in C++, Ansi-style
//============================================================================

#include "Face.h"
#include <iostream>

using namespace std;

Face::Face(){

}

/*
 * Creates a new Face ignoring direction of edges.
 */
Face::Face(Edge * newa, Edge * newb, Edge * newc){
	a=newa;
	b=newb;
	c=newc;
	setCentroid();
}

/*
 * Creates a new Face allowing for the reversing of Edges.
 */
Face::Face(Edge * newa, bool revAval, Edge * newb, bool revBval, Edge * newc, bool revCval){
	a=newa;
	edgeAReversed = revAval;
	b=newb;
	edgeBReversed = revBval;
	c=newc;
	edgeCReversed = revCval;
	setCentroid();
}


Face::~Face() {
	// TODO Auto-generated destructor stub
}

/*
 * This function returns an Edge, pretty simple but at one point all three getEdges contained
 * code currently commented out here to 'unreverse' the edges if they had been reversed for
 * the purpose of drawing anti-clockwise triangles easily. This resulted in a memory leak.
 */
Edge* Face::getEdgeA(){
	/*if(edgeAReversed==true)
	{
		Edge * tempEdge = new Edge(a->getVertexB(),a->getVertexA());
		return tempEdge;
	} //BAD MEMORY LEAKING CODE :(*/
	return a;
}

Edge* Face::getEdgeB(){
	return b;
}

Edge* Face::getEdgeC(){
	return c;
}

/*
 * This calculates the Centroid (the Vertex Average of all points on a face) this is called on Face creation.
 * The value is stored in the Faces private variable facePoint.
 */
void Face::setCentroid(){

	float ax,ay,az,bx,by,bz,cx,cy,cz;
	if (!this->getEdgeADirection())
	{
		ax = this->getEdgeA()->getVertexA()->getX();
		ay = this->getEdgeA()->getVertexA()->getY();
		az = this->getEdgeA()->getVertexA()->getZ();
	}
	else
	{
		ax = this->getEdgeA()->getVertexB()->getX();
		ay = this->getEdgeA()->getVertexB()->getY();
		az = this->getEdgeA()->getVertexB()->getZ();
	}

	if (!this->getEdgeBDirection())
	{
		bx = this->getEdgeB()->getVertexA()->getX();
		by = this->getEdgeB()->getVertexA()->getY();
		bz = this->getEdgeB()->getVertexA()->getZ();
	}
	else
	{
		bx = this->getEdgeB()->getVertexB()->getX();
		by = this->getEdgeB()->getVertexB()->getY();
		bz = this->getEdgeB()->getVertexB()->getZ();
	}

	if (!this->getEdgeCDirection())
	{
		cx = this->getEdgeC()->getVertexA()->getX();
		cy = this->getEdgeC()->getVertexA()->getY();
		cz = this->getEdgeC()->getVertexA()->getZ();
	}
	else
	{
		cx = this->getEdgeC()->getVertexB()->getX();
		cy = this->getEdgeC()->getVertexB()->getY();
		cz = this->getEdgeC()->getVertexB()->getZ();
	}

	float a1 = ax+bx+cx;
	float b1 = ay+by+cy;
	float c1 = az+bz+cz;
	facePoint = Vertex((a1/3),(b1/3),(c1/3));
}

Vertex Face::getCentroid(){
	return facePoint;
}

bool Face::getEdgeADirection(){
	return edgeAReversed;
}

bool Face::getEdgeBDirection(){
	return edgeBReversed;
}

bool Face::getEdgeCDirection(){
	return edgeCReversed;
}

/*
 * Get Point allows unique vertices to still be retrieved from faces in a
 * A, B, C manner without worrying about reversed Edges. It returns the first
 * point in the Edge which is unique unless the edge has been reversed, these
 * methods detect this and return the second point if reversing has occurred
 */

Vertex * Face::getPointA()
{
	if(!edgeAReversed)
	{
		return this->a->getVertexA();
	}
	return this->a->getVertexB();
}

Vertex * Face::getPointB()
{
	if(!edgeBReversed)
		{
			return this->b->getVertexA();
		}
		return this->b->getVertexB();
}

Vertex * Face::getPointC()
{
	if(!edgeCReversed)
			{
				return this->c->getVertexA();
			}
			return this->c->getVertexB();
}





