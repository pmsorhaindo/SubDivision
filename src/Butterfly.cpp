/*
 * Butterfly.cpp
 *
 *  Created on: 11 Dec 2011
 *      Author: mikey
 */


#include <GL/gl.h>
#include <GL/glu.h>
#include "Butterfly.h"
#include <iostream>
using namespace std;

Butterfly::Butterfly() {
	// TODO Auto-generated constructor stub

}
Butterfly::Butterfly(int numberOfOldVertices, int numberOfOldEdges, int numberOfOldFaces, Vertex *oldVerts, Edge *oldEdges, Face *oldFaces)
{
	faceArray = new Face[numberOfOldFaces*3];
	edgeArray = new Edge[numberOfOldEdges*10];
	vertexArray = new Vertex[numberOfOldVertices*10];
	sizeOfVertexArray = 0;
	sizeOfEdgeArray = 0;
	sizeOfFaceArray = 0;

	rotAng = 0.0f;
	GeometryOps gOps = GeometryOps();

	for(int i=0; i<numberOfOldEdges; i++)
	{
		cout << "Edge " << i << " toStr is: " << gOps.edgeToString(oldEdges[i])<<"\n";
	}
	cout << "\n";

	int v1Index,v2Index,v3Index;

	for (int i=0; i<numberOfOldFaces; i++)
	{
		//cout <<"face " << i <<" edge A spits out: " << gOps.vertexToString(getNewEdgePoint(oldFaces->getEdgeA(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces))<<"\n";
		//cout <<"face " << i <<" edge B spits out: " << gOps.vertexToString(getNewEdgePoint(oldFaces->getEdgeB(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces))<<"\n";
		//cout <<"face " << i <<" edge C spits out: " << gOps.vertexToString(getNewEdgePoint(oldFaces->getEdgeC(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces))<<"\n";
		Vertex tempV1 = getNewEdgePoint(oldFaces[i].getEdgeA(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
		Vertex tempV2 = getNewEdgePoint(oldFaces[i].getEdgeB(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
		Vertex tempV3 = getNewEdgePoint(oldFaces[i].getEdgeC(),oldEdges,numberOfOldEdges,oldFaces,numberOfOldFaces);
		cout << "loop\n";
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
			v3Index = gOps.whereInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray);
		}

		tempV1 = *oldFaces[i].getPointA();
		tempV2 = *oldFaces[i].getPointB();
		tempV3 = *oldFaces[i].getPointC();

		int p1Index,p2Index,p3Index;

		if (!gOps.existsInNewVertexArray(tempV1,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointA();
			v1Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p1Index= gOps.whereInNewVertexArray(tempV1,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointB();
			v2Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p2Index = gOps.whereInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV3,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointC();
			v3Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p3Index = gOps.whereInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray);
		}

		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[p1Index],&vertexArray[v1Index]);
		int newEdgeAIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v1Index],&vertexArray[v2Index]);
		int newEdgeBIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v2Index],&vertexArray[p1Index]);
		int newEdgeCIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false);
		sizeOfFaceArray++;

	}

	for (int i =0; i<sizeOfVertexArray; i++)
	{
		cout << "owch " << gOps.vertexToString(vertexArray[i]) <<"\n";
	}

}

Butterfly::~Butterfly() {
	// TODO Auto-generated destructor stub
}


Vertex Butterfly::getNewEdgePoint(Edge * edgeToWork,Edge * oldEdges, int numberOfOldEdges, Face * oldFaces, int numberOfOldFaces){

		//Run for all faces
		//run the the function for for each edge on a face and stitch up and create new Faces
		//Functionize to take an edge and do this to it
		GeometryOps gOps = GeometryOps();

		Vertex t1 = *(edgeToWork->getVertexA());
		GeometryOps::eightEdge valT1 = gOps.getIncidentEdges(&t1,oldEdges,numberOfOldEdges);
		//cout << "valance1 = " << valT1.contains <<"\n";
		Vertex t2 = *(edgeToWork->getVertexB());
		GeometryOps::eightEdge valT2 = gOps.getIncidentEdges(&t1,oldEdges,numberOfOldEdges);
		//cout << "valance1 = " << valT2.contains <<"\n";
		//cout << gOps.vertexToString(t1) << "\n";
		//cout << gOps.vertexToString(t2) << "\n";

		GeometryOps::twoFace firstFaces = gOps.getOtherFace(*edgeToWork,oldFaces,numberOfOldFaces);
		//cout << "testy 1 " << gOps.vertexToString(*firstFaces.faceOne.getEdgeA()->getVertexA()) <<"\n";
		//cout << "testy 2 " << gOps.vertexToString(*firstFaces.faceTwo.getEdgeA()->getVertexA()) <<"\n";

		Vertex t3 = gOps.thirdPointInFace(t1,t2,firstFaces.faceOne);
		Vertex t4 = gOps.thirdPointInFace(t1,t2,firstFaces.faceTwo);
		//cout << "thirdy " << gOps.vertexToString(t3) << "\n";
		//cout << "thirdy " << gOps.vertexToString(t4) << "\n";

		//cout << "lmfao!?" << endl;
		//cout << gOps.vertexToString(t1) << "::" << gOps.vertexToString(t3) <<"::"<<gOps.vertexToString(t2)<<"\n";
		Vertex t5 = gOps.getWings(t1, t3, oldFaces, numberOfOldFaces,t2);
		Vertex t6 = gOps.getWings(t1, t4, oldFaces, numberOfOldFaces,t2);
		Vertex t7 = gOps.getWings(t2, t3, oldFaces, numberOfOldFaces,t1);
		Vertex t8 = gOps.getWings(t2, t4, oldFaces, numberOfOldFaces,t1);
		/*cout << "points t1-t8" << "\n";
		cout << "t1" <<gOps.vertexToString(t1) << "\n";
		cout << "t2" <<gOps.vertexToString(t2) << "\n";
		cout << "t3" <<gOps.vertexToString(t3) << "\n";
		cout << "t4" <<gOps.vertexToString(t4) << "\n";
		cout << "t5" <<gOps.vertexToString(t5) << "\n";
		cout << "t6" <<gOps.vertexToString(t6) << "\n";
		cout << "t7" <<gOps.vertexToString(t7) << "\n";
		cout << "t8" <<gOps.vertexToString(t8) << "\n";*/

		//weightings
		t1=t1*0.5f;
		t2=t2*0.5f;
		t3=t3*0.125f;
		t4=t4*0.125f;
		t5=t5*-0.0625f;
		t6=t6*-0.0625f;
		t7=t7*-0.0625f;
		t8=t8*-0.0625f;
		Vertex resultv = t1+t2+t3+t4+t5+t6+t7+t8;
		//resultv.div(8.0f);
		//cout << "resultv : " << gOps.vertexToString(resultv) << "\n\n";
		return resultv;
}

