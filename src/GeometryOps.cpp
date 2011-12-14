//============================================================================
// Name        : GeometryOps.cpp
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : This class handles all the calculations that need to be performed
//               on faces edges, vertices or a combination of the three to produce
//               new vertices for drawing the next iteration. - in C++, Ansi-style
//============================================================================

#include "GeometryOps.h"


using namespace std;

GeometryOps::GeometryOps() {
	// Empty Constructor
}

GeometryOps::~GeometryOps() {
	// Empty Destructor
}

/*
 * This function returns a vertex which is the average of the two vertices which
 * make up the Edge which it is provided with.
 */
Vertex GeometryOps::edgeMidPoint(Edge e1){
	float tempvx = e1.getVertexA()->getX()-e1.getVertexB()->getX();
	float tempvy = e1.getVertexA()->getY()-e1.getVertexB()->getY();
	float tempvz = e1.getVertexA()->getZ()-e1.getVertexB()->getZ();
	Vertex vert(tempvx,tempvy,tempvz);
	return vert;
}

/*
 * This function given three Vertex returns their average as a Vertex.
 */
Vertex GeometryOps::getCentroid(Vertex v1, Vertex v2, Vertex v3){
	float x =v1.getX()+v2.getX()+v3.getX();
	float y =v1.getY()+v2.getY()+v3.getY();
	float z =v1.getZ()+v2.getZ()+v3.getZ();
	Vertex v = Vertex(x,y,z);
	return v;
}

/*
 * This function compares two Vertices x, y and z values to see if they are the same
 * and returns true if this is so.
 */
bool GeometryOps::compareVertices(Vertex v1,Vertex  v2){
	bool areSame = true;
	if(v1.getX()!=v2.getX())
		{areSame = false;}
	if(v1.getY()!=v2.getY())
		{areSame = false;}
	if(v1.getZ()!=v2.getZ())
		{areSame=false;}
	return areSame;
}

/*
 * This function uses stringstream to convert a float to a string.
 * Assisted by cplusplus.com/forum/general/8165
 */
string GeometryOps::floatToString(float val){
	stringstream ss(stringstream::in|stringstream::out);
	ss<<val;
	string returnString = ss.str();
	return returnString;
}

/*
 * This function given an Edge e, returns the two Faces that share this Edge.
 * It will throw errors if it doesn't find exactly two Faces.
 */
GeometryOps::twoFace GeometryOps::getOtherFace(Edge e,Face*ptr,int i){
	GeometryOps::twoFace otherFaces;

	int found=0;
	for (int it=0;it<i;it++)
	{
		if(compareEdges(ptr[it].getEdgeA(),&e))
		{
			if(found==0){
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				otherFaces.faceTwo=ptr[it];
			}
			else if (found==2)
			{
				cerr << "problem!"<<endl;
				found++;
				otherFaces.faceTwo=ptr[it];
			}
		}
		if(compareEdges(ptr[it].getEdgeB(),&e))
		{
			if(found==0){
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				otherFaces.faceTwo=ptr[it];

			}
			else if (found==2)
			{
				cerr << "problem!"<<endl;
				found=found+1;
				otherFaces.faceTwo=ptr[it];
			}
		}
		if(compareEdges(ptr[it].getEdgeC(),&e))
		{
			if(found==0){
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				otherFaces.faceTwo=ptr[it];
			}
			else if (found==2)
			{
				cerr << "problem!"<<endl;
				found++;
				otherFaces.faceTwo=ptr[it];
			}
		}
	}
	if (found!=2) cout <<"!£$%^finding faces problem!\n";
	if (found==1) cout <<"!£$%^not Enough problem!\n";
	return otherFaces;
}

/*
 * Overloaded.
 * This function given an Edge returns the two QFaces that share this Edge.
 * It will throw errors if it doesn't find exactly two QFaces.
 */
