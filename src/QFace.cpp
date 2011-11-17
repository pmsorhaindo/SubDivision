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

QFace::QFace(Edge newa, Edge newb, Edge newc, Edge newd){
	a=newa;
	b=newb;
	c=newc;
	d=newd;
	setCentroid();
}

QFace::~QFace() {
	// TODO Auto-generated destructor stub
}

Edge QFace::getEdgeA(){
	return a;
}

Edge QFace::getEdgeB(){
	return b;
}

Edge QFace::getEdgeC(){
	return c;
}

Edge QFace::getEdgeD(){
	return d;
}

Vertex QFace::calcCentroid(){
	Vertex v;
	float x=((this->a.getVertexA().getX()+this->a.getVertexA().getY()+this->a.getVertexA().getZ())/3.0f);
	float y=((this->a.getVertexB().getX()+this->a.getVertexB().getY()+this->a.getVertexB().getZ())/3.0f);
	float z=((this->b.getVertexA().getX()+this->b.getVertexA().getY()+this->b.getVertexA().getZ())/3.0f);
	v = Vertex(x,y,z);
	//std::cout <<"QFacepoint aax: "<< this->a.getVertexA().getX() << " aay: " << this->a.getVertexA().getY() << " aaz: " << this->a.getVertexA().getZ()<<endl;
	//std::cout <<"QFacepoint abx: "<< this->a.getVertexB().getX() << " aby: " << this->a.getVertexB().getY() << " abz: " << this->a.getVertexB().getZ()<<endl;
	//std::cout <<"QFacepoint bbx: "<< this->c.getVertexA().getX() << " bby: " << this->c.getVertexA().getY() << " bbz: " << this->c.getVertexA().getZ()<<endl;
	return v;
}

void QFace::setCentroid(){
	float a1 = this->getEdgeA().getVertexA().getX()+this->getEdgeA().getVertexB().getX()+this->getEdgeB().getVertexB().getX();
	float b1 = this->getEdgeA().getVertexA().getY()+this->getEdgeA().getVertexB().getY()+this->getEdgeB().getVertexB().getY();
	float c1 = this->getEdgeA().getVertexA().getZ()+this->getEdgeA().getVertexB().getZ()+this->getEdgeB().getVertexB().getZ();
	QFacePoint = Vertex((a1/3),(b1/3),(c1/3));
}

Vertex QFace::getCentroid(){
	return QFacePoint;
}