void Butterfly::draw(){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
		// Reset The Current Modelview Matrix
		glLoadIdentity();
		// put the thing somewhere between the near and far clipping panes
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(rotAng,0.0f,0.1f,0.);

		/*for (int i = 0; i <sizeOfFaceArray; i++)
		{
		cout << " ---- face " << i << " drawn at: " <<endl;
		cout << "x: " << faceArray[i].getPointA()->getX() << " y: "<< faceArray[i].getPointA()->getY() << " z: " << faceArray[i].getPointA()->getZ()<< "\n";
		cout << "x: " << faceArray[i].getPointB()->getX() << " y: "<< faceArray[i].getPointB()->getY() << " z: " << faceArray[i].getPointB()->getZ()<< "\n";
		cout << "x: " << faceArray[i].getPointC()->getX() << " y: "<< faceArray[i].getPointC()->getY() << " z: " << faceArray[i].getPointC()->getZ()<< "\n";
		cout << "x: " << faceArray[i].getPointD()->getX() << " y: "<< faceArray[i].getPointD()->getY() << " z: " << faceArray[i].getPointD()->getZ()<< "\n\n";
		}*/

		for(int i=0;i<sizeOfFaceArray;i++)
		{
			glBegin(GL_QUADS);
			//OpenGL must be counter clockwise!

			if(i%4==1)
			{
				glColor3f(1.0f,0.0f,0.0f); //Red
			}
			else if(i%4==2)
			{
				glColor3f(0.0f,0.0f,1.0f); //Blue
			}
			/*else if(i%4==3)
			{
				glColor3f(1.0f,0.5f,0.2f);
			}
			else
			{
				glColor3f(1.0f,0.5f,0.2f);
			}*/

			glVertex3f(faceArray[i].getPointA()->getX(),faceArray[i].getPointA()->getY(),faceArray[i].getPointA()->getZ());
			glVertex3f(faceArray[i].getPointB()->getX(),faceArray[i].getPointB()->getY(),faceArray[i].getPointB()->getZ());
			glVertex3f(faceArray[i].getPointC()->getX(),faceArray[i].getPointC()->getY(),faceArray[i].getPointC()->getZ());


			glEnd();

			glBegin(GL_LINES);
			//OpenGL must be counter clockwise!

			if(i%2==1)
			{
				glColor3f(1.0f,0.0f,0.0f); //Red
			}
			else
			{
				glColor3f(0.0f,0.0f,1.0f); //Blue
			}

			//glVertex3f(faceArray[i].getPointA()->getX(),faceArray[i].getPointA()->getY(),faceArray[i].getPointA()->getZ());
			//glVertex3f(faceArray[i].getPointB()->getX(),faceArray[i].getPointB()->getY(),faceArray[i].getPointB()->getZ());
			//glVertex3f(faceArray[i].getPointC()->getX(),faceArray[i].getPointC()->getY(),faceArray[i].getPointC()->getZ());
			//glVertex3f(faceArray[i].getPointD()->getX(),faceArray[i].getPointD()->getY(),faceArray[i].getPointD()->getZ());

			//glVertex3f(0,0.416667,-0.416667);
			//glVertex3f(0.291667,0.291667,-0.395833);
			//glVertex3f(0.291667,0.291667,-0.395833);
			//glVertex3f(0,0.5,0);
			//glVertex3f(0,0.5,0);
			//glVertex3f(0.166667,0.5,-0.166667);
			//glColor3f(0.0f,0.0f,1.0f);
			//glVertex3f(0.166667,0.5,-0.166667);
			//glVertex3f(0,0.416667,-0.416667);
			glEnd();
		}
	//cout << "one draw?\n";
	rotAng += 0.8;
}