GeometryOps::twoQFace GeometryOps::getOtherFace(Edge e,QFace*ptr,int i){
	GeometryOps::twoQFace otherFaces;
	int found=0;
	for (int it=0;it<i;it++)
	{
		if(compareEdges(ptr[it].getEdgeA(),&e))
		{
			if(found==0){
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				otherFaces.faceTwo=ptr[it];
			}
			else if (found==2)
			{
				cerr << "problem!"<<endl;
				found++;
				otherFaces.faceTwo=ptr[it];
			}
		}
		if(compareEdges(ptr[it].getEdgeB(),&e))
		{
			if(found==0){
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				otherFaces.faceTwo=ptr[it];

			}
			else if (found==2)
			{
				cerr << "problem!"<<endl;
				found=found+1;
				otherFaces.faceTwo=ptr[it];
			}
		}
		if(compareEdges(ptr[it].getEdgeC(),&e))
		{
			if(found==0){
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				otherFaces.faceTwo=ptr[it];
			}
			else if (found==2)
			{
				cerr << "problem!"<<endl;
				found++;
				otherFaces.faceTwo=ptr[it];
			}
		}
		if(compareEdges(ptr[it].getEdgeD(),&e))
				{
					if(found==0){
						found++;
						otherFaces.faceOne=ptr[it];
					}
					else if (found==1)
					{
						found++;
						otherFaces.faceTwo=ptr[it];

					}
					else if (found==2)
					{
						cerr << "problem!"<<endl;
						found=found+1;
						otherFaces.faceTwo=ptr[it];
					}
				}
	}

	if (found!=2){
		cout <<"!£$%^finding faces problem!\n";
		cout << edgeToString(e) << "\n";
	}
	if (found==1) cout <<"!£$%^not Enough problem!\n";
	return otherFaces;
}

/*
 * Compares the values of two Edges to see if they are the same.
 * This function returns true if they are.
 */
bool GeometryOps::compareEdges(Edge *e1, Edge* e2){
	bool areSame = false;
	if (
		(compareVertices(*(e1->getVertexA()),*(e2->getVertexA()))
				&&compareVertices(*(e1->getVertexB()),*(e2->getVertexB())))||
				(compareVertices(*(e1->getVertexA()),*(e2->getVertexB()))
						&&compareVertices(*(e1->getVertexB()),*(e2->getVertexA())))) // Bug of the year? Never use copy and paste ever!
		{
		areSame=true;
	}
	return areSame;
}

/*
 * Prints a Vertex to console
 */
string GeometryOps::vertexToString(const Vertex & v){
	//cout <<"VertexString: "<<v.getX()<<endl;
	string vertexString;
	stringstream ss(stringstream::in|stringstream::out);
	vertexString = "x: "+floatToString(v.getX())+" y: "+floatToString(v.getY())+" z: "+floatToString(v.getZ());

	return vertexString;
}

/*
 * A useful debugging function to print a Faces unique vertices.
 */
string GeometryOps::printUniqueVertices(Face f){
	string uniqueVertsStr;
	Vertex first,second,third;
	first = *f.getEdgeA()->getVertexA();
	second = *f.getEdgeA()->getVertexB();
	if(!compareVertices(*f.getEdgeB()->getVertexA(),*f.getEdgeA()->getVertexA()))
	{
		if(!compareVertices(*f.getEdgeB()->getVertexA(),*f.getEdgeA()->getVertexB()))
			{
			third = *f.getEdgeB()->getVertexA();
			}
	}
	if(!compareVertices(*f.getEdgeB()->getVertexB(),*f.getEdgeA()->getVertexA()))
	{
		if(!compareVertices(*f.getEdgeB()->getVertexB(),*f.getEdgeA()->getVertexB()))
		{
		third = *f.getEdgeB()->getVertexB();
		}
	}
	uniqueVertsStr = "v1: "+vertexToString(first)+" v2: "+vertexToString(second)+" v3: "+vertexToString(third);
	return uniqueVertsStr;
}

/*
 * Prints an Edge to console as two Vertices.
 */
string GeometryOps::edgeToString(Edge e){
	string returnString = vertexToString(*e.getVertexA());
	returnString = returnString + " " +vertexToString(*e.getVertexB());
	return returnString;
}


GeometryOps::twoEdge GeometryOps::getOtherEdges(Face f,Edge e){
	GeometryOps::twoEdge twoEdgeStruct;
	//TODO
	return twoEdgeStruct;
}

