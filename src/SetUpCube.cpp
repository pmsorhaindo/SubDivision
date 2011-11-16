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
	GeometryOps::twoFace twoFaceStorage;
	GeometryOps::sixFace sixFaceStorage;
	GeometryOps::eightEdge eightEdgeStorage;

	/**
	//Looped!!
	for(int i=0; i<sizeOfEdgeArray; i++)
	{
		cout << "For face " <<i <<" the edge Midpoint is x: "<< edgeArray[i].getEdgeMidPoint().getX() << " y: " << edgeArray[i].getEdgeMidPoint().getY() << " z: " << edgeArray[1].getEdgeMidPoint().getZ() <<endl;
		float aq = (edgeArray[i].getVertexA().getX()+edgeArray[i].getVertexB().getX()+edgeArray[i].getFacesJoined1()->getCentroid().getX()+edgeArray[i].getFacesJoined2()->getCentroid().getX())/4.0f;
		float aw = (edgeArray[i].getVertexA().getY()+edgeArray[i].getVertexB().getY()+edgeArray[i].getFacesJoined1()->getCentroid().getY()+edgeArray[i].getFacesJoined2()->getCentroid().getY())/4.0f;
		float ae = (edgeArray[i].getVertexA().getZ()+edgeArray[i].getVertexB().getZ()+edgeArray[i].getFacesJoined1()->getCentroid().getZ()+edgeArray[i].getFacesJoined2()->getCentroid().getZ())/4.0f;
		Vertex edgeV = Vertex(aq,aw,ae);
		std::cout << i<<"'s Edge point is - X: " << edgeV.getX() << " Y: " << edgeV.getY() << " Z: " << edgeV.getZ() << std::endl;
	}

	//edgpoint
	float aq = (a.getVertexA().getX()+a.getVertexB().getX()+a.getFacesJoined1()->getCentroid().getX()+a.getFacesJoined2()->getCentroid().getX())/4.0f;
	float aw = (a.getVertexA().getY()+a.getVertexB().getY()+a.getFacesJoined1()->getCentroid().getY()+a.getFacesJoined2()->getCentroid().getY())/4.0f;
	float ae = (a.getVertexA().getZ()+a.getVertexB().getZ()+a.getFacesJoined1()->getCentroid().getZ()+a.getFacesJoined2()->getCentroid().getZ())/4.0f;
	Vertex edgeV = Vertex(aq,aw,ae);

	std::cout << "A's edge point is - X: " << edgeV.getX() << " Y: " << edgeV.getY() << " Z: " << edgeV.getZ() << std::endl;
	cout << "a Vertex A: " << a.getVertexA().getX() << ":" << a.getVertexA().getY() << ":" << a.getVertexA().getZ() << endl;
	cout << "a Vertex B: " << b.getVertexB().getX() << ":" << b.getVertexB().getY() << ":" << a.getVertexB().getZ() << endl;
	cout << "a face1 centroid: " << a.getFacesJoined1()->getCentroid().getX()<<" : "<<a.getFacesJoined1()->getCentroid().getY()<<" : "<<a.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face2 centroid: " << a.getFacesJoined2()->getCentroid().getX()<<" : "<<a.getFacesJoined2()->getCentroid().getY()<<" : "<<a.getFacesJoined2()->getCentroid().getZ()<<endl;
	cout << "centroid 1 composed of" << a.getFacesJoined1()->getEdgeA().getVertexA().getX() << ":"<<a.getFacesJoined1()->getEdgeA().getVertexA().getY()<<":" << a.getFacesJoined1()->getEdgeA().getVertexA().getX()<<endl;
	cout << "\t\t "<< a.getFacesJoined1()->getEdgeA().getVertexB().getX() << ":"<< a.getFacesJoined1()->getEdgeA().getVertexB().getY() << ":" << a.getFacesJoined1()->getEdgeA().getVertexB().getZ() << endl;
	cout << "\t\t "<< a.getFacesJoined1()->getEdgeB().getVertexB().getX() <<":"<<a.getFacesJoined1()->getEdgeB().getVertexB().getY()<<":"<<a.getFacesJoined1()->getEdgeB().getVertexB().getZ()<<endl;
	cout <<""<<endl;
	cout << "centroid 2 composed of" << a.getFacesJoined2()->getEdgeA().getVertexA().getX() << ":"<<a.getFacesJoined2()->getEdgeA().getVertexA().getY()<<":" << a.getFacesJoined2()->getEdgeA().getVertexA().getX()<<endl;
	cout << "\t\t "<< a.getFacesJoined2()->getEdgeA().getVertexB().getX() << ":"<< a.getFacesJoined2()->getEdgeA().getVertexB().getY() << ":" << a.getFacesJoined2()->getEdgeA().getVertexB().getZ() << endl;
	cout << "\t\t "<< a.getFacesJoined2()->getEdgeB().getVertexB().getX() <<":"<<a.getFacesJoined2()->getEdgeB().getVertexB().getY()<<":"<<a.getFacesJoined2()->getEdgeB().getVertexB().getZ()<<endl;
	cout <<""<<endl;
	cout <<""<<endl;
	cout <<"some more centroids" <<endl;
	cout << "a face1 centroid: " << a.getFacesJoined1()->getCentroid().getX()<<" : "<<a.getFacesJoined1()->getCentroid().getY()<<" : "<<a.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << a.getFacesJoined2()->getCentroid().getX()<<" : "<<a.getFacesJoined2()->getCentroid().getY()<<" : "<<a.getFacesJoined2()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << c.getFacesJoined1()->getCentroid().getX()<<" : "<<c.getFacesJoined1()->getCentroid().getY()<<" : "<<c.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << d.getFacesJoined1()->getCentroid().getX()<<" : "<<d.getFacesJoined1()->getCentroid().getY()<<" : "<<d.getFacesJoined1()->getCentroid().getZ()<<endl;
	cout << "a face1 centroid: " << e.getFacesJoined1()->getCentroid().getX()<<" : "<<e.getFacesJoined1()->getCentroid().getY()<<" : "<<e.getFacesJoined1()->getCentroid().getZ()<<endl;

	cout << ">>> Geometry Ops Class Testing! <<<" <<endl;
	cout << "" <<endl;
	cout << "Compare Vertexes"<<endl;
	cout << "compareVertices(v1,v1) = " << gOps.compareVertices(v1,v1) <<endl;
	cout << "compareVertices(v1,v2) = " << gOps.compareVertices(v1,v2) <<endl;
	cout << "compareVertices(v2,v2) = " << gOps.compareVertices(v2,v2) <<endl;
	cout << "compareVertices(v2,v3) = " << gOps.compareVertices(v2,v3) <<endl;
	cout << "compareVertices(v3,v3) = " << gOps.compareVertices(v3,v3) <<endl;
	cout << "" <<endl;
	cout << "Get Centroid"<<endl;
	cout << "getCentroid() = " << gOps.compareVertices(v1,v2) <<endl;
	cout << "getCentroid(v2,v2) = " << gOps.compareVertices(v2,v2) <<endl;
	cout << "getCentroid(v2,v3) = " << gOps.compareVertices(v2,v3) <<endl;
	cout << "getCentroid(v3,v3) = " << gOps.compareVertices(v3,v3) <<endl;
	cout << "" <<endl;
	cout << "Compare Edges"<<endl;
	cout << "compareEdges(a,a) "<<gOps.compareEdges(a,a)<<endl;
	cout << "compareEdges(b,a) "<<gOps.compareEdges(b,a)<<endl;
	cout << "compareEdges(b,b) "<<gOps.compareEdges(b,b)<<endl;
	cout << "compareEdges(b,c) "<<gOps.compareEdges(b,c)<<endl;
	cout << "" <<endl;
	cout << "getOtherFace"<<endl;
	twoFaceStorage = gOps.getOtherFace(a,faceArrayPtr,sizeOfFaceArray);
	cout << "getOtherFace(a,faceArrayPtr,sizeOfFaceArray) " <<gOps.printUniqueVertices(twoFaceStorage.faceOne)<<endl;
	cout << "getOtherFace(a,faceArrayPtr,sizeOfFaceArray) " <<gOps.printUniqueVertices(twoFaceStorage.faceTwo)<<endl;
	cout << "" <<endl;
	cout << "Vertex Overloading"<<endl;
	cout << "v1 + v1 " <<gOps.vertexToString((v1+v1))<<endl;
	cout << "v1 + v2 " <<gOps.vertexToString((v1+v2))<<endl;
	cout << "v2 + v2 " <<gOps.vertexToString((v2+v2))<<endl;
	cout << "" <<endl;
	cout << "Edge Points"<<endl;
	cout << "edge point of a: " << gOps.vertexToString(gOps.getEdgePoint(a,faceArrayPtr,sizeOfFaceArray))<<endl;
	cout << "edge point of b: " << gOps.vertexToString(gOps.getEdgePoint(b,faceArrayPtr,sizeOfFaceArray))<<endl;
	cout << "edge point of c: " << gOps.vertexToString(gOps.getEdgePoint(c,faceArrayPtr,sizeOfFaceArray))<<endl;
	cout << "" <<endl;
	cout << "Face Contains Points"<<endl;
	cout << "Face one contains Vertex 3: " << gOps.faceContainsVertex(one,v3)<<endl;
	cout << "Face eight does not contain Vertex 6: " << gOps.faceContainsVertex(eight,v6)<<endl;
	cout << "Face four contains Vertex 1: " << gOps.faceContainsVertex(four,v1)<<endl;
	cout << "" <<endl;
	cout << "Get Adjacent Faces" <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v1,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex one: " << sixFaceStorage.contains <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v2,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex two: " << sixFaceStorage.contains <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v3,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex three: " << sixFaceStorage.contains <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v4,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex four: " << sixFaceStorage.contains <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v5,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex five: " << sixFaceStorage.contains <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v6,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex six: " << sixFaceStorage.contains <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v7,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex seven: " << sixFaceStorage.contains <<endl;
	sixFaceStorage = gOps.getAdjacentFaces(v8,faceArrayPtr,sizeOfFaceArray);
	cout << "Adjacent Faces to Vertex eight: " << sixFaceStorage.contains <<endl;
	cout << "" <<endl;
	cout << "Get Q" <<endl;
	cout << "The Q for Vertex 1 is: " << gOps.vertexToString(gOps.getQ(v1,faceArrayPtr,sizeOfFaceArray)) <<endl;
	cout << "The Q for Vertex 2 is: " << gOps.vertexToString(gOps.getQ(v2,faceArrayPtr,sizeOfFaceArray)) <<endl;
	cout << "The Q for Vertex 3 is: " << gOps.vertexToString(gOps.getQ(v3,faceArrayPtr,sizeOfFaceArray)) <<endl;
	cout << "" <<endl;
	cout << "Get Incident Edges" <<endl;
	eightEdgeStorage = gOps.getIncidentEdges(v1,edgeArrayPtr,sizeOfEdgeArray);
	cout << "The number of edges incident on v1 are: " << eightEdgeStorage.contains <<endl;
	eightEdgeStorage = gOps.getIncidentEdges(v2,edgeArrayPtr,sizeOfEdgeArray);
	cout << "The number of edges incident on v2 are: " << eightEdgeStorage.contains <<endl;
	eightEdgeStorage = gOps.getIncidentEdges(v3,edgeArrayPtr,sizeOfEdgeArray);
	cout << "The number of edges incident on v3 are: " << eightEdgeStorage.contains <<endl;
	eightEdgeStorage = gOps.getIncidentEdges(v4,edgeArrayPtr,sizeOfEdgeArray);
	cout << "The number of edges incident on v4 are: " << eightEdgeStorage.contains <<endl;
	cout << "" <<endl;
	cout << "Get 2R" <<endl;
	cout << "The 2R for Vertex 1 is: " << gOps.vertexToString(gOps.get2R(v1,edgeArrayPtr,sizeOfEdgeArray)) <<endl;
	cout << "The 2R for Vertex 2 is: " << gOps.vertexToString(gOps.get2R(v2,edgeArrayPtr,sizeOfEdgeArray)) <<endl;
	cout << "The 2R for Vertex 3 is: " << gOps.vertexToString(gOps.get2R(v3,edgeArrayPtr,sizeOfEdgeArray)) <<endl;
	cout << "" <<endl;
	cout << "Get SandStuff" <<endl;
	cout << "The sAndStuff for Vertex 1 is: " << gOps.vertexToString(gOps.getSandStuff(v1,edgeArrayPtr,sizeOfEdgeArray)) <<endl;
	cout << "The sAndStuff for Vertex 2 is: " << gOps.vertexToString(gOps.getSandStuff(v2,edgeArrayPtr,sizeOfEdgeArray)) <<endl;
	cout << "The sAndStuff for Vertex 3 is: " << gOps.vertexToString(gOps.getSandStuff(v3,edgeArrayPtr,sizeOfEdgeArray)) <<endl;
	cout << "" <<endl;
	**/

	//cout << "OMG new Vertex Point NO WAI!!" <<endl;
	//cout << "The first NEW Vertex generated from original Vertex 1 is: " << gOps.vertexToString(gOps.generateNewVertexPoint(v1,faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray)) <<endl;

	for(int i=0; i<sizeOfVertexArray; i++)
		{
			cout << "The vertex point for v" <<i <<" is: "<< gOps.vertexToString(gOps.generateNewVertexPoint(vertexArrayPtr[i],faceArrayPtr,edgeArrayPtr,sizeOfFaceArray,sizeOfEdgeArray))  << std::endl;
		}

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
