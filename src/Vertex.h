/*
Copyright (C) <2012> <Paul-Michael Sorhaindo>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//============================================================================
// Name        : Vertex.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class holds information relevant for to a specific Vertex. - in C++, Ansi-style
//============================================================================

#ifndef VERTEX_H_
#define VERTEX_H_

class Edge;
class Vertex {

private:
	float x;
	float y;
	float z;
	float valance;

public:
	Vertex();
	Vertex(float newX, float newY, float newZ);
	virtual ~Vertex();
	float getX() const;
	float getY() const;
	float getZ() const;
	void setX(float f);
	void setY(float f);
	void setZ(float f);
	void div(float f);
	void add(Vertex v);
	Vertex operator+(const Vertex &a) const;
	Vertex operator-(const Vertex &a) const;
	Vertex operator*(const Vertex &a) const;
	Vertex operator*(const float &a) const;
	Vertex operator*(const int &a) const;
	Vertex operator/(const float &a) const;
};



#endif /* VERTEX_H_ */