/*
 * Multiplies two Vertices.
 */
Vertex GeometryOps::multVert(Vertex v,float factor){
	float x =(v.getX()*factor);
	float y =(v.getY()*factor);
	float z =(v.getZ()*factor);
	Vertex returnV = Vertex(x,y,z);
	return returnV;
}

/*
 * Multiplies an Edge
 */
GeometryOps::twoVert GeometryOps::multTwoVerts(Edge e,float factor){
	GeometryOps::twoVert twoVertStruct;
	twoVertStruct.vertOne=multVert(*e.getVertexA(),factor);
	twoVertStruct.vertTwo=multVert(*e.getVertexB(),factor);
	return twoVertStruct;
}

/*
 * This function uses compare Vertices to see if an Edge contains a provided Vertex v.
 */
bool GeometryOps::edgeContainsVertex(Edge e, Vertex * v){
	bool doesContain=false;
	if(compareVertices(*e.getVertexA(),*v)) doesContain=true;
	if(compareVertices(*e.getVertexB(),*v)) doesContain=true;
	return doesContain;
}

/*
 * Uses the Compare Vertices method to see if a provided vertex v is contained in Face f.
 */
bool GeometryOps::faceContainsVertex(Face f, Vertex v){
	bool doesContain=false;
	if(compareVertices(*f.getEdgeA()->getVertexA(),v)) doesContain=true;
	if(compareVertices(*f.getEdgeA()->getVertexB(),v)) doesContain=true;
	if(compareVertices(*f.getEdgeB()->getVertexA(),v)) doesContain=true;
	if(compareVertices(*f.getEdgeB()->getVertexB(),v)) doesContain=true;
	if(compareVertices(*f.getEdgeC()->getVertexA(),v)) doesContain=true;
	if(compareVertices(*f.getEdgeC()->getVertexB(),v)) doesContain=true;
	return doesContain;
}

/*
 * Uses the Compare Vertices method to see if a provided vertex v is contained in QFace f.
 */
bool GeometryOps::faceContainsVertex(QFace f, Vertex v){
	bool doesContain=false;
		if(compareVertices(*f.getEdgeA()->getVertexA(),v)) doesContain=true;
		if(compareVertices(*f.getEdgeA()->getVertexB(),v)) doesContain=true;
		if(compareVertices(*f.getEdgeB()->getVertexA(),v)) doesContain=true;
		if(compareVertices(*f.getEdgeB()->getVertexB(),v)) doesContain=true;
		if(compareVertices(*f.getEdgeC()->getVertexA(),v)) doesContain=true;
		if(compareVertices(*f.getEdgeC()->getVertexB(),v)) doesContain=true;
		if(compareVertices(*f.getEdgeD()->getVertexA(),v)) doesContain=true;
		if(compareVertices(*f.getEdgeD()->getVertexB(),v)) doesContain=true;
		return doesContain;
}

/*
 * Calculates a Catmull Clark Edgepoint.
 */
Vertex GeometryOps::getEdgePoint(Edge* edg,Face*fptr,int i,Edge * eptr,int j){
	Vertex edgePoint = Vertex();
	GeometryOps::twoFace touchingFaces;
	touchingFaces = getOtherFace(*edg,fptr,i);

	edgePoint.add(*edg->getVertexA());
	edgePoint.add(*edg->getVertexB());
	//edgePoint.add(edg->getEdgeMidPoint());
	edgePoint.add(touchingFaces.faceOne.getCentroid());
	edgePoint.add(touchingFaces.faceTwo.getCentroid());
	//cout << "EdgePoint Added" << vertexToString(edgePoint)<<endl;
	edgePoint.div(4.0f);
	//edgePoint.div(3.0f);
	//cout << "Edgepoint: \t" << vertexToString(edgePoint)<<"\n"<<endl;
	return edgePoint;
}

/*
 * Calculates a Catmull Clark Edgepoint. Overloading the original Faces version to accept QFaces.
 */
