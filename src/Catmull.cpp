/*
 * Catmull.cpp
 *
 *  Created on: 9 Nov 2011
 *      Author: mikey
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Catmull.h"

using namespace std;
Catmull::Catmull() {
	// TODO Auto-generated constructor stub

}

Catmull::Catmull(int v, int e, int f, Vertex *ova, Edge *oea, Face *ofa){
	//TODO split The Stich up Process
	faceArray = new QFace[f*3];
	edgeArray = new Edge[e*10];
	vertexArray = new Vertex[v*10];
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

	//assign pointers to arrays
	//Vertex * vertexArrayPtr;
	vertexArrayPtr = vertexArray;
	//Face * faceArrayPtr;
	faceArrayPtr = faceArray;
	//Edge * edgeArrayPtr;
	edgeArrayPtr = edgeArray;
	rotAng = 0.0f;

	/*
	 *VERIFIED
	 */cout << "Size of old Edge Array = " <<sizeOfOldEdgeArray <<"\n"; // size of Old edge Array was wrong hardcoded 12 ;/

	/*for (int i=0; i<sizeOfOldEdgeArray; i++)
	{
		cout << "Edge " << i << "'s midpoint is: " << gOps.vertexToString(oldEdgeArray[i].getEdgeMidPoint()) << "\n";
	} // Edge midpoints were messed up not dividing by 2 and negating wtf?*/


	/*
	 * VERIFIED
	 *cout << "size of Old Face Array" << sizeOfOldFaceArray << "\n";

	for (int i = 0; i< sizeOfOldFaceArray; i++ )
	{
		cout << "Face " << i << "'s Face point is: " << gOps.vertexToString(oldFaceArray[i].getCentroid())<<"\n";
	}*/

	//cout << "Size of old Edge Array = " <<sizeOfOldEdgeArray <<"\n";

	for (int i=0; i<sizeOfOldEdgeArray; i++)
	{
		Vertex edgpt = gOps.getEdgePoint(&oldEdgeArray[i],oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		cout << "The new edgepoint at " <<  i << " is: " << gOps.vertexToString(edgpt) << "\n";
		//cout << "test" << "\n";
	}

	/*
	 * Vertex Points Q style
	 */
	/*for (int i=0; i<sizeOfOldVertexArray; i++)
	{
		Vertex qPoint = gOps.getQ(oldVertexArray[i],oldFaceArray,sizeOfOldFaceArray);
		cout << "Q at Point "<< i<< " is: " << gOps.vertexToString(qPoint) << "\n";
	}*/
	cout <<endl;
	/*
	 * 2 R's looking good!
	 *
	 * for (int i=0; i<sizeOfOldVertexArray; i++)
	{
		Vertex rPoint = gOps.get2R(oldVertexArray[i],oldEdgeArray,sizeOfOldEdgeArray);
		cout << "2R at Point "<< i<< " is: " << gOps.vertexToString(rPoint) << "\n";
	}*/
	 //cout<<endl;
	/*
	 * S points looking good!
	 * for (int i=0; i<sizeOfOldVertexArray; i++)
	{
		Vertex sPoint = gOps.getSandStuff(oldVertexArray[i],oldEdgeArray,sizeOfOldEdgeArray);
		cout << "S at Point "<< i<< " is: " << gOps.vertexToString(sPoint) << "\n";
	}*/


	/*cout<<endl;
	for (int i=0; i<sizeOfOldVertexArray; i++)
	{
		Vertex newPoint = gOps.generateNewVertexPoint(&oldVertexArray[i],oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		cout << "New Vertex at Point "<< i<< " is: " << gOps.vertexToString(newPoint) << "\n";
	}*/

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
			cerr << "this shouldn't happen\n";
			cout << "offending Vertex is -> " << gOps.vertexToString(oldFaceArray[i].getCentroid()) << "\n";
			facePointIndex = gOps.whereInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointA;
		edgePointA = gOps.getEdgePoint(oldFaceArray[i].getEdgeA(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(edgePointA) <<"\n";
			vertexArray[sizeOfVertexArray] = edgePointA;
			edgePointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointAIndex = gOps.whereInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray);
			cout << "epa in Index "<< edgePointAIndex << "\n";
		}

		Vertex edgePointB;
		edgePointB = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointB = gOps.getEdgePoint(oldFaceArray[i].getEdgeB(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(edgePointB) <<"\n";
			vertexArray[sizeOfVertexArray] = edgePointB;
			edgePointBIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointBIndex = gOps.whereInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray);
			cout << "epb in Index "<< edgePointBIndex << "\n";
		}

		Vertex edgePointC;
		edgePointC = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointC = gOps.getEdgePoint(oldFaceArray[i].getEdgeC(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(edgePointC) <<"\n";
			vertexArray[sizeOfVertexArray] = edgePointC;
			edgePointCIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointCIndex = gOps.whereInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray);
			cout << "epc in Index "<< edgePointCIndex << "\n";
		}


		Vertex newV1 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV1,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(newV1) <<"\n";
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
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(newV2) <<"\n";
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
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(newV3) <<"\n";
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointC(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointCIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointCIndex = gOps.whereInNewVertexArray(newV3,vertexArrayPtr,sizeOfVertexArray);
		}

		/*cout << "VertexArrayIndex's\n";
		cout << "edgePointAIndex "<< edgePointAIndex <<"\n";
		cout << "edgePointBIndex " << edgePointBIndex <<"\n";
		cout << "edgePointCIndex " << edgePointCIndex << "\n";
		cout << "facePointIndex " << facePointIndex << "\n";
		cout << "newVertPointAIndex " << newVertPointAIndex <<"\n";
		cout << "newVertPointBIndex " << newVertPointBIndex <<"\n";
		cout << "newVertPointCIndex " << newVertPointCIndex <<"\n";
		cout << "\n";*/
		//Edge newV1 ->


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

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false,&edgeArray[newEdgeDIndex],false);
		sizeOfFaceArray++;
		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeEIndex],false,&edgeArray[newEdgeFIndex],false,&edgeArray[newEdgeGIndex],false,&edgeArray[newEdgeHIndex],false);
		sizeOfFaceArray++;
		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeIIndex],false,&edgeArray[newEdgeJIndex],false,&edgeArray[newEdgeKIndex],false,&edgeArray[newEdgeLIndex],false);
		sizeOfFaceArray++;

		//else{cout<<"caught!\n";}
	}

	//cout<< "sizeOfOldFaceArray " << sizeOfOldFaceArray<<endl;
	//GeometryOps::twoFace twoFaceStorage = gOps.getOtherFace(oea[2],ofa,f);
	//cout<< "edge Array test 1: " << gOps.printUniqueVertices(twoFaceStorage.faceOne) <<"\n";
	//cout<< "edge Array test 2: " << gOps.printUniqueVertices(twoFaceStorage.faceTwo) <<"\n";
	cout << "sizeOfVertexArray " << sizeOfVertexArray<<endl;
	cout << "sizeOfEdgeArray " << sizeOfEdgeArray<<endl;
	cout << "sizeOfFaceArray " << sizeOfFaceArray<<endl;
	/*cout <<"x: "<<faceArray[0].getEdgeA()->getVertexA()->getX();
	cout << " y: " << faceArray[0].getEdgeA()->getVertexA()->getY();
	cout << " z: " <<faceArray[0].getEdgeA()->getVertexA()->getZ()<<endl;*/
	//glVertex3f(faceArray[0].getEdgeB()->getVertexA()->getX(),faceArray[0].getEdgeB()->getVertexA()->getY(),faceArray[0].getEdgeB()->getVertexA()->getZ());
	//glVertex3f(faceArray[0].getEdgeC()->getVertexA()->getX(),faceArray[0].getEdgeC()->getVertexA()->getY(),faceArray[0].getEdgeC()->getVertexA()->getZ()); //
	//glVertex3f(faceArray[0].getEdgeD()->getVertexA()->getX(),faceArray[0].getEdgeD()->getVertexA()->getY(),faceArray[0].getEdgeD()->getVertexA()->getZ());

	cout << "\n newVertArray in Catmull\n";
	for (int j=0; j<sizeOfVertexArray; j++)
	{
		cout<< "Vertex " << j << " "<<gOps.vertexToString(vertexArray[j])<<endl;
	}
}


