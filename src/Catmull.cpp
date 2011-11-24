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
	int sizeOfFaceArray;
	int sizeOfEdgeArray;
	int sizeOfVertexArray;

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

	for (int i=0; i<sizeOfFaceArray; i++)
	{
		Vertex facep;
		facep = oldFaceArray[i].getCentroid();
		vertexArray[sizeOfVertexArray] = facep;
		sizeOfVertexArray++;

		Vertex edgePointA;
		int edgePointAIndex;
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
			//gOps.whereInNewVertexArray(edgePointA,vertexArray,v)
			//edgePointAIndex = where exists vertex func pls!
		}

		Vertex newV1 = gOps.generateNewVertexPoint(oldFaceArray[i].getEdgeA()->getVertexB(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
				 if(!gOps.existsInNewVertexArray(newV1,vertexArray,v))
				 {
					 vertexArray[sizeOfVertexArray] = newV1;
					 sizeOfVertexArray++;

					 //TODO RUN A CHECK FIRSTTT!!! PLSEASE TO SAVE YOURSELF
					 // to check edge doesn't already exist.
					 int newEdgeIndex;
					 edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointAIndex],&vertexArray[sizeOfVertexArray]);
					 sizeOfEdgeArray++;
				 }
				 else
				 {
					 edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointAIndex],&vertexArray[gOps.whereInNewVertexArray(edgePointA,vertexArray,v)]);
				 }




		Vertex edgePointB;
		oldFaceArray[i].getEdgeB()->setEdgePoint(gOps.getEdgePoint(oldFaceArray[i].getEdgeB(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray));
		edgePointB = oldFaceArray[i].getEdgeB()->getEdgePoint();
		if(!gOps.existsInNewVertexArray(edgePointB,vertexArrayPtr,v))
		{
			vertexArray[sizeOfVertexArray] = edgePointB;
			sizeOfVertexArray++;
		}

		//else{cout<<"caught!\n";}
		Vertex edgePointC;
		oldFaceArray[i].getEdgeC()->setEdgePoint(gOps.getEdgePoint(oldFaceArray[i].getEdgeC(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray));
		edgePointC = faceArrayPtr[i].getEdgeC()->getEdgePoint();
		//edgePointC = gOps.getEdgePoint(faceArrayPtr[i].getEdgeC(),faceArrayPtr,sizeOfFaceArray);
		if(!gOps.existsInNewVertexArray(edgePointC,vertexArrayPtr,v))
		{
			vertexArray[sizeOfVertexArray] = edgePointC;
			sizeOfVertexArray++;
		}
		 Vertex newV2 = gOps.generateNewVertexPoint(oldFaceArray[i].getEdgeA()->getVertexA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		 if(!gOps.existsInNewVertexArray(newV2,vertexArrayPtr,v))
		 {
			 vertexArray[sizeOfVertexArray] = newV2;
			 sizeOfVertexArray++;
		 }

		 Vertex newV3 = gOps.generateNewVertexPoint(oldFaceArray[i].getEdgeB()->getVertexA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		 if(!gOps.existsInNewVertexArray(newV3,vertexArrayPtr,50))
		 {
			 vertexArray[sizeOfVertexArray] = newV3;
			 sizeOfVertexArray++;
		 }
		 //else{cout<<"caught!\n";}
	}

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
