//============================================================================
// Name        : Catmull.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class implements and stiches up Catmull-Clark Subdivison. - in C++, Ansi-style
//============================================================================

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Catmull.h"

using namespace std;
Catmull::Catmull() {

}

/*
 * This constructor applies subdivision to a Shape made up of triangular faces.
 * these faces are to be stored in the Face Edge Vertex Format specified in the
 * Face Edge and Vertex Classes.
 */
Catmull::Catmull(int v, int e, int f, Vertex *ova, Edge *oea, Face *ofa){
	//TODO split The Stich up Process
	faceArray = new QFace[f*3];
	edgeArray = new Edge[e*8];
	vertexArray = new Vertex[v*6];
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

	//Assign Pointers to my Arrays
	vertexArrayPtr = vertexArray;
	faceArrayPtr = faceArray;
	edgeArrayPtr = edgeArray;
	rotAng = 0.0f;

	for (int i=0; i<sizeOfOldFaceArray; i++)
	{
		Vertex facep;
		int facePointIndex;
		int newEdgeAIndex,newEdgeBIndex,newEdgeCIndex,newEdgeDIndex,newEdgeEIndex,newEdgeFIndex,newEdgeGIndex,newEdgeHIndex,newEdgeIIndex,newEdgeJIndex,newEdgeKIndex,newEdgeLIndex;
		int edgePointAIndex,edgePointBIndex,edgePointCIndex;
		int newVertPointAIndex, newVertPointBIndex, newVertPointCIndex;

		//cout << "gonna compare centroid " << gOps.vertexToString(oldFaceArray[i].getCentroid()) <<endl;
		if (!gOps.existsInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << " this is unique? " << gOps.vertexToString(oldFaceArray[i].getCentroid()) <<"\n";
			vertexArray[sizeOfVertexArray] =  oldFaceArray[i].getCentroid();
			facePointIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			//Face points should be added more than once.
			cerr << "this shouldn't happen\n";
			facePointIndex = gOps.whereInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray);
		}

		/*
		 * Generating each Edge point on the face for Edges A,B and C. Adding it if it doesn't exist in the Face Array
		 * and assigning the index in the array to a variable.
		 */
		Vertex edgePointA;
		edgePointA = gOps.getEdgePoint(oldFaceArray[i].getEdgeA(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = edgePointA;
			edgePointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointAIndex = gOps.whereInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointB;
		edgePointB = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointB = gOps.getEdgePoint(oldFaceArray[i].getEdgeB(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = edgePointB;
			edgePointBIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointBIndex = gOps.whereInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointC;
		edgePointC = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointC = gOps.getEdgePoint(oldFaceArray[i].getEdgeC(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = edgePointC;
			edgePointCIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointCIndex = gOps.whereInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray);
		}

		/*
		 * Generating each new Catmull-Clark Vertex point on the face for Points A,B and C.
		 * Adding it if it doesn't exist in the Face Array and assigning the index
		 * in the array to a variable.
		 */
		Vertex newV1 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV1,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointAIndex = gOps.whereInNewVertexArray(newV1,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex newV2 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointB(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV2,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointB(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointBIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointBIndex = gOps.whereInNewVertexArray(newV2,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex newV3 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointC(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV3,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointC(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointCIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointCIndex = gOps.whereInNewVertexArray(newV3,vertexArrayPtr,sizeOfVertexArray);
		}


		//Stitching up Process
		/*
		 * The First Face Generated from the old face starting from the NewVertex point and working around anti-clockwise
		 * to the edgePoint then face point to the the second Edge point concluding at the Vertex point.
		 */
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointAIndex],&vertexArray[edgePointCIndex]);
		newEdgeAIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointCIndex],&vertexArray[facePointIndex]);
		newEdgeBIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointAIndex]);
		newEdgeCIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointAIndex],&vertexArray[newVertPointAIndex]);
		newEdgeDIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false,&edgeArray[newEdgeDIndex],false);
		sizeOfFaceArray++;


		// Stitching up second Face
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointBIndex],&vertexArray[edgePointAIndex]);
		newEdgeEIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointAIndex],&vertexArray[facePointIndex]);
		newEdgeFIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointBIndex]);
		newEdgeGIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointBIndex],&vertexArray[newVertPointBIndex]);
		newEdgeHIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeEIndex],false,&edgeArray[newEdgeFIndex],false,&edgeArray[newEdgeGIndex],false,&edgeArray[newEdgeHIndex],false);
		sizeOfFaceArray++;

		//Stitching up Thrid Face - this is the final face when generating Catmull clark Faces from a Triangular face.
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointCIndex],&vertexArray[edgePointBIndex]);
		newEdgeIIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointBIndex],&vertexArray[facePointIndex]);
		newEdgeJIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointCIndex]);
		newEdgeKIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointCIndex],&vertexArray[newVertPointCIndex]);
		newEdgeLIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeIIndex],false,&edgeArray[newEdgeJIndex],false,&edgeArray[newEdgeKIndex],false,&edgeArray[newEdgeLIndex],false);
		sizeOfFaceArray++;

		//else{cout<<"caught!\n";}
	}

	cout << "sizeOfVertexArray " << sizeOfVertexArray<<endl;
	cout << "sizeOfEdgeArray " << sizeOfEdgeArray<<endl;
	cout << "sizeOfFaceArray " << sizeOfFaceArray<<endl;

	cout << "\n newVertArray in Catmull\n";
	for (int j=0; j<sizeOfVertexArray; j++)
	{
		cout<< "Vertex " << j << " "<<gOps.vertexToString(vertexArray[j])<<endl;
	}
}

