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
	faceArray = new QFace[1000];
	edgeArray = new Edge[1000];
	vertexArray = new Vertex[1000];
	sizeOfFaceArray = 0;
	sizeOfEdgeArray = 0;
	sizeOfVertexArray = 0;

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

		//cout << "gonna compare centroid " << gOps.vertexToString(oldFaceArray[i].getCentroid()) <<endl;
		if (!gOps.existsInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray))
		{
		vertexArray[sizeOfVertexArray] =  oldFaceArray[i].getCentroid();
		facePointIndex = sizeOfVertexArray;
		sizeOfVertexArray++;
		}
		else
		{
			cerr << "this shouldn't happen\n";
			cout << "offending Vertex is -> " << gOps.vertexToString(oldFaceArray[i].getCentroid()) << "\n";
			facePointIndex = gOps.whereInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointA;
		edgePointA = gOps.getEdgePoint(oldFaceArray[i].getEdgeA(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		cout << "edgey A comes to the mix "<< gOps.vertexToString(oldFaceArray[i].getEdgeA()->getEdgePoint()) << endl;
		if(!gOps.existsInNewVertexArray(edgePointA,vertexArray,v))
		{
			vertexArray[sizeOfVertexArray] = edgePointA;
			edgePointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointAIndex = gOps.whereInNewVertexArray(edgePointA,vertexArray,v);
			cout << "epa in Index "<< edgePointAIndex << "\n";
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
			cout << "epb in Index "<< edgePointBIndex << "\n";
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
			cout << "epc in Index "<< edgePointCIndex << "\n";
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
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getEdgeC()->getVertexA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointCIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointCIndex = gOps.whereInNewVertexArray(newV3,vertexArray,v);
		}

		cout << "VertexArrayIndex's\n";
		cout << "edgePointAIndex "<< edgePointAIndex <<"\n";
		cout << "edgePointBIndex " << edgePointBIndex <<"\n";
		cout << "edgePointCIndex " << edgePointCIndex << "\n";
		cout << "facePointIndex " << facePointIndex << "\n";
		cout << "newVertPointAIndex " << newVertPointAIndex <<"\n";
		cout << "newVertPointBIndex " << newVertPointBIndex <<"\n";
		cout << "newVertPointCIndex " << newVertPointCIndex <<"\n";
		cout << "\n";
		//Edge newV1 ->
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointAIndex],&vertexArray[newVertPointAIndex]);
		newEdgeAIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointAIndex],&vertexArray[edgePointBIndex]);
		newEdgeBIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointBIndex],&vertexArray[facePointIndex]);
		newEdgeCIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointAIndex]);
		newEdgeDIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false,&edgeArray[newEdgeDIndex],false);
		sizeOfFaceArray++;

		//else{cout<<"caught!\n";}
	}

	cout << "sizeOfVertexArray is: " << sizeOfVertexArray <<"\n";

	cout << "\n newVertArray in Catmull\n";
	for (int j=0; j<sizeOfVertexArray; j++)
	{
		cout<< "Vertex " << j << " "<<gOps.vertexToString(vertexArray[j])<<endl;
	}

	cout << "size of EdgeArray " << sizeOfEdgeArray << "\n";

	//cout<< "sizeOfOldFaceArray " << sizeOfOldFaceArray<<endl;
	//GeometryOps::twoFace twoFaceStorage = gOps.getOtherFace(oea[2],ofa,f);
	//cout<< "edge Array test 1: " << gOps.printUniqueVertices(twoFaceStorage.faceOne) <<"\n";
	//cout<< "edge Array test 2: " << gOps.printUniqueVertices(twoFaceStorage.faceTwo) <<"\n";
	cout << "sizeOfVertexArray " << sizeOfVertexArray<<endl;
	cout << "sizeOfEdgeArray " << sizeOfEdgeArray<<endl;
	cout << "sizeOfFaceArray " << sizeOfFaceArray<<endl;
	cout <<"x: "<<faceArray[0].getEdgeA()->getVertexA()->getX();
	cout << " y: " << faceArray[0].getEdgeA()->getVertexA()->getY();
	cout << " z: " <<faceArray[0].getEdgeA()->getVertexA()->getZ()<<endl;
	//glVertex3f(faceArray[0].getEdgeB()->getVertexA()->getX(),faceArray[0].getEdgeB()->getVertexA()->getY(),faceArray[0].getEdgeB()->getVertexA()->getZ());
	//glVertex3f(faceArray[0].getEdgeC()->getVertexA()->getX(),faceArray[0].getEdgeC()->getVertexA()->getY(),faceArray[0].getEdgeC()->getVertexA()->getZ()); //
	//glVertex3f(faceArray[0].getEdgeD()->getVertexA()->getX(),faceArray[0].getEdgeD()->getVertexA()->getY(),faceArray[0].getEdgeD()->getVertexA()->getZ());
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

		for(int i=0;i<sizeOfFaceArray;i++)
		{
			glBegin(GL_QUADS);
			//OpenGL must be counter clockwise!

			/*if(i%2==1)
			{
				glColor3f(1.0f,0.0f,0.0f); //Red
			}
			else
			{
				glColor3f(0.0f,0.0f,1.0f); //Blue
			}*/
				glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ());
				glVertex3f(faceArray[i].getEdgeB()->getVertexA()->getX(),faceArray[i].getEdgeB()->getVertexA()->getY(),faceArray[i].getEdgeB()->getVertexA()->getZ());
				glVertex3f(faceArray[i].getEdgeC()->getVertexA()->getX(),faceArray[i].getEdgeC()->getVertexA()->getY(),faceArray[i].getEdgeC()->getVertexA()->getZ()); //
				glVertex3f(faceArray[i].getEdgeD()->getVertexA()->getX(),faceArray[i].getEdgeD()->getVertexA()->getY(),faceArray[i].getEdgeD()->getVertexA()->getZ());
			glEnd();
		}
	//cout << "one draw?\n";
	rotAng += 0.2;
}