Catmull::Catmull(int v, int e, int f, Vertex *ova, Edge *oea, QFace *ofa){
	//TODO split The Stitch up Process
	cout << "In Paris" <<endl;
	faceArray = new QFace[f*3];
	edgeArray = new Edge[e*8];
	vertexArray = new Vertex[v*10];
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

	cout << "Hello cruel world!\n";

	/*
	 *VERIFIED
	 */cout << "Size of old Edge Array = " <<sizeOfOldEdgeArray <<"\n"; // size of Old edge Array was wrong hardcoded 12 ;/

	/*for (int i=0; i<sizeOfOldEdgeArray; i++)
	{
		cout << "Edge " << i << "'s midpoint is: " << gOps.vertexToString(oldEdgeArray[i].getEdgeMidPoint()) << "\n";
	} // Edge midpoints were messed up not dividing by 2 and negating wtf?*/


	/*
	 * VERIFIED
	 */cout << "size of Old Face Array " << sizeOfOldFaceArray << "\n";

	for (int i = 0; i< sizeOfOldFaceArray; i++ )
	{
		cout << "Face " << i << "'s Face point is: " << gOps.vertexToString(oldFaceArray[i].getCentroid())<<"\n";
	}

	cout << "Size of old Edge Array = " <<sizeOfOldEdgeArray <<"\n";

	for (int i=0; i<sizeOfOldEdgeArray; i++)
	{
		//cout << "edgey!! " <<gOps.vertexToString(*oldEdgeArray[i].getVertexA())<<"\n";
		//cout << "facey!! " <<gOps.vertexToString(*oldFaceArray[i].getEdgeA()->getVertexA())<<"\n";
		Vertex edgpt = gOps.getEdgePoint(&oldEdgeArray[i],oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		//cout << "The new edgepoint at " <<  i << " is: " << gOps.vertexToString(edgpt) << "\n";
		//cout << "test" << "\n";
	}

	cout << "Peanut butter biscuits\n";

	/*cout<<endl;
	for (int i=0; i<sizeOfOldVertexArray; i++)
	{
		Vertex newPoint = gOps.generateNewVertexPoint(&oldVertexArray[i],oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		cout << "New Vertex at Point "<< i<< " is: " << gOps.vertexToString(newPoint) << "\n";
	}*/

	for (int i=0; i<sizeOfOldFaceArray; i++)
	{
		Vertex facep;
		int facePointIndex;
		int newEdgeAIndex,newEdgeBIndex,newEdgeCIndex,newEdgeDIndex,newEdgeEIndex,newEdgeFIndex,newEdgeGIndex,newEdgeHIndex,newEdgeIIndex,newEdgeJIndex,newEdgeKIndex,newEdgeLIndex,newEdgeMIndex,newEdgeNIndex,newEdgeOIndex,newEdgePIndex;
		int edgePointAIndex,edgePointBIndex,edgePointCIndex,edgePointDIndex;
		int newVertPointAIndex, newVertPointBIndex, newVertPointCIndex,newVertPointDIndex;

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
			cerr << "this shouldn't happen\n";
			cout << "offending Vertex is -> " << gOps.vertexToString(oldFaceArray[i].getCentroid()) << "\n";
			facePointIndex = gOps.whereInNewVertexArray(oldFaceArray[i].getCentroid(),vertexArrayPtr,sizeOfVertexArray);
		}

		Vertex edgePointA;
		edgePointA = gOps.getEdgePoint(oldFaceArray[i].getEdgeA(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(edgePointA) <<"\n";
			vertexArray[sizeOfVertexArray] = edgePointA;
			edgePointAIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointAIndex = gOps.whereInNewVertexArray(edgePointA,vertexArrayPtr,sizeOfVertexArray);
			cout << "epa in Index "<< edgePointAIndex << "\n";
		}

		Vertex edgePointB;
		edgePointB = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointB = gOps.getEdgePoint(oldFaceArray[i].getEdgeB(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(edgePointB) <<"\n";
			vertexArray[sizeOfVertexArray] = edgePointB;
			edgePointBIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointBIndex = gOps.whereInNewVertexArray(edgePointB,vertexArrayPtr,sizeOfVertexArray);
			cout << "epb in Index "<< edgePointBIndex << "\n";
		}

		Vertex edgePointC;
		edgePointC = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointC = gOps.getEdgePoint(oldFaceArray[i].getEdgeC(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(edgePointC) <<"\n";
			vertexArray[sizeOfVertexArray] = edgePointC;
			edgePointCIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointCIndex = gOps.whereInNewVertexArray(edgePointC,vertexArrayPtr,sizeOfVertexArray);
			cout << "epc in Index "<< edgePointCIndex << "\n";
		}


		Vertex edgePointD;
		edgePointD = oldFaceArray[i].getEdgeB()->getEdgePoint();
		edgePointD = gOps.getEdgePoint(oldFaceArray[i].getEdgeD(),oldFaceArray,sizeOfOldFaceArray,oldEdgeArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(edgePointD,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(edgePointC) <<"\n";
			vertexArray[sizeOfVertexArray] = edgePointD;
			edgePointDIndex=sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			edgePointDIndex = gOps.whereInNewVertexArray(edgePointD,vertexArrayPtr,sizeOfVertexArray);
			cout << "epd in Index "<< edgePointDIndex << "\n";
		}

		Vertex newV1 = gOps.generateNewVertexPoint(oldFaceArray[i].getPointA(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
		if(!gOps.existsInNewVertexArray(newV1,vertexArrayPtr,sizeOfVertexArray))
		{
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(newV1) <<"\n";
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
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(newV2) <<"\n";
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
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(newV3) <<"\n";
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
			//cout << sizeOfVertexArray << "this is unique? " << gOps.vertexToString(newV3) <<"\n";
			vertexArray[sizeOfVertexArray] = gOps.generateNewVertexPoint(oldFaceArray[i].getPointD(),oldFaceArray,oldEdgeArray,sizeOfOldFaceArray,sizeOfOldEdgeArray);
			newVertPointDIndex = sizeOfVertexArray;
			sizeOfVertexArray++;
		}
		else
		{
			newVertPointDIndex = gOps.whereInNewVertexArray(newV4,vertexArrayPtr,sizeOfVertexArray);
		}

		/*cout << "VertexArrayIndex's\n";
		cout << "edgePointAIndex "<< edgePointAIndex <<"\n";
		cout << "edgePointBIndex " << edgePointBIndex <<"\n";
		cout << "edgePointCIndex " << edgePointCIndex << "\n";
		cout << "facePointIndex " << facePointIndex << "\n";
		cout << "newVertPointAIndex " << newVertPointAIndex <<"\n";
		cout << "newVertPointBIndex " << newVertPointBIndex <<"\n";
		cout << "newVertPointCIndex " << newVertPointCIndex <<"\n";
		cout << "\n";*/
		//Edge newV1 ->


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

		//sort!!!
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

		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeAIndex],false,&edgeArray[newEdgeBIndex],false,&edgeArray[newEdgeCIndex],false,&edgeArray[newEdgeDIndex],false);
		sizeOfFaceArray++;
		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeEIndex],false,&edgeArray[newEdgeFIndex],false,&edgeArray[newEdgeGIndex],false,&edgeArray[newEdgeHIndex],false);
		sizeOfFaceArray++;
		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeIIndex],false,&edgeArray[newEdgeJIndex],false,&edgeArray[newEdgeKIndex],false,&edgeArray[newEdgeLIndex],false);
		sizeOfFaceArray++;
		faceArray[sizeOfFaceArray] = QFace(&edgeArray[newEdgeMIndex],false,&edgeArray[newEdgeNIndex],false,&edgeArray[newEdgeOIndex],false,&edgeArray[newEdgePIndex],false);
		sizeOfFaceArray++;
		//else{cout<<"caught!\n";}
	}

	//cout<< "sizeOfOldFaceArray " << sizeOfOldFaceArray<<endl;
	//GeometryOps::twoFace twoFaceStorage = gOps.getOtherFace(oea[2],ofa,f);
	//cout<< "edge Array test 1: " << gOps.printUniqueVertices(twoFaceStorage.faceOne) <<"\n";
	//cout<< "edge Array test 2: " << gOps.printUniqueVertices(twoFaceStorage.faceTwo) <<"\n";
	cout << "sizeOfVertexArray " << sizeOfVertexArray<<endl;
	cout << "sizeOfEdgeArray " << sizeOfEdgeArray<<endl;
	cout << "sizeOfFaceArray " << sizeOfFaceArray<<endl;
	/*cout <<"x: "<<faceArray[0].getEdgeA()->getVertexA()->getX();
	cout << " y: " << faceArray[0].getEdgeA()->getVertexA()->getY();
	cout << " z: " <<faceArray[0].getEdgeA()->getVertexA()->getZ()<<endl;*/
	//glVertex3f(faceArray[0].getEdgeB()->getVertexA()->getX(),faceArray[0].getEdgeB()->getVertexA()->getY(),faceArray[0].getEdgeB()->getVertexA()->getZ());
	//glVertex3f(faceArray[0].getEdgeC()->getVertexA()->getX(),faceArray[0].getEdgeC()->getVertexA()->getY(),faceArray[0].getEdgeC()->getVertexA()->getZ()); //
	//glVertex3f(faceArray[0].getEdgeD()->getVertexA()->getX(),faceArray[0].getEdgeD()->getVertexA()->getY(),faceArray[0].getEdgeD()->getVertexA()->getZ());

	/*cout << "\n newVertArray in Catmull\n";
	for (int j=0; j<sizeOfVertexArray; j++)
	{
		cout<< "Vertex " << j << " "<<gOps.vertexToString(vertexArray[j])<<endl;
	}*/
}


Catmull::~Catmull() {

}

void Catmull::draw(){
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
			glVertex3f(faceArray[i].getPointD()->getX(),faceArray[i].getPointD()->getY(),faceArray[i].getPointD()->getZ());


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
