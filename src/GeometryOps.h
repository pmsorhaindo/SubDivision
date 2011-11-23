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

	struct sixFace{
			int contains;
			Face faceOne;
			Face faceTwo;
			Face faceThree;
			Face faceFour;
			Face faceFive;
			Face faceSix;
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
	Vertex getEdgePoint(Edge* edg,Face*fptr,int iFaces,Edge * eptr,int j);
	bool compareVertices(Vertex v1,Vertex v2);
	twoFace getOtherFace(Edge e,Face*ptr,int iFaces);
	eightEdge getIncidentEdges(Vertex * v, Edge*ptr, int iEdges);
	sixFace getAdjacentFaces(Vertex v, Face*ptr, int iFaces);
	bool compareEdges(Edge *e1, Edge* e2);
	std::string printUniqueVertices(Face f);
	std::string vertexToString(Vertex v);
	std::string floatToString(float val);
	std::string edgeToString(Edge e);
	twoEdge getOtherEdges(Face f, Edge e);
	twoVert multTwoVerts(Edge e,float factor);
	Vertex multVert(Vertex v,float factor);
	bool faceContainsVertex(Face f, Vertex v);
	bool edgeContainsVertex(Edge e, Vertex * v);
	Vertex getQ(Vertex v, Face*ptr, int i);
	Vertex get2R(Vertex v, Edge*ptr, int i);
	Vertex getSandStuff(Vertex v, Edge*ptr, int i);
	Vertex generateNewVertexPoint(Vertex * v, Face*facePtr, Edge*edgePtr, int faceSize, int edgeSize);
	Vertex twoEdgesGetCommonVertex(Edge a, Edge b);
	bool twoEdgesIsCommonVertex(Edge a, Edge b);
	//int GeometryOps::matchIsFound(int found, twoFace twoFacestruct,);
	bool existsInNewFaceArray(Face f, Face*facePtr,int faceArraySize);
	bool existsInNewEdgeArray(Edge f, Edge*edgePtr,int edgeArraySize);
	bool existsInNewVertexArray(Vertex v, Vertex*vertexPtr,int vertexArraySize);
};

#endif /* GEOMETRYOPS_H_ */
