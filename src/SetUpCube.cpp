/*
 * SetUpCube.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include "SetUpCube.h"
#include "GeometryOps.h"
#include <iostream>

using namespace std;
//TODO Rename from SetupCube?
SetUpCube::SetUpCube() {

	cout<<"cube starts setting up!\n";

	vertexArray[0] = Vertex(-0.5f,-0.5f,0.5f);
	vertexArray[1] = Vertex(0.5f,-0.5f,0.5f);
	vertexArray[2] = Vertex(0.5f,0.5f,0.5f);
	vertexArray[3] = Vertex(-0.5f,0.5f,0.5f);
	vertexArray[4] = Vertex(-0.5f,-0.5f,-0.5f);
	vertexArray[5] = Vertex(0.5f,-0.5f,-0.5f);
	vertexArray[6] = Vertex(0.5f,0.5f,-0.5f);
	vertexArray[7] = Vertex(-0.5f,0.5f,-0.5f);
	cout<< "cube Vertices set up\n";

	edgeArray[0] = Edge(&vertexArray[3],&vertexArray[2]); // a 1
	edgeArray[1] = Edge(&vertexArray[2],&vertexArray[6]); // b 2
	edgeArray[2] = Edge(&vertexArray[6],&vertexArray[7]); // c 3
	edgeArray[3] = Edge(&vertexArray[7],&vertexArray[3]); // d 4
	edgeArray[4] = Edge(&vertexArray[2],&vertexArray[7]); // e 5
	edgeArray[5] = Edge(&vertexArray[1],&vertexArray[2]); // f 6
	edgeArray[6] = Edge(&vertexArray[0],&vertexArray[1]); // g 7
	edgeArray[7] = Edge(&vertexArray[0],&vertexArray[3]); // h 8
	edgeArray[8] = Edge(&vertexArray[2],&vertexArray[0]); // i 9
	edgeArray[9] = Edge(&vertexArray[0],&vertexArray[4]); // j 10
	edgeArray[10] = Edge(&vertexArray[5],&vertexArray[1]); // k 11
	edgeArray[11] = Edge(&vertexArray[4],&vertexArray[5]); // l 12
	edgeArray[12] = Edge(&vertexArray[4],&vertexArray[1]); // m 13
	edgeArray[13] = Edge(&vertexArray[7],&vertexArray[4]); // n 14
	edgeArray[14] = Edge(&vertexArray[5],&vertexArray[6]); // o 15
	edgeArray[15] = Edge(&vertexArray[4],&vertexArray[6]); // p 16
	edgeArray[16] = Edge(&vertexArray[3],&vertexArray[4]); // q 17
	edgeArray[17] = Edge(&vertexArray[2],&vertexArray[5]); // r 18
	cout<< "cube Edges set up\n";

	faceArray[0] = Face(&edgeArray[2],false,&edgeArray[4],true,&edgeArray[1],false); //top back g
	faceArray[1] = Face(&edgeArray[3],false,&edgeArray[0],false,&edgeArray[4],false); //top front g a
	faceArray[2] = Face(&edgeArray[7],false,&edgeArray[0],false,&edgeArray[8],false); // front top g a
	faceArray[3] = Face(&edgeArray[8],false,&edgeArray[6],false,&edgeArray[5],false); //front bottom g a
	faceArray[4] = Face(&edgeArray[9],false,&edgeArray[12],false,&edgeArray[6],true); // bottom front g
	faceArray[5] = Face(&edgeArray[12],true,&edgeArray[11],false,&edgeArray[10],false); //bottom back g
	faceArray[6] = Face(&edgeArray[11],false,&edgeArray[14],false,&edgeArray[15],true); // back bottom g
	faceArray[7] = Face(&edgeArray[13],false,&edgeArray[15],false,&edgeArray[2],false); //Back top a
	faceArray[8] = Face(&edgeArray[3],true,&edgeArray[13],false,&edgeArray[16],true); // left top
	faceArray[9] = Face(&edgeArray[16],false,&edgeArray[9],true,&edgeArray[7],false); //left bottom
	faceArray[10] = Face(&edgeArray[14],true,&edgeArray[17],true,&edgeArray[1],false); // right top
	faceArray[11] = Face(&edgeArray[17],false,&edgeArray[10],false,&edgeArray[5],false); // right bottom a
	cout<< "cube Faces set up\n";

	int sizeOfEdgeArray = 18;
	int sizeOfVertexArray = 8;
	int sizeOfFaceArray = 12;


	//angle variable to rotate the cube.
	rotAng = 0.0f;

	//assign pointers to arrays
	//Vertex * vertexArrayPtr;
	vertexArrayPtr = vertexArray;
	//Face * faceArrayPtr;
	faceArrayPtr = faceArray;
	//Edge * edgeArrayPtr;
	edgeArrayPtr = edgeArray;

	GeometryOps gOps = GeometryOps();

	//MAKE NEW FACE EDGE VERTEX STRUCTURE¬!"!!!!!
	//ok here we go..
	Vertex newVertexArray[50];
	Vertex *newVertexArrayPtr = newVertexArray;


	int totalNewVerts = 0;
	int totalNewEdges = 0;
	int totalNewFaces = 0;

	/**SOLUTION?
	For each face
	Take two edges
	take their edge points for point on newFace
	and the new Vertex for the 4th point on the face
	addToVertex Array if not existing in VertexArray
	Repeat twice (3x more on next iteratations) more for the next two Pair of edges on the face.
	Repeat for all faces.**/

	/*Pass the class to create new arrays the current amount of vertices faces and edges
	 * in the current structure so it will generate the right size of array. The array stored in this new class
	 * will ensure things don't get deleted.
	 */

	/*for (int i=0; i<sizeOfFaceArray; i++)
	{
		Vertex facep;
		facep = faceArrayPtr[i].getCentroid();
		newVertexArray[totalNewVerts] = facep;
		totalNewVerts++;

		Vertex edgePointA;
		edgePointA = faceArrayPtr[i].getEdgeA()->getEdgePoint();
		edgePointA = gOps.getEdgePoint(faceArrayPtr[i].getEdgeA(),faceArrayPtr,sizeOfFaceArray,edgeArrayPtr,sizeOfEdgeArray);

		if(!gOps.existsInNewVertexArray(edgePointA,newVertexArrayPtr,50))
		{
			newVertexArray[totalNewVerts] = edgePointA;
			totalNewVerts++;
		}

		Vertex newV1 = gOps.generateNewVertexPoint(faceArrayPtr[i].getEdgeA()->getVertexB(),faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);
				 if(!gOps.existsInNewVertexArray(newV1,newVertexArrayPtr,50))
				 {
					 newVertexArray[totalNewVerts] = newV1;
					 totalNewVerts++;
				 }

		//Edge newE1 = Edge(edgePointA,newV1);


		Vertex edgePointB;
		faceArrayPtr[i].getEdgeB()->setEdgePoint(gOps.getEdgePoint(faceArrayPtr[i].getEdgeB(),faceArrayPtr,sizeOfFaceArray,edgeArrayPtr,sizeOfEdgeArray));
		edgePointB = faceArrayPtr[i].getEdgeB()->getEdgePoint();
		if(!gOps.existsInNewVertexArray(edgePointB,newVertexArrayPtr,50))
		{
			newVertexArray[totalNewVerts] = edgePointB;
			totalNewVerts++;
		}

		//else{cout<<"caught!\n";}
		Vertex edgePointC;
		faceArrayPtr[i].getEdgeC()->setEdgePoint(gOps.getEdgePoint(faceArrayPtr[i].getEdgeC(),faceArrayPtr,sizeOfFaceArray,edgeArrayPtr,sizeOfEdgeArray));
		edgePointC = faceArrayPtr[i].getEdgeC()->getEdgePoint();
		//edgePointC = gOps.getEdgePoint(faceArrayPtr[i].getEdgeC(),faceArrayPtr,sizeOfFaceArray);
		if(!gOps.existsInNewVertexArray(edgePointC,newVertexArrayPtr,50))
		{
			newVertexArray[totalNewVerts] = edgePointC;
			totalNewVerts++;
		}
		 Vertex newV2 = gOps.generateNewVertexPoint(faceArrayPtr[i].getEdgeA()->getVertexA(),faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);
		 if(!gOps.existsInNewVertexArray(newV2,newVertexArrayPtr,50))
		 {
			 newVertexArray[totalNewVerts] = newV2;
			 totalNewVerts++;
		 }

		 Vertex newV3 = gOps.generateNewVertexPoint(faceArrayPtr[i].getEdgeB()->getVertexA(),faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);
		 if(!gOps.existsInNewVertexArray(newV3,newVertexArrayPtr,50))
		 {
			 newVertexArray[totalNewVerts] = newV3;
			 totalNewVerts++;
		 }
		 //else{cout<<"caught!\n";}
	}*/

	/*cout << "Yay! total new Faces = " << totalNewFaces <<endl;
	cout << "Yay! total new Edges = " << totalNewEdges <<endl;
	cout << "Yay! total new Verts = " << totalNewVerts <<endl;
	//cout << "face 1 attempt "<< newFaceArray[0].getEdgeA().getVertexA()->getX() <<endl;


	for (int i =0; i<totalNewVerts; i++)
	{
		cout<< "New Shapes Vertex "<< i <<" "<< gOps.vertexToString(newVertexArray[i]) <<endl;
	}

	cout <<"\n"<<endl;*/

	/*for (int i = 0; i<12; i++)
	{
		cout << "***Face " << i <<endl;
		cout << " first : " << faceArray[i].getEdgeA()->getVertexA()->getX()<< "::"<< faceArray[i].getEdgeA()->getVertexA()->getY() << "::" <<faceArray[i].getEdgeA()->getVertexA()->getZ()<<endl;
		cout << " second : " << faceArray[i].getEdgeA()->getVertexB()->getX()<< "::"<< faceArray[i].getEdgeA()->getVertexB()->getY() << "::" <<faceArray[i].getEdgeA()->getVertexB()->getZ()<<endl;
		cout << " third : " << faceArray[i].getEdgeB()->getVertexB()->getX()<< "::"<< faceArray[i].getEdgeB()->getVertexB()->getY() << "::" <<faceArray[i].getEdgeB()->getVertexB()->getZ()<<endl;
	}*/

	/*for(int i=0;i<sizeOfEdgeArray;i++)
	{
		cout <<"***EdgePoint " << i << " = " << gOps.vertexToString(edgeArrayPtr[i].getEdgePoint())<<endl;
	}*/

}