Vertex GeometryOps::getEdgePoint(Edge* edg,QFace*fptr,int iFaces,Edge * eptr,int i){
	Vertex edgePoint = Vertex();
	GeometryOps::twoQFace touchingFaces;
	touchingFaces = getOtherFace(*edg,fptr,iFaces); // WAS PASSING THE SIZE OF EDGE ARRAY -.-

	edgePoint.add(*edg->getVertexA());
	edgePoint.add(*edg->getVertexB());
	//edgePoint.add(edg->getEdgeMidPoint());
	edgePoint.add(touchingFaces.faceOne.getCentroid());
	edgePoint.add(touchingFaces.faceTwo.getCentroid());
	//cout << "EdgePoint Added" << vertexToString(edgePoint)<<endl;
	edgePoint.div(4.0f);
	//edgePoint.div(3.0f);
	//cout << "Edgepoint: \t" << vertexToString(edgePoint)<<"\n"<<endl;
	return edgePoint;
}

/*
 * Uses the faceContainsVertex method and loops through an array of Faces
 * Faces which contain the given Vertex v are returned in a sixFace Structure.
 */
GeometryOps::sixFace GeometryOps::getAdjacentFaces(Vertex v, Face*ptr, int i){
	GeometryOps::sixFace adjFaces;
	int found = 0;
	// where i is the amount of faces in the array
	for (int it=0;it<i;it++)
	{
		if(faceContainsVertex(ptr[it],v))
		{
			if(found==0){
				found++;
				adjFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				adjFaces.faceTwo=ptr[it];
			}
			else if (found==2)
			{
				found++;
				adjFaces.faceThree=ptr[it];
			}
			else if (found==3)
			{
				found++;
				adjFaces.faceFour=ptr[it];
			}
			else if (found==4)
			{
				found++;
				adjFaces.faceFive=ptr[it];
			}
			else if (found==5)
			{
				found++;
				adjFaces.faceSix=ptr[it];
			}
		}
	}
	adjFaces.contains = found;
	return adjFaces;
}

/*
 * Uses the faceContainsVertex method and loops through an array of QFaces
 * QFaces which contain the given Vertex v are returned in a sixQFace Structure.
 */
GeometryOps::sixQFace GeometryOps::getAdjacentFaces(Vertex v, QFace*ptr, int i){
	GeometryOps::sixQFace adjFaces;
	int found = 0;
	for (int it=0;it<i;it++)
	{
		if(faceContainsVertex(ptr[it],v))
		{
			//cout << "Face At! : " << it << "\n";
			if(found==0){
				found++;
				adjFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				adjFaces.faceTwo=ptr[it];
			}
			else if (found==2)
			{
				found++;
				adjFaces.faceThree=ptr[it];
			}
			else if (found==3)
			{
				found++;
				adjFaces.faceFour=ptr[it];
			}
			else if (found==4)
			{
				found++;
				adjFaces.faceFive=ptr[it];
			}
			else if (found==5)
			{
				found++;
				adjFaces.faceSix=ptr[it];
			}
		}
	}
	adjFaces.contains = found;
	return adjFaces;
}

/*
 * Uses the edgeContainsVertex method and loops through an array of Edges
 * to return all the Edges that touch a Vertex. This is returned in an eightEdge Structure.
 */
GeometryOps::eightEdge GeometryOps::getIncidentEdges(Vertex *v, Edge*ptr, int iEdges){
	GeometryOps::eightEdge incEdges;
	int found = 0;
	for (int it=0;it<iEdges;it++)
	{
		if(edgeContainsVertex(ptr[it],v))
		{
			if(found==0){
				found++;
				incEdges.edgeOne=ptr[it];
			}
			else if (found==1)
			{
				found++;
				incEdges.edgeTwo=ptr[it];
			}
			else if (found==2)
			{
				found++;
				incEdges.edgeThree=ptr[it];
			}
			else if (found==3)
			{
				found++;
				incEdges.edgeFour=ptr[it];
			}
			else if (found==4)
			{
				found++;
				incEdges.edgeFive=ptr[it];
			}
			else if (found==5)
			{
				found++;
				incEdges.edgeSix=ptr[it];
			}
			else if (found==6)
			{
				found++;
				incEdges.edgeSeven=ptr[it];
			}
			else if (found==7)
			{
				found++;
				incEdges.edgeEight=ptr[it];
			}
		}
	}
	incEdges.contains = found;
	return incEdges;
}