/*
 * Overloaded
 * This constructor applies subdivision to a Shape made up of Quadrilateral faces.
 * These faces are to be stored in the QFace Edge Vertex Format specified in the
 * QFace Edge and Vertex Classes.
 */
Catmull::Catmull(int v, int e, int f, Vertex *ova, Edge *oea, QFace *ofa){

	faceArray = new QFace[f*4];
	edgeArray = new Edge[e*8];
	vertexArray = new Vertex[v*6];
	sizeOfFaceArray = 0;
	sizeOfEdgeArray = 0;
	sizeOfVertexArray = 0;

	Vertex * oldVertexArray = ova;
	Edge * oldEdgeArray = oea;
	QFace * oldFaceArray = ofa;
	int sizeOfOldVertexArray = v;
	int sizeOfOldEdgeArray = e;
	int sizeOfOldFaceArray = f;

	GeometryOps gOps = GeometryOps();

	vertexArrayPtr = vertexArray;
	faceArrayPtr = faceArray;
	edgeArrayPtr = edgeArray;
	rotAng = 0.0f;
	//cout << "Hello cruel world!\n";

	for (int i=0; i<sizeOfOldFaceArray; i++)
	{
		Vertex facep;
		int facePointIndex;
		int newEdgeAIndex,newEdgeBIndex,newEdgeCIndex,newEdgeDIndex,newEdgeEIndex,newEdgeFIndex,newEdgeGIndex,newEdgeHIndex,newEdgeIIndex,newEdgeJIndex,newEdgeKIndex,newEdgeLIndex,newEdgeMIndex,newEdgeNIndex,newEdgeOIndex,newEdgePIndex;
		int edgePointAIndex,edgePointBIndex,edgePointCIndex,edgePointDIndex;
		int newVertPointAIndex, newVertPointBIndex, newVertPointCIndex,newVertPointDIndex;

		// Get Face Point and add it to the new Vertex Array, if already in existence take the new Vertex
		if (!gOps.existsInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] =  oldFaceArray[i].getCentroid();
			facePointIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			//Face points should be added more than once.
			cerr << "This shouldn't happen\n";
			facePointIndex = gOps.whereInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray);
		}

		/*
		 * Generating each Edge point on the face for Edges A,B,C and D. Adding it if it doesn't exist in the QFace Array
		 * and assigning the index in the array to a variable.
		 */
		Vertex edgePointA;
		edgePointA = gOps.getEdgePoint(oldFaceArray[i].getEdgeA(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = edgePointA;
			edgePointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointAIndex = gOps.whereInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointB;
		edgePointB = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointB = gOps.getEdgePoint(oldFaceArray[i].getEdgeB(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = edgePointB;
			edgePointBIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointBIndex = gOps.whereInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointC;
		edgePointC = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointC = gOps.getEdgePoint(oldFaceArray[i].getEdgeC(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = edgePointC;
			edgePointCIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointCIndex = gOps.whereInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointD;
		edgePointD = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointD = gOps.getEdgePoint(oldFaceArray[i].getEdgeD(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointD,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = edgePointD;
			edgePointDIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointDIndex = gOps.whereInNewVertexArray(edgePointD,vertexArrayPtr,sizeOfVertexArray);
		}

		/*
		 * Generating each new Catmull-Clark Vertex point on the face for Points A,B,C and D.
		 * Adding it if it doesn't exist in the Face Array and assigning the index
		 * in the array to a variable.
		 */
		Vertex newV1 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV1,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointAIndex = gOps.whereInNewVertexArray(newV1,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex newV2 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointB(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV2,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointB(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointBIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointBIndex = gOps.whereInNewVertexArray(newV2,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex newV3 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointC(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV3,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointC(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointCIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointCIndex = gOps.whereInNewVertexArray(newV3,vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex newV4 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointD(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV4,vertexArrayPtr,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointD(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointDIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointDIndex = gOps.whereInNewVertexArray(newV4,vertexArrayPtr,sizeOfVertexArray);
		}

		//Stitching up Process
		/*
		 * The First Face Generated from the old face starting from the NewVertex point and working around anti-clockwise
		 * to the edgePoint then face point to the the second Edge point concluding at the Vertex point.
		 */
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointAIndex],&vertexArray[edgePointDIndex]);
		newEdgeAIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointDIndex],&vertexArray[facePointIndex]);
		newEdgeBIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointAIndex]);
		newEdgeCIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointAIndex],&vertexArray[newVertPointAIndex]);
		newEdgeDIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false,&edgeArray[newEdgeDIndex],false);
		sizeOfFaceArray++;


		// Stitching up the Second Face
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointBIndex],&vertexArray[edgePointAIndex]);
		newEdgeEIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointAIndex],&vertexArray[facePointIndex]);
		newEdgeFIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointBIndex]);
		newEdgeGIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointBIndex],&vertexArray[newVertPointBIndex]);
		newEdgeHIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeEIndex],false,&edgeArray[newEdgeFIndex],false,&edgeArray[newEdgeGIndex],false,&edgeArray[newEdgeHIndex],false);
		sizeOfFaceArray++;


		// Stitching up the Third Face
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointCIndex],&vertexArray[edgePointBIndex]);
		newEdgeIIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointBIndex],&vertexArray[facePointIndex]);
		newEdgeJIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointCIndex]);
		newEdgeKIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointCIndex],&vertexArray[newVertPointCIndex]);
		newEdgeLIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeIIndex],false,&edgeArray[newEdgeJIndex],false,&edgeArray[newEdgeKIndex],false,&edgeArray[newEdgeLIndex],false);
		sizeOfFaceArray++;

		/*
		 * Stitching up the Fourth Face this is the final face as Catmull-Clark generates
		 * four new Faces from a Quad Surface.
		 */
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[newVertPointDIndex],&vertexArray[edgePointCIndex]);
		newEdgeMIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointCIndex],&vertexArray[facePointIndex]);
		newEdgeNIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[facePointIndex],&vertexArray[edgePointDIndex]);
		newEdgeOIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[edgePointDIndex],&vertexArray[newVertPointDIndex]);
		newEdgePIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeMIndex],false,&edgeArray[newEdgeNIndex],false,&edgeArray[newEdgeOIndex],false,&edgeArray[newEdgePIndex],false);
		sizeOfFaceArray++;

	}

}


