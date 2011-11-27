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

	/*if(edgeAReversed==true)
	{
		Edge * tempEdge = new Edge(a->getVertexB(),a->getVertexA());
		return tempEdge;
	} //BAD MEMORY LEAKING CODE :(*/

	return a;
}

Edge* Face::getEdgeB(){
	//cout << "getEdgeB\n";
	//cout << b << "\n";

	/*if(edgeBReversed==true)
		{
		Edge * tempEdge = new Edge(b->getVertexB(),b->getVertexA());
			return tempEdge;

		}//BAD MEMORY LEAKING CODE :(*/

	return b;
}

Edge* Face::getEdgeC(){

	/*if(edgeCReversed==true)
			{
				Edge * tempEdge = new Edge(c->getVertexB(),c->getVertexA());
				return tempEdge;
			} //BAD MEMORY LEAKING CODE :(*/

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
	//cout << "adding this " << this->getEdgeA()->getVertexA()->getX()<<"\n";
	//cout << "this "<< this->getEdgeB()->getVertexA()->getX() <<"\n";
	//cout << "and this C "<< this->getEdgeC()->getVertexA()->getX() << "\n";
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





