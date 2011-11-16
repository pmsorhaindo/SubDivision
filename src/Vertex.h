/*
 * Vertex.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

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
	float getX();
	float getY();
	float getZ();
	void setX(float f);
	void setY(float f);
	void setZ(float f);
	Vertex operator+(const Vertex &a) const;
	Vertex operator-(const Vertex &a) const;
	Vertex operator*(const Vertex &a) const;
	Vertex operator*(const float &a) const;
	Vertex operator*(const int &a) const;
	Vertex operator/(const float &a) const;
};



#endif /* VERTEX_H_ */
