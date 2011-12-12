/*
 * Butterfly.cpp
 *
 *  Created on: 11 Dec 2011
 *      Author: mikey
 */


#include "Butterfly.h"
#include <iostream>
using namespace std;

Butterfly::Butterfly() {
	// TODO Auto-generated constructor stub

}
Butterfly::Butterfly(int v, int e, int f, Vertex *ova, Edge *oea, Face *ofa)
{

	GeometryOps gOps = GeometryOps();

	for(int i=0; i<e; i++)
	{
		cout << "Edge " << i << " toStr is: " << gOps.edgeToString(oea[i])<<"\n";
	}
	cout << "\n";

	getNewEdgePoint(&oea[1],oea,e,ofa,f);

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
		cout << "valance1 = " << valT1.contains <<"\n";
		Vertex t2 = *(edgeToWork->getVertexB());
		GeometryOps::eightEdge valT2 = gOps.getIncidentEdges(&t1,oldEdges,numberOfOldEdges);
		cout << "valance1 = " << valT2.contains <<"\n";
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
		cout << "points t1-t8" << "\n";
		cout << "t1" <<gOps.vertexToString(t1) << "\n";
		cout << "t2" <<gOps.vertexToString(t2) << "\n";
		cout << "t3" <<gOps.vertexToString(t3) << "\n";
		cout << "t4" <<gOps.vertexToString(t4) << "\n";
		cout << "t5" <<gOps.vertexToString(t5) << "\n";
		cout << "t6" <<gOps.vertexToString(t6) << "\n";
		cout << "t7" <<gOps.vertexToString(t7) << "\n";
		cout << "t8" <<gOps.vertexToString(t8) << "\n";

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
		cout << "resultv : " << gOps.vertexToString(resultv) << "\n\n";
		return resultv;
}
