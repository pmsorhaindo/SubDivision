//============================================================================
// Name        : Butterfly.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class implements and stiches up Butterfly Subdivison. - in C++, Ansi-style
//============================================================================

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Butterfly.h"

using namespace std;

Butterfly::Butterfly() {
	// Empty Constructor.
}

Butterfly::Butterfly(int numberOfOldVertices, int numberOfOldEdges, int numberOfOldFaces, Vertex *oldVerts, Edge *oldEdges, Face *oldFaces)
{
	faceArray = new Face[numberOfOldFaces*4];
	edgeArray = new Edge[numberOfOldEdges*8];
	vertexArray = new Vertex[numberOfOldVertices*6];
	sizeOfVertexArray = 0;
	sizeOfEdgeArray = 0;
	sizeOfFaceArray = 0;
	rotAng = 0.0f;

	GeometryOps gOps = GeometryOps();

	int v1Index,v2Index,v3Index;

	/*
	 * Loops through the Array of oldFaces and calculates new points for each Edge storing them in a new Edge array.
	 * These edges new index's in the array are saved in variables for the stitching up process.
	 */
	for (int i=0; i<numberOfOldFaces; i++)
	{
		Vertex tempV1 = getNewEdgePoint(oldFaces[i].getEdgeA(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
		Vertex tempV2 = getNewEdgePoint(oldFaces[i].getEdgeB(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
		Vertex tempV3 = getNewEdgePoint(oldFaces[i].getEdgeC(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);

		if (!gOps.existsInNewVertexArray(tempV1,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = getNewEdgePoint(oldFaces[i].getEdgeA(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
			v1Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			v1Index= gOps.whereInNewVertexArray(tempV1,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = getNewEdgePoint(oldFaces[i].getEdgeB(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
			v2Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			v2Index = gOps.whereInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV3,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = getNewEdgePoint(oldFaces[i].getEdgeC(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
			v3Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			v3Index = gOps.whereInNewVertexArray(tempV3,vertexArray,sizeOfVertexArray);
		}

		Vertex tempV4 = *oldFaces[i].getPointA();
		Vertex tempV5 = *oldFaces[i].getPointB();
		Vertex tempV6 = *oldFaces[i].getPointC();

		int p1Index,p2Index,p3Index;

		if (!gOps.existsInNewVertexArray(tempV4,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointA();
			p1Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p1Index= gOps.whereInNewVertexArray(tempV4,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV5,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointB();
			p2Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p2Index = gOps.whereInNewVertexArray(tempV5,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV6,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointC();
			p3Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p3Index = gOps.whereInNewVertexArray(tempV6,vertexArray,sizeOfVertexArray);
		}

		//Stitching up the four new triangles that are generated from each old triangle Face.
		// Going anticlockwise from the original pointA(p1Index)
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[p1Index],&vertexArray[v3Index]);
		int newEdgeAIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v3Index],&vertexArray[v1Index]);
		int newEdgeBIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v1Index],&vertexArray[p1Index]);
		int newEdgeCIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		// Adding the Face to the Face Array.
		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false);
		sizeOfFaceArray++;

		// Going anticlockwise from the original pointB(p2Index)
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[p2Index],&vertexArray[v1Index]);
		int newEdgeDIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v1Index],&vertexArray[v2Index]);
		int newEdgeEIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v2Index],&vertexArray[p2Index]);
		int newEdgeFIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		// Adding the Face to the Face Array.
		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeDIndex],false,&edgeArray[newEdgeEIndex],false,&edgeArray[newEdgeFIndex],false);
		sizeOfFaceArray++;

		// Going anticlockwise from the original pointC(p3Index)
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[p3Index],&vertexArray[v2Index]);
		int newEdgeGIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v2Index],&vertexArray[v3Index]);
		int newEdgeHIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v3Index],&vertexArray[p3Index]);
		int newEdgeIIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		// Adding the Face to the Face Array.
		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeGIndex],false,&edgeArray[newEdgeHIndex],false,&edgeArray[newEdgeIIndex],false);
		sizeOfFaceArray++;


		//Stitching up the inside of the of the triangle, connecting up the newly generated points.
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v1Index],&vertexArray[v3Index]);
		int newEdgeJIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v3Index],&vertexArray[v2Index]);
		int newEdgeKIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v2Index],&vertexArray[v1Index]);
		int newEdgeLIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		// Adding the Face to the Face Array.
		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeJIndex],false,&edgeArray[newEdgeKIndex],false,&edgeArray[newEdgeLIndex],false);
		sizeOfFaceArray++;

	}
}

Butterfly::~Butterfly() {
	// Destructor
}

/*
 * Calculates a new Butterfly edgePoint from on the average of eight surrounding vertices located using the
 * Butterfly stencil.
 */
