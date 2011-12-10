/*
 * GeometryOps.h
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#ifndef GEOMETRYOPS_H_
#define GEOMETRYOPS_H_
#include "Face.h"
#include "QFace.h"
#include <string>
#include <iostream>
#include <sstream>

class GeometryOps {
public:

	struct twoFace{
		Face faceOne;
		Face faceTwo;
	};

	struct twoQFace{
			QFace faceOne;
			QFace faceTwo;
		};

	struct sixFace{
			int contains;
			Face faceOne;
			Face faceTwo;
			Face faceThree;
			Face faceFour;
			Face faceFive;
			Face faceSix;
		};
	struct sixQFace{
				int contains;
				QFace faceOne;
				QFace faceTwo;
				QFace faceThree;
				QFace faceFour;
				QFace faceFive;
				QFace faceSix;
			};


	struct eightEdge{
		int contains;
		Edge edgeOne;
		Edge edgeTwo;
		Edge edgeThree;
		Edge edgeFour;
		Edge edgeFive;
		Edge edgeSix;
		Edge edgeSeven;
		Edge edgeEight;
	};

	struct twoEdge{
				Vertex edgeOne;
				Vertex edgeTwo;
			};

	struct threeEdge{
				Vertex edgeOne;
				Vertex edgeTwo;
				Vertex edgeThree;
			};

	struct twoVert{
			Vertex vertOne;
			Vertex vertTwo;
		};

	struct fourExistVert{
				Vertex vertOne;
				bool vertOneExists;
				Vertex vertTwo;
				bool vertTwoExists;
				Vertex vertThree;
				bool vertThreeExists;
				Vertex vertFour;
				bool vertFourExists;
			};

	GeometryOps();
	virtual ~GeometryOps();
	//pass by reference to save on the copying
	Vertex edgeMidPoint(Edge e1);
	Vertex getCentroid(Vertex v1, Vertex v2, Vertex v3);
	Vertex getEdgePoint(Edge* edg,Face*fptr,int iFaces,Edge * eptr,int iEdges);
	Vertex getEdgePoint(Edge* edg,QFace*fptr,int iFaces,Edge * eptr,int iEdges);
	bool compareVertices(Vertex v1,Vertex v2);
	twoFace getOtherFace(Edge e,Face*ptr,int iFaces);
	twoQFace getOtherFace(Edge e,QFace*ptr,int iFaces);
	eightEdge getIncidentEdges(Vertex * v, Edge*ptr, int iEdges);
	sixFace getAdjacentFaces(Vertex v, Face*ptr, int iFaces);
	sixQFace getAdjacentFaces(Vertex v, QFace*ptr, int iFaces);
	bool compareEdges(Edge *e1, Edge* e2);
	std::string printUniqueVertices(Face f);
	std::string printUniqueVertices(QFace f);
	std::string vertexToString(const Vertex & v);
	std::string floatToString(float val);
	std::string edgeToString(Edge e);
	twoEdge getOtherEdges(Face f, Edge e);
	threeEdge getOtherEdges(QFace f, Edge e);
	twoVert multTwoVerts(Edge e,float factor);
	Vertex multVert(Vertex v,float factor);
	bool faceContainsVertex(Face f, Vertex v);
	bool faceContainsVertex(QFace f, Vertex v);
	bool edgeContainsVertex(Edge e, Vertex * v);
	Vertex getQ(Vertex v, Face*ptr, int i);
	Vertex getQ(Vertex v, QFace*ptr, int i);
	Vertex get2R(Vertex v, Edge*ptr, int i);
	Vertex getSandStuff(Vertex v, Edge*ptr, int i);
	Vertex generateNewVertexPoint(Vertex * v, Face*facePtr, Edge*edgePtr, int faceSize, int edgeSize);
	Vertex generateNewVertexPoint(Vertex * v, QFace*facePtr, Edge*edgePtr, int faceSize, int edgeSize);
	Vertex twoEdgesGetCommonVertex(Edge a, Edge b);
	bool twoEdgesIsCommonVertex(Edge a, Edge b);
	//int GeometryOps::matchIsFound(int found, twoFace twoFacestruct,);
	bool existsInNewQFaceArray(Face f, QFace*facePtr,int faceArraySize);
	bool existsInNewFaceArray(Face f, Face*facePtr,int faceArraySize);
	bool existsInNewEdgeArray(Edge f, Edge*edgePtr,int edgeArraySize);
	bool existsInNewVertexArray(Vertex v, Vertex*vertexPtr,int vertexArraySize);
	int whereInNewVertexArray(Vertex v, Vertex*vertexPtr,int vertexArraySize);
};

#endif /* GEOMETRYOPS_H_ */
