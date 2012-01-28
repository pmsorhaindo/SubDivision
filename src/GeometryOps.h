/*
Copyright (C) <2012> <Paul-Michael Sorhaindo>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
//============================================================================
// Name        : GeometryOps.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class handles all the calculations that need to be performed
//               on faces edges, vertices or a combination of the three to produce
//               new vertices for drawing the next iteration. - in C++, Ansi-style
//============================================================================

#ifndef GEOMETRYOPS_H_
#define GEOMETRYOPS_H_
#include "Face.h"
#include "QFace.h"
#include <string>
#include <iostream>
#include <sstream>

class GeometryOps {
public:

	/*
	 * Custom Structure to hold and return two Faces.
	 */
	struct twoFace{
		Face faceOne;
		Face faceTwo;
	};

	/*
	 * Custom Structure to hold and return two QFaces.
	 */
	struct twoQFace{
			QFace faceOne;
			QFace faceTwo;
		};

	/*
	 * Custom Structure to hold and return six Faces.
	 * Can also hold the number of faces currently assigned in the variable contains.
	 */
	struct sixFace{
			int contains;
			Face faceOne;
			Face faceTwo;
			Face faceThree;
			Face faceFour;
			Face faceFive;
			Face faceSix;
		};

	/*
	 * Custom Structure to hold and return six QFaces.
	 * Can also hold the number of Quads currently assigned in the variable contains.
	 */
	struct sixQFace{
				int contains;
				QFace faceOne;
				QFace faceTwo;
				QFace faceThree;
				QFace faceFour;
				QFace faceFive;
				QFace faceSix;
			};

	/*
	 * A custom structure to hold and return eight Edges,
	 * the number of Edges in the structure can be monitored with
	 * the variable contains.
	 */
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

	/*
	 * A custom structure to hold and return two Edges
	 */
	struct twoEdge{
				Vertex edgeOne;
				Vertex edgeTwo;
			};

	/*
	 * A custom structure to hold and return three Edges
	 */
	struct threeEdge{
				Vertex edgeOne;
				Vertex edgeTwo;
				Vertex edgeThree;
			};

	/*
	 * A custom structure to hold and return two Vertices
	 */
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
	bool existsInNewQFaceArray(Face f, QFace*facePtr,int faceArraySize);
	bool existsInNewFaceArray(Face f, Face*facePtr,int faceArraySize);
	bool existsInNewEdgeArray(Edge f, Edge*edgePtr,int edgeArraySize);
	bool existsInNewVertexArray(Vertex v, Vertex*vertexPtr,int vertexArraySize);
	int whereInNewVertexArray(Vertex v, Vertex*vertexPtr,int vertexArraySize);
	Vertex thirdPointInFace(Vertex v1,Vertex v2,Face f);
	Vertex getWings(Vertex e1, Vertex e2, Face * facePtr, int sizeOfFaceArray, Vertex opposingV);
};

#endif /* GEOMETRYOPS_H_ */
