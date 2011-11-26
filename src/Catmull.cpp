/*
 * Catmull.cpp
 *
 *  Created on: 9 Nov 2011
 *      Author: mikey
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Catmull.h"

using namespace std;
Catmull::Catmull() {
	// TODO Auto-generated constructor stub

}

Catmull::Catmull(int v, int e, int f, Vertex *ova, Edge *oea, Face *ofa){
	//TODO split setUpCube!
	QFace faceArray[(f*3)];
	Edge edgeArray[e*3];
	Vertex vertexArray[v*3];
	int sizeOfFaceArray = 0;
	int sizeOfEdgeArray = 0;
	int sizeOfVertexArray = 0;

	Vertex * oldVertexArray = ova;
	Edge * oldEdgeArray = oea;
	Face * oldFaceArray = ofa;
	int sizeOfOldVertexArray = v;
	int sizeOfOldEdgeArray = e;
	int sizeOfOldFaceArray = f;

	GeometryOps gOps = GeometryOps();

	//assign pointers to arrays
	//Vertex * vertexArrayPtr;
	vertexArrayPtr = vertexArray;
	//Face * faceArrayPtr;
	faceArrayPtr = faceArray;
	//Edge * edgeArrayPtr;
	edgeArrayPtr = edgeArray;
	rotAng = 0.0f;

	for (int i=0; i<sizeOfOldFaceArray; i++)
	{
		Vertex facep;
		int facePointIndex;
		int newEdgeAIndex, newEdgeBIndex, newEdgeCIndex, newEdgeDIndex;
		int edgePointAIndex,edgePointBIndex,edgePointCIndex;
		int newVertPointAIndex, newVertPointBIndex, newVertPointCIndex;

		if (gOps.existsInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray))
		{
		vertexArray[sizeOfVertexArray] = facep;
		sizeOfVertexArray++;
		}
		else
		{
			cerr << "this shouldn't happen\n";
			cout << "offending Vertex is -> " << gOps.vertexToString(oldFaceArray[i].getCentroid()) << "\n";
			facePointIndex = gOps.whereInNewVertexArray(facep,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointA;
		edgePointA = oldFaceArray[i].getEdgeA()->getEdgePoint();
		edgePointA = gOps.getEdgePoint(oldFaceArray[i].getEdgeA(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointA,vertexArray,v))
		{
			vertexArray[sizeOfVertexArray] = edgePointA;
			edgePointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointAIndex = gOps.whereInNewVertexArray(edgePointA,vertexArray,v);
		}

		Vertex edgePointB;
		edgePointB = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointB = gOps.getEdgePoint(oldFaceArray[i].getEdgeB(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointB,vertexArray,v))
		{
			vertexArray[sizeOfVertexArray] = edgePointB;
			edgePointBIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointBIndex = gOps.whereInNewVertexArray(edgePointB,vertexArray,v);
		}

		Vertex edgePointC;
		edgePointC = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointC = gOps.getEdgePoint(oldFaceArray[i].getEdgeC(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointC,vertexArray,v))
		{
			vertexArray[sizeOfVertexArray] = edgePointC;
			edgePointCIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointCIndex = gOps.whereInNewVertexArray(edgePointC,vertexArray,v);
		}



		Vertex newV1 = gOps.generateNewVertexPoint(oldFaceArray[i].getEdgeA()->getVertexA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV1,vertexArray,v))
		{
			vertexArray[sizeOfVertexArray] = newV1;
			newVertPointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointAIndex = gOps.whereInNewVertexArray(newV1,vertexArray,v);
		}

		Vertex newV2 = gOps.generateNewVertexPoint(oldFaceArray[i].getEdgeB()->getVertexA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV2,vertexArray,v))
		{
			vertexArray[sizeOfVertexArray] = newV2;
			newVertPointBIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointBIndex = gOps.whereInNewVertexArray(newV2,vertexArray,v);
		}

		Vertex newV3 = gOps.generateNewVertexPoint(oldFaceArray[i].getEdgeC()->getVertexA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV3,vertexArray,v))
		{
			vertexArray[sizeOfVertexArray] = newV3;
			newVertPointCIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointCIndex = gOps.whereInNewVertexArray(newV3,vertexArray,v);
		}

		//Edge newV1 ->
		//edgeArray[sizeOfEdgeArray] = Edge()
		//faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false,&edgeArray[newEdgeDIndex],false);
		 //else{cout<<"caught!\n";}
	}

	cout << "sizeOfVertexArray is: " << sizeOfVertexArray <<"\n";

}

Catmull::~Catmull() {
	// TODO Auto-generated destructor stub
}

void Catmull::draw(){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
		// Reset The Current Modelview Matrix
		glLoadIdentity();
		// put the thing somewhere between the near and far clipping panes
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(rotAng,0.0f,0.5f,1.0);

		for(int i=0;i<12;i++)
		{
			glBegin(GL_QUADS);
			//OpenGL must be counter clockwise!

			if(i%2==1)
			{
				glColor3f(1.0f,0.0f,0.0f); //Red
			}
			else
			{
				glColor3f(0.0f,0.0f,1.0f); //Blue
			}
				//glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ());
				//glVertex3f(faceArray[i].getEdgeB()->getVertexA()->getX(),faceArray[i].getEdgeB()->getVertexA()->getY(),faceArray[i].getEdgeB()->getVertexA()->getZ());
				//glVertex3f(faceArray[i].getEdgeC()->getVertexA()->getX(),faceArray[i].getEdgeC()->getVertexA()->getY(),faceArray[i].getEdgeC()->getVertexA()->getZ()); //
				//glVertex3f(faceArray[i].getEdgeD()->getVertexA()->getX(),faceArray[i].getEdgeD()->getVertexA()->getY(),faceArray[i].getEdgeD()->getVertexA()->getZ());
			glEnd();
		}
	//cout << "one draw?\n";
	rotAng += 0.2;
}
