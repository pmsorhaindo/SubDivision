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
