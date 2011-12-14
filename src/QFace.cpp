//============================================================================
// Name        : QFace.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This allows for the storage of Four sided faces. To store three sided faces
//               I use a seperate class called Face. - in C++, Ansi-style
//============================================================================


#include "QFace.h"
#include <iostream>

using namespace std;

QFace::QFace(){

}

/*
 * Creates a new QFace from the Edges provided the boolean values allow Edges to be reversed.
 */
QFace::QFace(Edge * newa, bool revAval, Edge * newb, bool revBval, Edge * newc, bool revCval, Edge * newd,  bool revDval){
	a=newa;
	b=newb;
	c=newc;
	d=newd;
	edgeAReversed=revAval;
	edgeBReversed=revBval;
	edgeCReversed=revCval;
	edgeDReversed=revDval;
	setCentroid();
}

QFace::~QFace() {
	// Destructor
}

Edge * QFace::getEdgeA(){
	return a;
}

Edge * QFace::getEdgeB(){
	return b;
}

Edge * QFace::getEdgeC(){
	return c;
}

Edge * QFace::getEdgeD(){
	return d;
}

/*
 * This calculates the Centroid (the Vertex Average of all points on a face) this is called on QFace creation.
 * The value is stored in the QFaces private variable QFacePoint.
 */
void QFace::setCentroid(){
	float a1 = this->getEdgeA()->getVertexA()->getX()+this->getEdgeB()->getVertexA()->getX()+this->getEdgeC()->getVertexA()->getX()+this->getEdgeD()->getVertexA()->getX();
	float b1 = this->getEdgeA()->getVertexA()->getY()+this->getEdgeB()->getVertexA()->getY()+this->getEdgeC()->getVertexA()->getY()+this->getEdgeD()->getVertexA()->getY();
	float c1 = this->getEdgeA()->getVertexA()->getZ()+this->getEdgeB()->getVertexA()->getZ()+this->getEdgeC()->getVertexA()->getZ()+this->getEdgeD()->getVertexA()->getZ();
	QFacePoint = Vertex((a1/4),(b1/4),(c1/4));
}

Vertex QFace::getCentroid(){
	return QFacePoint;
}

bool QFace::getEdgeADirection(){
	return edgeAReversed;
}

bool QFace::getEdgeBDirection(){
	return edgeBReversed;
}

bool QFace::getEdgeCDirection(){
	return edgeCReversed;
}

bool QFace::getEdgeDDirection(){
	return edgeCReversed;
}


/*
 * Get Point allows unique vertices to still be retrieved from faces in a
 * A, B, C, D manner without worrying about reversed Edges. It returns the first
 * point in the Edge which is unique unless the edge has been reversed, these
 * methods detect this and return the second point if reversing has occurred
 */
Vertex * QFace::getPointA()
{
	if(!edgeAReversed)
	{
		return this->a->getVertexA();
	}
	return this->a->getVertexB();
}

Vertex * QFace::getPointB()
{
	if(!edgeBReversed)
		{
			return this->b->getVertexA();
		}
		return this->b->getVertexB();
}

Vertex * QFace::getPointC()
{
	if(!edgeCReversed)
			{
				return this->c->getVertexA();
			}
			return this->c->getVertexB();
}

Vertex * QFace::getPointD()
{
	if(!edgeDReversed)
			{
				return this->d->getVertexA();
			}
			return this->d->getVertexB();
}