Catmull::~Catmull() {
	//Destructor
}

/*
 * Drawing function loads translates and rotates the OpenGL camera and draws the faces
 * lines and points if their respective parameters which are passed are true.
 */
void Catmull::draw(bool faces, bool lines, bool points){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
		// Reset The Current Modelview Matrix
		glLoadIdentity();
		// put the thing somewhere between the near and far clipping panes
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(rotAng,0.0f,0.1f,0.);

		if (faces) {
			for(int i=0;i<sizeOfFaceArray;i++)
			{
				glBegin(GL_QUADS);
				//OpenGL must be counter clockwise!

				glColor3f(1.0f,0.0f,0.0f);
				if(i%2==1)
				{
					glColor3f(0.0f,0.0f,1.0f); //Blue
				}

				glVertex3f(faceArray[i].getPointA()->getX(),faceArray[i].getPointA()->getY(),faceArray[i].getPointA()->getZ());
				glVertex3f(faceArray[i].getPointB()->getX(),faceArray[i].getPointB()->getY(),faceArray[i].getPointB()->getZ());
				glVertex3f(faceArray[i].getPointC()->getX(),faceArray[i].getPointC()->getY(),faceArray[i].getPointC()->getZ());
				glVertex3f(faceArray[i].getPointD()->getX(),faceArray[i].getPointD()->getY(),faceArray[i].getPointD()->getZ());

				glEnd();
			}
		}

		if (lines)
		{
			for (int j =0; j<sizeOfEdgeArray;j++)
			{
				glBegin(GL_LINES);

				glColor3f(1.0f,1.0f,1.0f);


				glVertex3f(edgeArray[j].getVertexA()->getX(),edgeArray[j].getVertexA()->getY(),edgeArray[j].getVertexA()->getZ());
				glVertex3f(edgeArray[j].getVertexB()->getX(),edgeArray[j].getVertexB()->getY(),edgeArray[j].getVertexB()->getZ());

				glEnd();
			}
		}

		if (points)
		{
			for (int j =0; j<sizeOfVertexArray;j++)
			{
				glBegin(GL_POINTS);
				//OpenGL must be counter clockwise!

				glColor3f(1.0f,1.0f,0.0f);

				glVertex3f(vertexArray[j].getX(),vertexArray[j].getY(),vertexArray[j].getZ());

				glEnd();
			}
		}
	rotAng += 0.8;
}

// Returning pointers and sizes of arrays for use on the next iteration of Catmull-Clark.
int Catmull::returnSizeOfVertexArray()
{
	return sizeOfVertexArray;
}

int Catmull::returnSizeOfEdgeArray()
{
	return sizeOfEdgeArray;
}

int Catmull::returnSizeOfFaceArray()
{
	return sizeOfFaceArray;
}

Vertex * Catmull::returnVertexArrayPtr(){
	return vertexArrayPtr;
}

Edge * Catmull::returnEdgeArrayPtr(){
	return edgeArrayPtr;
}

QFace * Catmull::returnFaceArrayPtr(){
	return faceArrayPtr;
}
