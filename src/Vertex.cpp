/*
 * Vertex.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "Vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(){
	x=0;
	y=0;
	z=0;
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

void Vertex::div(float val){
	//std::cout << "before div x was: " << x <<"\n";
	x=x/val;
	//std::cout << "after div x was: " << x <<"\n";
	//std::cout << "before div y was: " << y <<"\n";
	y=y/val;
	//std::cout << "after div y was: " << y <<"\n";
	//std::cout << "before div z was: " << z <<"\n";
	z=z/val;
	//std::cout << "after div z was: " << z <<"\n";
}

void Vertex::add(Vertex v){
	//cout << "Addition Test\n";
	//cout << "x:"<<x<<" + vx:"<<v.getX();
	x = x+v.getX();
	//cout << " = " << x<<endl;
	//cout << "y:"<<y<<" + vy:"<<v.getY();
	y = y+v.getY();
	//cout << " = " << y<<endl;
	//cout << "z:"<<z<<" + vz:"<<v.getZ();
	z = z+v.getZ();
	//cout << " = " << z<<endl;
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
