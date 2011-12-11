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
		//Run for all faces
		//run the the function for for each edge on a face and stitch up and create new Faces
		//Functionize to take an edge and do this to it
		Vertex t1 = *(oea[i].getVertexA());
		Vertex t2 = *(oea[i].getVertexB());
		GeometryOps::twoFace firstFaces = gOps.getOtherFace(oea[i],ofa,f);
		Vertex t3 = gOps.thirdPointInFace(t1,t2,firstFaces.faceOne);
		Vertex t4 = gOps.thirdPointInFace(t1,t2,firstFaces.faceTwo);

		Vertex t5 = gOps.getWings(t1,t3,ofa,f,t2);
		Vertex t6 = gOps.getWings(t1,t4,ofa,f,t2);
		Vertex t7 = gOps.getWings(t2,t3,ofa,f,t1);
		Vertex t8 = gOps.getWings(t2,t4,ofa,f,t1);

		//weightings
		t1.div(0.5f);
		t2.div(0.5f);
		t3.div(0.125f);
		t4.div(0.125f);
		t5.div(-0.0625f);
		t6.div(-0.0625f);
		t7.div(-0.0625f);
		t8.div(-0.0625f);
		Vertex resultv = t1+t2+t3+t4+t5+t6+t7+t8;
		resultv.div(8.0f);
		cout << "resultv : " << gOps.vertexToString(resultv) << "\n";
	}
}

Butterfly::~Butterfly() {
	// TODO Auto-generated destructor stub
}
