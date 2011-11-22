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

SetUpCube::SetUpCube() {

	cout<<"cube starts setting up!\n";
	Vertex v1 = Vertex(-0.5f,-0.5f,0.5f);//Front anti clock wise bottom left to top left
	Vertex v2 = Vertex(0.5f,-0.5f,0.5f);
	Vertex v3 = Vertex(0.5f,0.5f,0.5f);
	Vertex v4 = Vertex(-0.5f,0.5f,0.5f);
	Vertex v5 = Vertex(-0.5f,-0.5f,-0.5f);//Back anti clockwise From bottom left to top left
	Vertex v6 = Vertex(0.5f,-0.5f,-0.5f);
	Vertex v7 = Vertex(0.5f,0.5f,-0.5f);
	Vertex v8 = Vertex(-0.5f,0.5f,-0.5f);
	cout <<"Cube verts set\n";
	Edge a = Edge(&v4,&v3); //top front
	Edge b = Edge(&v3,&v7); //top right
	Edge c = Edge(&v7,&v8); //top back
	Edge d = Edge(&v8,&v4); //top left
	Edge e = Edge(&v3,&v8); //top middle
	Edge f = Edge(&v2,&v3); //front right
	Edge g = Edge(&v1,&v2); // front bottom
	Edge h = Edge(&v1,&v4); //front left
	Edge i = Edge(&v3,&v1); // front middle
	Edge j = Edge(&v1,&v5); //bottom left
	Edge k = Edge(&v6,&v2); //bottom right
	Edge l = Edge(&v5,&v6); //bottom back
	Edge m = Edge(&v5,&v2); // bottom middle
	Edge n = Edge(&v8,&v5); // back left
	Edge o = Edge(&v6,&v7); // back right
	Edge p = Edge(&v5,&v7); // back middle
	Edge q = Edge(&v4,&v5); // left middle
	Edge r = Edge(&v3,&v6); // right middle
	cout <<"Cube edges set\n";
	//surface -> face
	Face one = Face(&c,false,&e,true,&b,false); //top back g
	Face two = Face(&d,false,&a,false,&e,false); //top front g
	Face three = Face(&h,false,&a,false,&i,false); // front top g
	Face four = Face(&i,false,&g,false,&f,false); //front bottom g
	Face five = Face(&j,false,&m,false,&g,true); // bottom front g
	Face six = Face(&m,true,&l,false,&k,false); //bottom back g
	Face seven = Face(&l,false,&o,false,&p,true); // back bottom g
	Face eight = Face(&n,false,&p,false,&c,false); //Back top
	Face nine = Face(&d,true,&n,false,&q,true); // left top
	Face ten = Face(&q,false,&j,true,&h,false); //left bottom
	Face eleven = Face(&o,true,&r,true,&b,false); // right top
	Face twelve = Face(&r,false,&k,false,&f,false); // right bottom
	cout<< "cube Faces set up\n";

	vertexArray[0] = v1;
	vertexArray[1] = v2;
	vertexArray[2] = v3;
	vertexArray[3] = v4;
	vertexArray[4] = v5;
	vertexArray[5] = v6;
	vertexArray[6] = v7;
	vertexArray[7] = v8;
	int sizeOfVertexArray = 8;

	faceArray[0] = one;
	faceArray[1] = two;
	faceArray[2] = three;
	faceArray[3] = four;
	faceArray[4] = five;
	faceArray[5] = six;
	faceArray[6] = seven;
	faceArray[7] = eight;
	faceArray[8] = nine;
	faceArray[9] = ten;
	faceArray[10] = eleven;
	faceArray[11] = twelve;
	int sizeOfFaceArray = 12;

	edgeArray[0] = a;
	edgeArray[1] = b;
	edgeArray[2] = c;
	edgeArray[3] = d;
	edgeArray[4] = e;
	edgeArray[5] = f;
	edgeArray[6] = g;
	edgeArray[7] = h;
	edgeArray[8] = i;
	edgeArray[9] = j;
	edgeArray[10] = k;
	edgeArray[11] = l;
	edgeArray[12] = m;
	edgeArray[13] = n;
	edgeArray[14] = o;
	edgeArray[15] = p;
	edgeArray[16] = q;
	edgeArray[17] = r;
	int sizeOfEdgeArray = 18;

	//angle variable to rotate the cube.
	rotAng = 0.0f;

	//assign pointers to arrays
	Vertex * vertexArrayPtr;
	vertexArrayPtr = vertexArray;
	Face * faceArrayPtr;
	faceArrayPtr = faceArray;
	Edge * edgeArrayPtr;
	edgeArrayPtr = edgeArray;

	GeometryOps gOps = GeometryOps();

	//MAKE NEW FACE EDGE VERTEX STRUCTURE¬!"!!!!!
	//ok here we go..
	QFace newFaceArray[50];// this is bad will link lists fix this?! faces will always be 4*more
	Edge newEdgeArray[50]; //
	Vertex newVertexArray[50];
	Vertex *newVertexArrayPtr = newVertexArray;


	int totalNewVerts = 0;
	int totalNewEdges = 0;
	int totalNewFaces = 0;
	for (int i=0; i<sizeOfFaceArray; i++)
	{
		Vertex facep;
		facep = faceArrayPtr[i].getCentroid();
		newVertexArray[totalNewVerts] = facep;
		totalNewVerts++;

		Vertex edgePointA = Vertex(1.0f,2.0f,3.0f);
		//cout<<"filled?\n";

		//faceArrayPtr[i].getEdgeA()->setEdgePoint(gOps.getEdgePoint(faceArrayPtr[i].getEdgeA(),faceArrayPtr,sizeOfFaceArray));
		edgePointA = faceArrayPtr[i].getEdgeA()->getEdgePoint();
		edgePointA = gOps.getEdgePoint(faceArrayPtr[i].getEdgeA(),faceArrayPtr,sizeOfFaceArray,edgeArrayPtr,sizeOfEdgeArray);
		//cout<<"filled with! " << gOps.vertexToString(edgePointA)<<endl;
		if(!gOps.existsInNewVertexArray(edgePointA,newVertexArrayPtr,50))
		{
			newVertexArray[totalNewVerts] = edgePointA;
			totalNewVerts++;
		}
		//else{cout<<"caught!\n";}
		Vertex edgePointB;
		faceArrayPtr[i].getEdgeB()->setEdgePoint(gOps.getEdgePoint(faceArrayPtr[i].getEdgeB(),faceArrayPtr,sizeOfFaceArray,edgeArrayPtr,sizeOfEdgeArray));
		edgePointB = faceArrayPtr[i].getEdgeB()->getEdgePoint();
		//edgePointB = gOps.getEdgePoint(faceArrayPtr[i].getEdgeB(),faceArrayPtr,sizeOfFaceArray);
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
		 Vertex newV1 = gOps.generateNewVertexPoint(faceArrayPtr[i].getEdgeA()->getVertexA(),faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);
		 if(!gOps.existsInNewVertexArray(newV1,newVertexArrayPtr,50))
		 {
			 newVertexArray[totalNewVerts] = newV1;
			 totalNewVerts++;
		 }
		 Vertex newV2 = gOps.generateNewVertexPoint(faceArrayPtr[i].getEdgeA()->getVertexB(),faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);
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
	}

	cout << "Yay! total new Faces = " << totalNewFaces <<endl;
	cout << "Yay! total new Edges = " << totalNewEdges <<endl;
	cout << "Yay! total new Verts = " << totalNewVerts <<endl;
	//cout << "face 1 attempt "<< newFaceArray[0].getEdgeA().getVertexA()->getX() <<endl;


	for (int i =0; i<totalNewVerts; i++)
	{
		cout<< "New Shapes Vertex "<< i <<" "<< gOps.vertexToString(newVertexArray[i]) <<endl;

	}

	cout <<"\n"<<endl;

	for (int i = 0; i<12; i++)
	{
		cout << "***Face " << i <<endl;
		cout << " first : " << faceArray[i].getEdgeA()->getVertexA()->getX()<< "::"<< faceArray[i].getEdgeA()->getVertexA()->getY() << "::" <<faceArray[i].getEdgeA()->getVertexA()->getZ()<<endl;
		cout << " second : " << faceArray[i].getEdgeA()->getVertexB()->getX()<< "::"<< faceArray[i].getEdgeA()->getVertexB()->getY() << "::" <<faceArray[i].getEdgeA()->getVertexB()->getZ()<<endl;
		cout << " third : " << faceArray[i].getEdgeB()->getVertexB()->getX()<< "::"<< faceArray[i].getEdgeB()->getVertexB()->getY() << "::" <<faceArray[i].getEdgeB()->getVertexB()->getZ()<<endl;
	}

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

		for(int i = 0; i<12;i++)
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

				/*//works
				glVertex3f(0.5f,0.5f,-0.5f);
				glVertex3f(-0.5f,0.5f,-0.5f);
				glVertex3f(-0.5f,0.5f,-0.5f);

				//***Face 1
				glVertex3f(-0.5f,0.5f,-0.5f);
				glVertex3f(-0.5f,0.5f,0.5f);
				glVertex3f(0.5f,0.5f,0.5f);
				//***Face 2
				glVertex3f(0.5f,-0.5f,0.5f);
				glVertex3f(-0.5f,0.5f,0.5f);
				glVertex3f(0.5f,0.5f,0.5f);
				//***Face 3
				glVertex3f(0.5f,0.5f,0.5f);
				glVertex3f(-0.5f,-0.5f,0.5f);
				glVertex3f(0.5f,-0.5f,0.5f);
				//***Face 4
				glVertex3f(-0.5f,-0.5f,0.5f);
				glVertex3f(-0.5f,-0.5f,-0.5f);
				glVertex3f(0.5f,-0.5f,0.5f);
				//***Face 5
				glVertex3f(-0.5f,-0.5f,-0.5f);
				glVertex3f(0.5f,-0.5f,0.5f);
				glVertex3f(0.5f,-0.5f,-0.5f);
				//***Face 6
				glVertex3f(-0.5f,-0.5f,-0.5f);
				glVertex3f(0.5f,-0.5f,-0.5f);
				glVertex3f(0.5f,0.5f,-0.5f);
				//***Face 7
				glVertex3f(-0.5f,0.5f,-0.5f);
				glVertex3f(-0.5f,-0.5f,-0.5f);
				glVertex3f(0.5f,0.5f,-0.5f);
				//***Face 8
				glVertex3f(-0.5f,0.5f,-0.5f);
				glVertex3f(-0.5f,0.5f,0.5f);
				glVertex3f( -0.5f,-0.5f,-0.5f);
				//***Face 9
				glVertex3f(-0.5f,0.5f,0.5f);
				glVertex3f(-0.5f,-0.5f,-0.5f);
				glVertex3f(-0.5f,-0.5f,-0.5f);
				//***Face 10
				glVertex3f(0.5f,-0.5f,-0.5f);
				glVertex3f(0.5f,0.5f,-0.5f);
				glVertex3f(0.5f,-0.5f,-0.5f);
				//***Face 11
				glVertex3f(0.5f,0.5f,0.5f);
				glVertex3f(0.5f,-0.5f,-0.5f);
				glVertex3f(0.5f,-0.5f,0.5f);*/



				//glVertex3f(faceArray[i].getEdgeA()->getVertexA()->getX(),faceArray[i].getEdgeA()->getVertexA()->getY(),faceArray[i].getEdgeA()->getVertexA()->getZ()); //
				//glVertex3f(faceArray[i].getEdgeA()->getVertexB()->getX(),faceArray[i].getEdgeA()->getVertexB()->getY(),faceArray[i].getEdgeA()->getVertexB()->getZ());
				//glVertex3f(faceArray[i].getEdgeB()->getVertexB()->getX(),faceArray[i].getEdgeB()->getVertexB()->getY(),faceArray[i].getEdgeB()->getVertexB()->getZ());

				//fixed points -Crashes
				//glVertex3f(faceArray[1].getEdgeA()->getVertexA()->getX(),faceArray[1].getEdgeA()->getVertexA()->getY(),faceArray[1].getEdgeA()->getVertexA()->getZ()); //
				//glVertex3f(faceArray[1].getEdgeA()->getVertexB()->getX(),faceArray[1].getEdgeA()->getVertexB()->getY(),faceArray[1].getEdgeA()->getVertexB()->getZ());
				//glVertex3f(faceArray[1].getEdgeB()->getVertexB()->getX(),faceArray[1].getEdgeB()->getVertexB()->getY(),faceArray[1].getEdgeB()->getVertexB()->getZ());

				// no Z's
				glVertex3f(0.0f,1.0f,0.0f); //
				glVertex3f(faceArray[1].getEdgeA()->getVertexB()->getX(),faceArray[1].getEdgeA()->getVertexB()->getY(),0.0f);
				glVertex3f(faceArray[1].getEdgeB()->getVertexB()->getX(),faceArray[1].getEdgeB()->getVertexB()->getY(),0.0f);


				glEnd();
			}
		//cout << "one draw?\n";
		rotAng += 0.2;
}
