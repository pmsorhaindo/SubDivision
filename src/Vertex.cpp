/*
 * Vertex.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "Vertex.h"

Vertex::Vertex(){

}

Vertex::Vertex(float newX, float newY, float newZ) {
	x = newX;
	y = newY;
	z = newZ;
}

Vertex::~Vertex() {
	// TODO Auto-generated destructor stub
}

float Vertex::getX(){
	return x;
}

float Vertex::getY(){
	return y;
}

float Vertex::getZ(){
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
