/*
 * QFace.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "QFace.h"
#include <iostream>

using namespace std;

QFace::QFace(){

}

QFace::QFace(Edge *newa, bool revAval, Edge * newb, bool revBval, Edge * newc, bool revCval, Edge * newd,  bool revDval){
	a=newa;
	b=newb;
	c=newc;
	d=newd;
	edgeAReversed=revAval;
	edgeBReversed=revBval;
	edgeCReversed=revCval;
	edgeDReversed=revDval;
	//setCentroid();
}

QFace::~QFace() {
	// TODO Auto-generated destructor stub
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

Vertex QFace::calcCentroid(){
	Vertex v;

	float x=((this->a->getVertexA()->getX()+this->a->getVertexA()->getY()+this->a->getVertexA()->getZ())/3.0f);
	float y=((this->a->getVertexB()->getX()+this->a->getVertexB()->getY()+this->a->getVertexB()->getZ())/3.0f);
	float z=((this->b->getVertexA()->getX()+this->b->getVertexA()->getY()+this->b->getVertexA()->getZ())/3.0f);

	v = Vertex(x,y,z);
	return v;
}

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