Vertex Butterfly::getNewEdgePoint(Edge * edgeToWork,Edge * oldEdges, int numberOfOldEdges, Face * oldFaces, int numberOfOldFaces){

		GeometryOps gOps = GeometryOps();

		/*
		 * For vertex t1 and t2 the valence is calculated this would be used to calculate weightings for increased the smoothing of
		 * this is held in ValT1 and ValT2 but is unused. As I never got modified butterfly fully implemented.
		 */
		Vertex t1 = *(edgeToWork->getVertexA());
		GeometryOps::eightEdge valT1 = gOps.getIncidentEdges(&t1,oldEdges,numberOfOldEdges);
		Vertex t2 = *(edgeToWork->getVertexB());
		GeometryOps::eightEdge valT2 = gOps.getIncidentEdges(&t1,oldEdges,numberOfOldEdges);

		GeometryOps::twoFace firstFaces = gOps.getOtherFace(*edgeToWork,oldFaces,numberOfOldFaces);

		Vertex t3 = gOps.thirdPointInFace(t1,t2,firstFaces.faceOne);
		Vertex t4 = gOps.thirdPointInFace(t1,t2,firstFaces.faceTwo);

		Vertex t5 = gOps.getWings(t1, t3, oldFaces, numberOfOldFaces,t2);
		Vertex t6 = gOps.getWings(t1, t4, oldFaces, numberOfOldFaces,t2);
		Vertex t7 = gOps.getWings(t2, t3, oldFaces, numberOfOldFaces,t1);
		Vertex t8 = gOps.getWings(t2, t4, oldFaces, numberOfOldFaces,t1);

		//The weightings for each point on the Butterfly stencil.
		t1=t1*0.5f;
		t2=t2*0.5f;
		t3=t3*0.125f;
		t4=t4*0.125f;
		t5=t5*-0.0625f;
		t6=t6*-0.0625f;
		t7=t7*-0.0625f;
		t8=t8*-0.0625f;
		Vertex resultv = t1+t2+t3+t4+t5+t6+t7+t8;
		return resultv;
}

/*
 * Drawing function loads translates and rotates the OpenGL camera and draws the faces
 * lines and points if their respective parameters which are passed are true.
 */
void Butterfly::draw(bool faces,bool lines,bool points){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
		// Reset The Current Modelview Matrix
		glLoadIdentity();
		// put the thing somewhere between the near and far clipping panes
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(rotAng,0.0f,0.1f,0.);

		// Drawing code for faces. If requested.
		if(faces)
		{
			// For each face get each unique point in the Face get its X,Y and Z values for use in glVertex3f within GL_TRIANGLES.
			for(int i=0;i<sizeOfFaceArray;i++)
			{
				glBegin(GL_TRIANGLES);
				//OpenGL must be counter clockwise!

				//based on the i value of the iteration change the colour of the face. Using modulo to alternate between Red and Blue.
				glColor3f(1.0f,0.0f,0.0f); //Red

				if(i%2==1)
				{
					glColor3f(0.0f,0.0f,1.0f); //Blue
				}
				glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ());
				glVertex3f(faceArray[i].getEdgeB()->getVertexA()->getX(),faceArray[i].getEdgeB()->getVertexA()->getY(),faceArray[i].getEdgeB()->getVertexA()->getZ());
				glVertex3f(faceArray[i].getEdgeC()->getVertexA()->getX(),faceArray[i].getEdgeC()->getVertexA()->getY(),faceArray[i].getEdgeC()->getVertexA()->getZ());

				glEnd();
			}
		}


		// Drawing code for lines. If requested.
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

		// Drawing code for points. If requested.
		if (points)
		{
			for (int j =0; j<sizeOfVertexArray;j++)
			{
				glBegin(GL_POINTS);

				glColor3f(1.0f,1.0f,0.0f);
				glVertex3f(vertexArray[j].getX(),vertexArray[j].getY(),vertexArray[j].getZ());

				glEnd();
			}
		}
	rotAng += 0.8;
}

// Returning pointers and sizes of arrays for use on the next iteration of Butterfly.
int Butterfly::returnSizeOfVertexArray(){
	return sizeOfVertexArray;
}

int Butterfly::returnSizeOfEdgeArray(){
	return sizeOfEdgeArray;
}

int Butterfly::returnSizeOfFaceArray(){
	return sizeOfFaceArray;
}

Vertex * Butterfly::returnVertexArrayPtr(){
	return vertexArray;
}

Edge * Butterfly::returnEdgeArrayPtr(){
	return edgeArray;
}

Face * Butterfly::returnFaceArrayPtr(){
	return faceArray;
}
