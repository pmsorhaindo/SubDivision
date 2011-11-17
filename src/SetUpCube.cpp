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

	Vertex v1 = Vertex(-0.5f,-0.5f,0.5f);//Front anti clock wise bottom left to top left
	Vertex v2 = Vertex(0.5f,-0.5f,0.5f);
	Vertex v3 = Vertex(0.5f,0.5f,0.5f);
	Vertex v4 = Vertex(-0.5f,0.5f,0.5f);
	Vertex v5 = Vertex(-0.5f,-0.5f,-0.5f);//Back anti clockwise From bottom left to top left
	Vertex v6 = Vertex(0.5f,-0.5f,-0.5f);
	Vertex v7 = Vertex(0.5f,0.5f,-0.5f);
	Vertex v8 = Vertex(-0.5f,0.5f,-0.5f);

	Edge a = Edge(v4,v3); //top front
	Edge b = Edge(v3,v7); //top right
	Edge c = Edge(v7,v8); //top back
	Edge d = Edge(v8,v4); //top left
	Edge e = Edge(v3,v8); //top middle
	Edge f = Edge(v2,v3); //front right
	Edge g = Edge(v1,v2); // front bottom
	Edge h = Edge(v1,v4); //front left
	Edge i = Edge(v3,v1); // front middle
	Edge j = Edge(v1,v5); //bottom left
	Edge k = Edge(v6,v2); //bottom right
	Edge l = Edge(v5,v6); //bottom back
	Edge m = Edge(v5,v2); // bottom middle
	Edge n = Edge(v8,v5); // back left
	Edge o = Edge(v6,v7); // back right
	Edge p = Edge(v5,v7); // back middle
	Edge q = Edge(v4,v5); // left middle
	Edge r = Edge(v3,v6); // right middle

	//surface -> face
	Face one = Face(c,reverseEdge(e),b); //top back g
	Face two = Face(d,a,e); //top front g
	Face three = Face(h,a,i); // front top g
	Face four = Face(i,g,f); //front bottom g
	Face five = Face(j,m,reverseEdge(g)); // bottom front g
	Face six = Face(reverseEdge(m),l,k); //bottom back g
	Face seven = Face(l,o,reverseEdge(p)); // back bottom g
	Face eight = Face(n,p,c); //Back top
	Face nine = Face(reverseEdge(d),n,reverseEdge(q)); // left top
	Face ten = Face(q,reverseEdge(j),h); //left bottom
	Face eleven = Face(reverseEdge(o),reverseEdge(r),b); // right top
	Face twelve = Face(r,k,f); // right bottom

	a.setJoinsFace(&two,&three);
	b.setJoinsFace(&two,&eleven);
	c.setJoinsFace(&one,&eight);
	d.setJoinsFace(&one,&nine);
	e.setJoinsFace(&one,&two);
	f.setJoinsFace(&four,&twelve);
	g.setJoinsFace(&four,&five);
	h.setJoinsFace(&three,&ten);
	i.setJoinsFace(&three,&four);
	j.setJoinsFace(&five,&ten);
	k.setJoinsFace(&six,&twelve);
	l.setJoinsFace(&six,&seven);
	m.setJoinsFace(&five,&six);
	n.setJoinsFace(&eight,&nine);
	o.setJoinsFace(&seven,&eleven);
	p.setJoinsFace(&seven,&eight);
	q.setJoinsFace(&nine,&ten);
	r.setJoinsFace(&eleven,&twelve);

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

	for(int i=0; i<sizeOfVertexArray; i++)
	{
		cout << "The vertex point for v" <<i <<" is: "<< gOps.vertexToString(gOps.generateNewVertexPoint(vertexArrayPtr[i],faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray))  << std::endl;
	}

	//MAKE NEW FACE EDGE VERTEX STRUCTURE¬!"!!!!!
	//ok here we go..

	QFace newFaceArray[500];// this is bad will link lists fix this?! faces will always be 4*more
	Edge newEdgeArray[500]; //
	Vertex newVertexArray[500];
	Vertex *newVertexArrayPtr = newVertexArray;

	//Look! all the new Vertices in a point cloud :D
	/**
	int totalNewVerts = 0;
	for (int i=0; i<sizeOfVertexArray; i++)
	{
		newVertexArray[totalNewVerts] = gOps.generateNewVertexPoint(vertexArrayPtr[i],faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);
		totalNewVerts++;
	}

	for (int i=0; i<sizeOfVertexArray; i++)
	{
		newVertexArray[totalNewVerts] = gOps.getEdgePoint(edgeArrayPtr[i],faceArrayPtr,sizeOfFaceArray);
		totalNewVerts++;
	}

	for (int i=0; i<sizeOfVertexArray; i++)
	{
		newVertexArray[totalNewVerts] = faceArrayPtr[i].getCentroid();
		totalNewVerts++;
	} **/

	/**SOLUTION?
	For each face
	Take two edges
	take their edge points for point on newFace
	and the new Vertex for the 4th point on the face
	addToVertex Array if not existing in VertexArray
	Repeat twice (3x more on next iteratations) more for the next two Pair of edges on the face.
	Repeat for all faces.**/

	int totalNewVerts = 0;
	int totalNewEdges = 0;
	int totalNewFaces = 0;
	for (int i=0; i<sizeOfFaceArray; i++)
	{
		//cin.get();
		Vertex temp1;
		GeometryOps::fourExistVert tempQuad;
		tempQuad.vertOne = faceArrayPtr[i].getCentroid();
		faceArrayPtr[i].getEdgeA();
		tempQuad.vertTwo = gOps.getEdgePoint(faceArrayPtr[i].getEdgeA(),faceArrayPtr,sizeOfFaceArray);
		faceArrayPtr[i].getEdgeB();
		tempQuad.vertThree = gOps.getEdgePoint(faceArrayPtr[i].getEdgeB(),faceArrayPtr,sizeOfFaceArray);
		if(gOps.twoEdgesIsCommonVertex(faceArrayPtr[i].getEdgeA(),faceArrayPtr[i].getEdgeB()))
			temp1 = gOps.twoEdgesGetCommonVertex(faceArrayPtr[i].getEdgeA(),faceArrayPtr[i].getEdgeB());
		tempQuad.vertFour = gOps.generateNewVertexPoint(temp1,faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);

		if(gOps.existsInNewVertexArray(tempQuad.vertOne,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
			cout << "Tried to Add vertex: " << gOps.vertexToString(tempQuad.vertOne)<<endl;

		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad.vertOne;
			totalNewVerts ++;
			cout << "Added vertex: " << gOps.vertexToString(tempQuad.vertOne)<<endl;
			cout << "Vertex stored as: " << gOps.vertexToString(newVertexArray[totalNewVerts]) <<endl;
		}

		if(gOps.existsInNewVertexArray(tempQuad.vertTwo,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad.vertTwo;
			totalNewVerts ++;
		}

		if(gOps.existsInNewVertexArray(tempQuad.vertThree,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad.vertThree;
			totalNewVerts ++;
		}
		if(gOps.existsInNewVertexArray(tempQuad.vertFour,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad.vertFour;
			totalNewVerts ++;
		}
		//TODO move to a NEW function in gOPs?
		// This needs to be repeated for each temp Quad and then again for edges.
		GeometryOps::eightEdge tempEdges;
		tempEdges.edgeOne = Edge(tempQuad.vertTwo,tempQuad.vertFour);
		tempEdges.edgeTwo = Edge(tempQuad.vertFour,tempQuad.vertThree);
		tempEdges.edgeThree = Edge(tempQuad.vertThree,tempQuad.vertOne);
		tempEdges.edgeFour = Edge(tempQuad.vertOne,tempQuad.vertTwo);

		QFace newQuad = QFace(tempEdges.edgeOne,tempEdges.edgeTwo,tempEdges.edgeThree,tempEdges.edgeFour);
		newFaceArray[totalNewFaces] = newQuad;
		totalNewFaces++;
		//useExistsInNewVertex Array before Adding
		/**for (int j =0; j<totalNewVerts; j++)
			{
				cout<< "New Shapes Vertex "<< j <<" "<< gOps.vertexToString(newVertexArray[j]) <<endl;
			}**/

		//cin.get();
		Vertex temp2;
		GeometryOps::fourExistVert tempQuad2;
		tempQuad2.vertOne = faceArrayPtr[i].getCentroid();
		faceArrayPtr[i].getEdgeA();
		tempQuad2.vertTwo = gOps.getEdgePoint(faceArrayPtr[i].getEdgeA(),faceArrayPtr,sizeOfFaceArray);
		faceArrayPtr[i].getEdgeB();
		tempQuad2.vertThree = gOps.getEdgePoint(faceArrayPtr[i].getEdgeB(),faceArrayPtr,sizeOfFaceArray);
		if(gOps.twoEdgesIsCommonVertex(faceArrayPtr[i].getEdgeA(),faceArrayPtr[i].getEdgeB()))
			temp2 = gOps.twoEdgesGetCommonVertex(faceArrayPtr[i].getEdgeA(),faceArrayPtr[i].getEdgeB());
		tempQuad2.vertFour = gOps.generateNewVertexPoint(temp2,faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);


		if(gOps.existsInNewVertexArray(tempQuad2.vertOne,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
			cout << "Tried to Add vertex: " << gOps.vertexToString(tempQuad2.vertOne)<<endl;
			cout << "Vertex stored as: " << gOps.vertexToString(newVertexArray[totalNewVerts]) <<endl;;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad2.vertOne;
			totalNewVerts ++;
		}

		if(gOps.existsInNewVertexArray(tempQuad2.vertTwo,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad2.vertTwo;
			totalNewVerts ++;
		}

		if(gOps.existsInNewVertexArray(tempQuad2.vertThree,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad2.vertThree;
			totalNewVerts ++;
		}
		if(gOps.existsInNewVertexArray(tempQuad2.vertFour,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad2.vertFour;
			totalNewVerts ++;
		}

		GeometryOps::eightEdge tempEdges2;
		tempEdges2.edgeOne = Edge(tempQuad2.vertTwo,tempQuad2.vertFour);
		tempEdges2.edgeTwo = Edge(tempQuad2.vertFour,tempQuad2.vertThree);
		tempEdges2.edgeThree = Edge(tempQuad2.vertThree,tempQuad2.vertOne);
		tempEdges2.edgeFour = Edge(tempQuad2.vertOne,tempQuad2.vertTwo);

		QFace newQuad2 = QFace(tempEdges2.edgeOne,tempEdges2.edgeTwo,tempEdges2.edgeThree,tempEdges2.edgeFour);
		newFaceArray[totalNewFaces] = newQuad2;
		totalNewFaces++;
		//useExistsInNewVertex Array before Adding
		/**for (int j =0; j<totalNewVerts; j++)
			{
				cout<< "New Shapes Vertex "<< j <<" "<< gOps.vertexToString(newVertexArray[j]) <<endl;
			}**/


		//cin.get();
		Vertex temp3;
		GeometryOps::fourExistVert tempQuad3;
		tempQuad3.vertOne = faceArrayPtr[i].getCentroid();
		faceArrayPtr[i].getEdgeA();
		tempQuad3.vertTwo = gOps.getEdgePoint(faceArrayPtr[i].getEdgeA(),faceArrayPtr,sizeOfFaceArray);
		faceArrayPtr[i].getEdgeB();
		tempQuad3.vertThree = gOps.getEdgePoint(faceArrayPtr[i].getEdgeB(),faceArrayPtr,sizeOfFaceArray);
		if(gOps.twoEdgesIsCommonVertex(faceArrayPtr[i].getEdgeA(),faceArrayPtr[i].getEdgeB()))
			temp3 = gOps.twoEdgesGetCommonVertex(faceArrayPtr[i].getEdgeA(),faceArrayPtr[i].getEdgeB());
		tempQuad3.vertFour = gOps.generateNewVertexPoint(temp3,faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray);


		if(gOps.existsInNewVertexArray(tempQuad3.vertOne,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
			cout << "Tried to Add vertex: " << gOps.vertexToString(tempQuad3.vertOne)<<endl;
			cout << "Vertex stored as: " << gOps.vertexToString(newVertexArray[totalNewVerts]) <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad3.vertOne;
			totalNewVerts ++;
		}

		if(gOps.existsInNewVertexArray(tempQuad3.vertTwo,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad3.vertTwo;
			totalNewVerts ++;
		}

		if(gOps.existsInNewVertexArray(tempQuad3.vertThree,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad3.vertThree;
			totalNewVerts ++;
		}
		if(gOps.existsInNewVertexArray(tempQuad3.vertFour,newVertexArrayPtr,totalNewVerts))
		{
			cout<<"caught a double!" <<endl;
		}
		else
		{
			newVertexArray[totalNewVerts] = tempQuad3.vertFour;
			totalNewVerts ++;
		}


		GeometryOps::eightEdge tempEdges3;
		tempEdges3.edgeOne = Edge(tempQuad3.vertTwo,tempQuad3.vertFour);
		tempEdges3.edgeTwo = Edge(tempQuad3.vertFour,tempQuad3.vertThree);
		tempEdges3.edgeThree = Edge(tempQuad3.vertThree,tempQuad3.vertOne);
		tempEdges3.edgeFour = Edge(tempQuad3.vertOne,tempQuad3.vertTwo);

		QFace newQuad3 = QFace(tempEdges3.edgeOne,tempEdges3.edgeTwo,tempEdges3.edgeThree,tempEdges3.edgeFour);
		newFaceArray[totalNewFaces] = newQuad3;
		totalNewFaces++;
		//useExistsInNewVertex Array before Adding
		/**for (int j =0; j<totalNewVerts; j++)
			{
				cout<< "New Shapes Vertex "<< j <<" "<< gOps.vertexToString(newVertexArray[j]) <<endl;
			}**/
		//cin.get();

	}
	cout << "Yay total new Faces = " << totalNewFaces <<endl;
	cout << "Yay total new Verts = " << totalNewVerts <<endl;
	cout << "face 1 attempt "<< newFaceArray[0].getEdgeA().getVertexA().getX() <<endl;

	/**for (int i =0; i<totalNewVerts; i++)
	{
		cout<< "New Shapes Vertex "<< i <<" "<< gOps.vertexToString(newVertexArray[i]) <<endl;
	}**/

}

SetUpCube::~SetUpCube() {
	// TODO Auto-generated destructor stub
}

Edge SetUpCube::reverseEdge(Edge reversing){
	Edge tempEdge = Edge(reversing.getVertexB(),reversing.getVertexA());
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

				glVertex3f(faceArray[i].getEdgeA().getVertexA().getX(),faceArray[i].getEdgeA().getVertexA().getY(),faceArray[i].getEdgeA().getVertexA().getZ()); //
				glVertex3f(faceArray[i].getEdgeA().getVertexB().getX(),faceArray[i].getEdgeA().getVertexB().getY(),faceArray[i].getEdgeA().getVertexB().getZ());
				glVertex3f(faceArray[i].getEdgeB().getVertexB().getX(),faceArray[i].getEdgeB().getVertexB().getY(),faceArray[i].getEdgeB().getVertexB().getZ());

				glEnd();
			}
		rotAng += 0.2;
}
