//============================================================================
// Name        : Vertex.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class holds information relevant for to a specific Vertex. - in C++, Ansi-style
//============================================================================
#include "Vertex.h"
#include <iostream>

using namespace std;

/*
 * Creates a new Vertex at the origin (0,0,0)
 */
Vertex::Vertex(){
	x=0;
	y=0;
	z=0;
}

/*
 * Creates a new Vertex with the given x, y and z values.
 */
Vertex::Vertex(float newX, float newY, float newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}

float Vertex::getX() const{
	return x;
}

float Vertex::getY() const{
	return y;
}

float Vertex::getZ() const{
	return z;
}

void Vertex::setX(float val){
	x=val;
}
void Vertex::setY(float val){
	y=val;
}
void Vertex::setZ(float val){
	z=val;
}

void Vertex::div(float val){
	x=x/val;
	y=y/val;
	z=z/val;
}

void Vertex::add(Vertex v){
	x = x+v.getX();
	y = y+v.getY();
	z = z+v.getZ();
}

// Overloading the operators  + - * and / for Vertices for ease of writing code.
// Syntax assistance provided by http://www.cplusplus.com/doc/tutorial/classes2/
Vertex Vertex::operator+(const Vertex &a) const
{
	return Vertex(x+a.x,y+a.y,z+a.z);
}

Vertex Vertex::operator-(const Vertex &a) const
{
	return Vertex(x-a.x,y-a.y,z-a.z);
}

Vertex Vertex::operator*(const Vertex &a) const
{
	return Vertex(x*a.x,y*a.y,z*a.z);
}

Vertex Vertex::operator*(const float &a) const
{
	return Vertex(x*a,y*a,z*a);
}

Vertex Vertex::operator*(const int &a) const
{
	return Vertex(x*(float)a,y*(float)a,z*(float)a);
}

Vertex Vertex::operator/(const float &a) const
{
	return Vertex(x/a,y/a,z/a);
}
