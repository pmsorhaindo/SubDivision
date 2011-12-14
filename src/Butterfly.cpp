//============================================================================
// Name        : Butterfly.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class implements and stiches up Butterfly Subdivison. - in C++, Ansi-style
//============================================================================

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
	faceArray = new Face[numberOfOldFaces*4];
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
			v3Index = gOps.whereInNewVertexArray(tempV3,vertexArray,sizeOfVertexArray);
		}

		tempV1 = *oldFaces[i].getPointA();
		tempV2 = *oldFaces[i].getPointB();
		tempV3 = *oldFaces[i].getPointC();

		int p1Index,p2Index,p3Index;

		if (!gOps.existsInNewVertexArray(tempV1,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointA();
			p1Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p1Index= gOps.whereInNewVertexArray(tempV1,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointB();
			p2Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p2Index = gOps.whereInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray);
		}

		if (!gOps.existsInNewVertexArray(tempV3,vertexArray,sizeOfVertexArray))
		{
			vertexArray[sizeOfVertexArray] = *oldFaces[i].getPointC();
			p3Index = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			p3Index = gOps.whereInNewVertexArray(tempV2,vertexArray,sizeOfVertexArray);
		}

		int point1 = gOps.existsInNewVertexArray(gOps.twoEdgesGetCommonVertex(*oldFaces[i].getEdgeC(),*oldFaces[i].getEdgeA()),vertexArray,sizeOfVertexArray);
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[p1Index],&vertexArray[v3Index]);
		int newEdgeAIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v3Index],&vertexArray[v1Index]);
		int newEdgeBIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v1Index],&vertexArray[p1Index]);
		int newEdgeCIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false);
		sizeOfFaceArray++;

		int point2 = gOps.existsInNewVertexArray(gOps.twoEdgesGetCommonVertex(*oldFaces[i].getEdgeA(),*oldFaces[i].getEdgeB()),vertexArray,sizeOfVertexArray);
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[p2Index],&vertexArray[v1Index]);
		int newEdgeDIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v1Index],&vertexArray[v2Index]);
		int newEdgeEIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v2Index],&vertexArray[p2Index]);
		int newEdgeFIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeDIndex],false,&edgeArray[newEdgeEIndex],false,&edgeArray[newEdgeFIndex],false);
		sizeOfFaceArray++;

		int point3 = gOps.existsInNewVertexArray(gOps.twoEdgesGetCommonVertex(*oldFaces[i].getEdgeB(),*oldFaces[i].getEdgeC()),vertexArray,sizeOfVertexArray);
		//cout << "point3 Index " << point3 << endl;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[p3Index],&vertexArray[v2Index]);
		int newEdgeGIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v2Index],&vertexArray[v3Index]);
		int newEdgeHIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v3Index],&vertexArray[p3Index]);
		int newEdgeIIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeGIndex],false,&edgeArray[newEdgeHIndex],false,&edgeArray[newEdgeIIndex],false);
		sizeOfFaceArray++;


		//GOOD
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v1Index],&vertexArray[v3Index]);
		int newEdgeJIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v3Index],&vertexArray[v2Index]);
		int newEdgeKIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;
		edgeArray[sizeOfEdgeArray] = Edge(&vertexArray[v2Index],&vertexArray[v1Index]);
		int newEdgeLIndex = sizeOfEdgeArray;
		sizeOfEdgeArray++;

		faceArray[sizeOfFaceArray] = Face(&edgeArray[newEdgeJIndex],false,&edgeArray[newEdgeKIndex],false,&edgeArray[newEdgeLIndex],false);
		sizeOfFaceArray++;

	}

	for (int i =0; i<sizeOfVertexArray; i++)
	{
		cout << "owch " << gOps.vertexToString(vertexArray[i]) <<"\n";
	}
	cout << endl;
	for (int i = 0; i <sizeOfFaceArray; i++)
	{
	cout << " ---- face " << i << " drawn at: " <<endl;
	cout << "x: " << faceArray[i].getPointA()->getX() << " y: "<< faceArray[i].getPointA()->getY() << " z: " << faceArray[i].getPointA()->getZ()<< "\n";
	cout << "x: " << faceArray[i].getPointB()->getX() << " y: "<< faceArray[i].getPointB()->getY() << " z: " << faceArray[i].getPointB()->getZ()<< "\n";
	cout << "x: " << faceArray[i].getPointC()->getX() << " y: "<< faceArray[i].getPointC()->getY() << " z: " << faceArray[i].getPointC()->getZ()<< "\n";
	}
	cout << "Face Array has " << sizeOfFaceArray << " inside." <<endl;
	cout << "Edge Array has " << sizeOfEdgeArray << " inside." <<endl;
	cout << "Vertex Array has " << sizeOfVertexArray << " inside." <<endl;
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
				//OpenGL must be counter clockwise!

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
				//OpenGL must be counter clockwise!

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