SetUpCube::~SetUpCube() {
	// TODO Auto-generated destructor stub
}

Edge SetUpCube::reverseEdge(Edge reversing){
	Edge tempEdge;
	//Edge tempEdge = Edge(reversing.getVertexB(),reversing.getVertexA());
	return tempEdge;
}

Face * SetUpCube::getFaceArray(){
	return faceArray;
}

void SetUpCube::draw(){
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
		// Reset The Current Modelview Matrix
		glLoadIdentity();
		// put the thing somewhere between the near and far clipping panes
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(rotAng,0.0f,0.5f,1.0);

		for(int i=0;i<12;i++)
			{
				glBegin(GL_TRIANGLES);
				//OpenGL must be counter clockwise!

				if(i%2==1)
				{
					glColor3f(1.0f,0.0f,0.0f); //Red
				}
				else
				{
					glColor3f(0.0f,0.0f,1.0f); //Blue
				}

				if(faceArray[i].getEdgeADirection())
				{
					glVertex3f(faceArray[i].getEdgeA()->getVertexB()->getX(),faceArray[i].getEdgeA()->getVertexB()->getY(),faceArray[i].getEdgeA()->getVertexB()->getZ());
					glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ()); //
				}
				else
				{
					glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ());
					glVertex3f(faceArray[i].getEdgeA()->getVertexB()->getX(),faceArray[i].getEdgeA()->getVertexB()->getY(),faceArray[i].getEdgeA()->getVertexB()->getZ());
				}

				if(faceArray[i].getEdgeBDirection())
				{
					glVertex3f(faceArray[i].getEdgeC()->getVertexB()->getX(),faceArray[i].getEdgeB()->getVertexA()->getY(),faceArray[i].getEdgeB()->getVertexA()->getZ());
				}
				else
				{
					glVertex3f(faceArray[i].getEdgeC()->getVertexA()->getX(),faceArray[i].getEdgeB()->getVertexB()->getY(),faceArray[i].getEdgeB()->getVertexB()->getZ());
				}
				glEnd();
			}
		//cout << "one draw?\n";
		rotAng += 0.2;
}

Face * SetUpCube::returnFaceArrayPtr()
{
	return faceArrayPtr;
}

Edge * SetUpCube::returnEdgeArrayPtr()
{
	return edgeArrayPtr;
}

Vertex * SetUpCube::returnVertexArrayPtr()
{
	return vertexArrayPtr;
}