/*
 * This generates a Catmull-Clark Q point which is the average of all the Face-Centroids divided
 * by the number of Faces incident on a particular Vertex v which is provided.
 */
Vertex GeometryOps::getQ(Vertex v, Face*ptr, int i){
	GeometryOps::sixFace faces = getAdjacentFaces(v,ptr,i);
	Vertex newQ;
	if(faces.contains==3) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid();
	if(faces.contains==4) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid();
	if(faces.contains==5) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid();
	if(faces.contains==6) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid()+faces.faceSix.getCentroid();

	return newQ/faces.contains;
}

/*
 * Overloaded.
 * This generates a Catmull-Clark Q point which is the average of all the QFace-Centroids divided
 * by the number of QFaces incident on a particular Vertex v which is provided.
 */
Vertex GeometryOps::getQ(Vertex v, QFace*ptr, int i){
	GeometryOps::sixQFace faces = getAdjacentFaces(v,ptr,i);
	Vertex newQ;
	if(faces.contains==3) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid();
	if(faces.contains==4) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid();
	if(faces.contains==5) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid();
	if(faces.contains==6) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid()+faces.faceSix.getCentroid();
	return newQ/faces.contains;
}

/*
 * This generates a Catmull-Clark R points which is the which is the average of all the Edge-midpoints incident
 * on a Vertex v which is provided. This is then multiplied by two for use in the final newVertexPoint Function.
 */
Vertex GeometryOps::get2R(Vertex v, Edge*ptr, int i){
	GeometryOps::eightEdge edges = getIncidentEdges(&v,ptr,i);
	Vertex newR;
	if (edges.contains==2) newR = edges.edgeOne.getEdgeMidPoint()+edges.edgeTwo.getEdgeMidPoint();
	if (edges.contains==3) newR = edges.edgeOne.getEdgeMidPoint()+edges.edgeTwo.getEdgeMidPoint()+edges.edgeThree.getEdgeMidPoint();
	if (edges.contains==4) newR = edges.edgeOne.getEdgeMidPoint()+edges.edgeTwo.getEdgeMidPoint()+edges.edgeThree.getEdgeMidPoint()+edges.edgeFour.getEdgeMidPoint();
	if (edges.contains==5) newR = edges.edgeOne.getEdgeMidPoint()+edges.edgeTwo.getEdgeMidPoint()+edges.edgeThree.getEdgeMidPoint()+edges.edgeFour.getEdgeMidPoint()+edges.edgeFive.getEdgeMidPoint();
	if (edges.contains==6) newR = edges.edgeOne.getEdgeMidPoint()+edges.edgeTwo.getEdgeMidPoint()+edges.edgeThree.getEdgeMidPoint()+edges.edgeFour.getEdgeMidPoint()+edges.edgeFive.getEdgeMidPoint()+edges.edgeSix.getEdgeMidPoint();
	if (edges.contains==7) newR = edges.edgeOne.getEdgeMidPoint()+edges.edgeTwo.getEdgeMidPoint()+edges.edgeThree.getEdgeMidPoint()+edges.edgeFour.getEdgeMidPoint()+edges.edgeFive.getEdgeMidPoint()+edges.edgeSix.getEdgeMidPoint()+edges.edgeSeven.getEdgeMidPoint();
	if (edges.contains==8) newR = edges.edgeOne.getEdgeMidPoint()+edges.edgeTwo.getEdgeMidPoint()+edges.edgeThree.getEdgeMidPoint()+edges.edgeFour.getEdgeMidPoint()+edges.edgeFive.getEdgeMidPoint()+edges.edgeSix.getEdgeMidPoint()+edges.edgeSeven.getEdgeMidPoint()+edges.edgeEight.getEdgeMidPoint();
	return (newR/edges.contains)*2;
}

/*
 * This generates a Catmull-Clark S point which is the original Vertex point and divides it by the valence of that point.
 */
