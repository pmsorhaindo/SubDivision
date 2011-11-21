/*
 * Face.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "Face.h"
#include <iostream>

using namespace std;

Face::Face(){

}

Face::Face(Edge * newa, Edge * newb, Edge * newc){
	//cout << "inside Face\n";
	a=newa;
	//cout << "first Edge in face\n";
	b=newb;
	c=newc;
	//cout <<"All edges set in Face\n";
	setCentroid();
	//cout << "centroid set\n";
}

Face::Face(Edge * newa, bool revAval, Edge * newb, bool revBval, Edge * newc, bool revCval){
	//cout << "inside Face\n";
	a=newa;
	edgeAReversed = revAval;
	//cout << "first Edge in face\n";
	b=newb;
	edgeBReversed = revBval;
	c=newc;
	edgeCReversed = revCval;
	//cout <<"All edges set in Face\n";
	setCentroid();
	//cout << "centroid set\n";
}


Face::~Face() {
	// TODO Auto-generated destructor stub
}

Edge* Face::getEdgeA(){
	//cout << "getEdgeA\n";
	//cout << a <<"\n";
	return a;
}

Edge* Face::getEdgeB(){
	//cout << "getEdgeB\n";
	//cout << b << "\n";
	return b;
}

Edge* Face::getEdgeC(){
	return c;
}

Vertex Face::calcCentroid(){
	Vertex v;
	float x=((this->a->getVertexA()->getX()+this->a->getVertexA()->getY()+this->a->getVertexA()->getZ())/3.0f);
	float y=((this->a->getVertexB()->getX()+this->a->getVertexB()->getY()+this->a->getVertexB()->getZ())/3.0f);
	float z=((this->b->getVertexA()->getX()+this->b->getVertexA()->getY()+this->b->getVertexA()->getZ())/3.0f);
	v = Vertex(x,y,z);
	//std::cout <<"Facepoint aax: "<< this->a.getVertexA().getX() << " aay: " << this->a.getVertexA().getY() << " aaz: " << this->a.getVertexA().getZ()<<endl;
	//std::cout <<"Facepoint abx: "<< this->a.getVertexB().getX() << " aby: " << this->a.getVertexB().getY() << " abz: " << this->a.getVertexB().getZ()<<endl;
	//std::cout <<"Facepoint bbx: "<< this->c.getVertexA().getX() << " bby: " << this->c.getVertexA().getY() << " bbz: " << this->c.getVertexA().getZ()<<endl;
	return v;
}

void Face::setCentroid(){
	//cout << "in setCentroid\n";
	//cout << "adding this" << this->getEdgeA()->getVertexA()->getX()<<"\n";
	//cout << "this "<< this->getEdgeA()->getVertexB()->getX() <<"\n";
	//cout << "oh noes\n";
	//cout << "and this C "<< this->getEdgeC()->getVertexB()->getX() << "\n";
	float a1 = this->getEdgeA()->getVertexA()->getX()+this->getEdgeA()->getVertexB()->getX()+this->getEdgeB()->getVertexB()->getX();
	float b1 = this->getEdgeA()->getVertexA()->getY()+this->getEdgeA()->getVertexB()->getY()+this->getEdgeB()->getVertexB()->getY();
	float c1 = this->getEdgeA()->getVertexA()->getZ()+this->getEdgeA()->getVertexB()->getZ()+this->getEdgeB()->getVertexB()->getZ();
	facePoint = Vertex((a1/3),(b1/3),(c1/3));
}

Vertex Face::getCentroid(){
	return facePoint;
}



