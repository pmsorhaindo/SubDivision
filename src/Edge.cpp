/*
 * Edge.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */
#include "Edge.h"
#include <iostream>
using namespace std;

Edge::Edge(){

}

Edge::Edge(Vertex newa, Vertex newb){
	a=newa;
	b=newb;
	calcEdgeMidPoint();
}

Edge::~Edge() {
	// TODO Auto-generated destructor stub
}

Vertex Edge::getVertexA(){
	return a;
}

Vertex Edge::getVertexB(){
	return b;
}

void Edge::setJoinsFace(Face *a, Face *b){
	joinsFace1 = a;
	joinsFace2 = b;
}

Face * Edge::getFacesJoined1(){

	Face *joinedFaces;
	joinedFaces = joinsFace1;
	return joinedFaces;
}

Face * Edge::getFacesJoined2(){

	Face *joinedFaces;
	joinedFaces = joinsFace2;
	return joinedFaces;
}

void Edge::calcEdgeMidPoint()
{
	//cout << "calc mid: axyz:"<<a.getX() <<":" << a.getY() << ":" << a.getZ()<<endl;
	//cout << "calc mid: bxyz:"<<b.getX() <<":" << b.getY() << ":" << b.getZ()<<endl;
	float tempvx = a.getX()-b.getX();
	//cout << "calc midresultx " << tempvx <<endl;
	//cout << a.getX() << "minus" <<b.getX(); // maybe brackets are needed around b.getX() like this -(b.getX());
	float tempvy = a.getY()-b.getY();
	//cout << "calc midresulty " << tempvy <<endl;
	float tempvz = a.getZ()-b.getZ();
	//cout << "calc midresultz " << tempvz <<endl;
	midPoint = Vertex(tempvx,tempvy,tempvz);
}

Vertex Edge::getEdgeMidPoint()
{
	//std::cout<<"Midpoint being retrieved is "<<midPoint.getX() <<":"<<midPoint.getY()<<":"<<midPoint.getZ()<<endl;
	return midPoint;
}

void Edge::setEdgePoint(Vertex v)
{
	edgePoint = v;
}

Vertex Edge::getEdgePoint()
{
	return edgePoint;
}