Vertex GeometryOps::getSandStuff(Vertex v, Edge*ptr, int i){
	GeometryOps::eightEdge edges = getIncidentEdges(&v,ptr,i);
	Vertex sAnd = v*(edges.contains-3);
	return sAnd;
}

/*
 * This generates a new Catmull Clark vertex point on a Shape composed of Triangles.
 */
Vertex GeometryOps::generateNewVertexPoint(Vertex * v, Face*facePtr, Edge*edgePtr, int faceSize, int edgeSize){
	GeometryOps::eightEdge edges = getIncidentEdges(v,edgePtr,edgeSize);
	Vertex jeden = getQ(*v,facePtr,faceSize);
	Vertex dwa = get2R(*v,edgePtr,edgeSize);
	Vertex trzy = getSandStuff(*v,edgePtr,edgeSize);
	Vertex polishAverageOfVertices = ((jeden/edges.contains)+(dwa/edges.contains)+(trzy/edges.contains));
	return polishAverageOfVertices;
}

/*
 * This generates a new Catmull Clark vertex point on a Shape composed of Quads.
 */
Vertex GeometryOps::generateNewVertexPoint(Vertex * v, QFace*facePtr, Edge*edgePtr, int faceSize, int edgeSize){
	GeometryOps::eightEdge edges = getIncidentEdges(v,edgePtr,edgeSize);
	Vertex jeden = getQ(*v,facePtr,faceSize);
	Vertex dwa = get2R(*v,edgePtr,edgeSize);
	Vertex trzy = getSandStuff(*v,edgePtr,edgeSize);
	Vertex polishAverageOfVertices = ((jeden/edges.contains)+(dwa/edges.contains)+(trzy/edges.contains));
	return polishAverageOfVertices;
}

/*
 * This function takes two Edges and returns the and returns the Vertex that they share.
 * The function will return the (0,0,0) vertex if no Vertex is shared.
 */
Vertex GeometryOps::twoEdgesGetCommonVertex(Edge a, Edge b){
	if(compareVertices(*a.getVertexA(),*b.getVertexA())){
		return *a.getVertexA();
	}
	if(compareVertices(*a.getVertexA(),*b.getVertexB())){
		return *a.getVertexA();
	}
	if(compareVertices(*a.getVertexB(),*b.getVertexA())){
		return *a.getVertexB();
	}
	if(compareVertices(*a.getVertexB(),*b.getVertexB()))
	{
		return *a.getVertexB();
	}
	return Vertex(); // Run twoEdgesIsCommonVertex to not catch this nasty thing.

}

/*
 * This function uses compareVertices to return true if two edges share a common Vertex,
 * and false otherwise.
 */
bool GeometryOps::twoEdgesIsCommonVertex(Edge a, Edge b){
	if(compareVertices(*a.getVertexA(),*b.getVertexA())||
			compareVertices(*a.getVertexA(),*b.getVertexB())||
			compareVertices(*a.getVertexB(),*b.getVertexA())||
			compareVertices(*a.getVertexB(),*b.getVertexB())){
		return true;
	}
	return false;
}

/*
 * This function returns true if an a Face identical to Face f is stored in the array
 * pointed to by the pointer facePtr.
 */
bool GeometryOps::existsInNewFaceArray(Face f, Face*facePtr,int faceArraySize){
	bool exists = false;
	//TODO: not needed
	return exists;
}

/*
 * This function returns true if an Edge of the same value of Edge e exists in the
 * Array of Edges pointed to by edgePtr and false otherwise.
 */
bool GeometryOps::existsInNewEdgeArray(Edge e, Edge*edgePtr,int edgeArraySize){
	bool exists = false;
		for(int i=0; i<edgeArraySize; i++)
		{
			if(compareEdges(&e,&edgePtr[i])){
				return true;
			}
		}
		return exists;
}

/*
 * This function returns true if a Vertex of the same value as the Vertex v provided as a parameter,
 * exists in the array of vertices pointed to by vertexPtr and false otherwise.
 */
bool GeometryOps::existsInNewVertexArray(Vertex v, Vertex*vertexPtr,int vertexArraySize){
	bool exists = false;
	for(int i=0; i<vertexArraySize; i++)
	{
		if(compareVertices(v,vertexPtr[i])){
			return true;
		}
	}
	return exists;
}

/*
 * This function returns the position of a vertex within an array of Vertices.
 * It returns -1 if the vertex is not found however the existsInNewVertexArray
 * function can be run beforehand to avoid this.
 */
int GeometryOps::whereInNewVertexArray(Vertex v, Vertex*vertexPtr,int vertexArraySize){
	for(int i=0; i<vertexArraySize; i++)
		{
			if(compareVertices(v,vertexPtr[i])){
				return i;
			}
		}
	cout << "dropped fail." << endl;
	return -1;
}

/*
 * Providing this function with two vertices and a Face will return the vertex in the face that hasn't been provided.
 * This function will break if points that are not in the face are provided.
 */
Vertex GeometryOps::thirdPointInFace(Vertex v1,Vertex v2,Face f){

	/*cout <<endl;
	cout << "Face : " << printUniqueVertices(f) << "\n";
	cout << "v1 : " << vertexToString(v1) << "\n";
	cout << "v2 : " << vertexToString(v2) << "\n"; */

	if( ( (compareVertices(v1,*f.getPointA())) && (compareVertices(v2,*f.getPointB())) ) ||
			( (compareVertices(v2,*f.getPointA())) && (compareVertices(v1,*f.getPointB())) ) )
	{
		return *f.getPointC();
	}

	if( ( (compareVertices(v1,*f.getPointA())) && (compareVertices(v2,*f.getPointC())) ) ||
			( (compareVertices(v2,*f.getPointA())) && (compareVertices(v1,*f.getPointC())) ) )
	{
		return *f.getPointB();
	}
	if( ( (compareVertices(v1,*f.getPointB())) && (compareVertices(v2,*f.getPointC())) ) ||
			( (compareVertices(v2,*f.getPointB())) && (compareVertices(v1,*f.getPointC())) ) )
	{
		return *f.getPointA();
	}

	/*
	 * Another approach
	 * if(compareVertices(v1,*f.getEdgeA()->getVertexA())&&compareVertices(v2,*f.getEdgeB()->getVertexA())) return *f.getEdgeC()->getVertexA();
	if(compareVertices(v2,*f.getEdgeA()->getVertexA())&&compareVertices(v1,*f.getEdgeB()->getVertexA())) return *f.getEdgeC()->getVertexA();
	if(compareVertices(v1,*f.getEdgeB()->getVertexA())&&compareVertices(v2,*f.getEdgeC()->getVertexA())) return *f.getEdgeA()->getVertexA();
	if(compareVertices(v2,*f.getEdgeB()->getVertexA())&&compareVertices(v1,*f.getEdgeC()->getVertexB())) return *f.getEdgeA()->getVertexA();
	if(compareVertices(v1,*f.getEdgeC()->getVertexA())&&compareVertices(v2,*f.getEdgeA()->getVertexA())) return *f.getEdgeB()->getVertexA();
	if(compareVertices(v2,*f.getEdgeC()->getVertexA())&&compareVertices(v1,*f.getEdgeA()->getVertexA())) return *f.getEdgeB()->getVertexA();*/
	Vertex err = Vertex();
	cout << "gOPs: Error finding third vertex!" << "\n";
	return err;
}

/*
 * Gets the outermost point of a 'Butterfly stencil' when given the edge of the two Vertex points
 * which make up the edge of the triangle touching that outermost point. This will be called four times per stencil.
 */
Vertex GeometryOps::getWings(Vertex e1, Vertex e2, Face * facePtr, int sizeOfFaceArray, Vertex opposingV){
	//Could possibly be changed to work with just an edge and opposing Vertex.
	Vertex wing = Vertex();
	Edge edge = Edge(&e2,&e1);
	GeometryOps::twoFace facesBack = getOtherFace(edge,facePtr,sizeOfFaceArray);

	if(faceContainsVertex(facesBack.faceOne, opposingV))
	{
		return thirdPointInFace(e1,e2,facesBack.faceTwo);
	}

	return thirdPointInFace(e1,e2,facesBack.faceOne);
}
