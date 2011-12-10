/*
 * GeometryOps.cpp
 *
 *  Created on: 6 Oct 2011
 *      Author: Mikey
 */

#include "GeometryOps.h"


using namespace std;

GeometryOps::GeometryOps() {
	// TODO Auto-generated constructor stub
}

GeometryOps::~GeometryOps() {
	// TODO Auto-generated destructor stub
}

Vertex GeometryOps::edgeMidPoint(Edge e1){

	float tempvx = e1.getVertexA()->getX()-e1.getVertexB()->getX();
	float tempvy = e1.getVertexA()->getY()-e1.getVertexB()->getY();
	float tempvz = e1.getVertexA()->getZ()-e1.getVertexB()->getZ();
	Vertex vert(tempvx,tempvy,tempvz);
	return vert;
}

Vertex GeometryOps::getCentroid(Vertex v1, Vertex v2, Vertex v3){
	float x =v1.getX()+v2.getX()+v3.getX();
	float y =v1.getY()+v2.getY()+v3.getY();
	float z =v1.getZ()+v2.getZ()+v3.getZ();
	Vertex v = Vertex(x,y,z);
	return v;
}

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

string GeometryOps::floatToString(float val){
	//cplusplus.com/forum/general/8165
	stringstream ss(stringstream::in|stringstream::out);
	ss<<val;
	string returnString = ss.str();
	return returnString;
}

GeometryOps::twoFace GeometryOps::getOtherFace(Edge e,Face*ptr,int i){
	GeometryOps::twoFace otherFaces;
	int found=0;
	for (int it=0;it<i;it++)
	{
		//cout<<"arrrghh: "<<edgeToString(e)<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeA())<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeB())<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeC())<<endl;
		if(compareEdges(ptr[it].getEdgeA(),&e))
		{
			if(found==0){
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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

/*GeometryOps::twoQFace GeometryOps::getOtherFace(Edge e,QFace*ptr,int i){
	GeometryOps::twoQFace otherFaces;
	int found=0;
	for (int it=0;it<i;it++)
	{
		//cout<<"arrrghh: "<<edgeToString(e)<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeA())<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeB())<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeC())<<endl;
		QFace & face = ptr[it];
		Edge * pEdge = face.getEdgeA();
		Vertex * pVert = pEdge->getVertexA();
		//cout << "we have " <<vertexToString(*pVert) << " vertex?\n";
		//cout << "we have " <<vertexToString(*(e.getVertexA())) << " e?\n";
		if(compareEdges(ptr[it].getEdgeA(),&e))
		{
			cout << "check" <<endl;
			if(found==0){
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
						//cout<<"got a Face\n";
						found++;
						otherFaces.faceOne=ptr[it];
					}
					else if (found==1)
					{
						//cout << "got a Two Face\n";
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
}*/

GeometryOps::twoQFace GeometryOps::getOtherFace(Edge e,QFace*ptr,int i){
	GeometryOps::twoQFace otherFaces;
	int found=0;
	for (int it=0;it<i;it++)
	{
		//cout<<"arrrghh: "<<edgeToString(e)<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeA())<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeB())<<endl;
		//cout<<"hmmmmmm: "<<edgeToString(*ptr[it].getEdgeC())<<endl;
		if(compareEdges(ptr[it].getEdgeA(),&e))
		{
			if(found==0){
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
				//cout<<"got a Face\n";
				found++;
				otherFaces.faceOne=ptr[it];
			}
			else if (found==1)
			{
				//cout << "got a Two Face\n";
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
						//cout<<"got a Face\n";
						found++;
						otherFaces.faceOne=ptr[it];
					}
					else if (found==1)
					{
						//cout << "got a Two Face\n";
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
	if (found!=2) cout <<"!£$%^finding faces problem!\n";
	if (found==1) cout <<"!£$%^not Enough problem!\n";
	return otherFaces;
}

bool GeometryOps::compareEdges(Edge *e1, Edge* e2){
	bool areSame = false;
	if (
		(compareVertices(*(e1->getVertexA()),*(e2->getVertexA()))
				&&compareVertices(*(e1->getVertexB()),*(e2->getVertexB())))||
				(compareVertices(*(e1->getVertexA()),*(e2->getVertexA()))
						&&compareVertices(*(e1->getVertexB()),*(e2->getVertexB()))))
	{
		areSame=true;
	}
	return areSame;
}

string GeometryOps::vertexToString(const Vertex & v){
	//cout <<"VertexString: "<<v.getX()<<endl;
	string vertexString;
	stringstream ss(stringstream::in|stringstream::out);
	vertexString = "x: "+floatToString(v.getX())+" y: "+floatToString(v.getY())+" z: "+floatToString(v.getZ());

	return vertexString;
}

string GeometryOps::printUniqueVertices(Face f){
	string uniqueVertsStr;
	Vertex first,second,third;
	first = *f.getEdgeA()->getVertexA();
	//cout << "First!!! << " + vertexToString(first)<<endl;
	second = *f.getEdgeA()->getVertexB();
	if(!compareVertices(*f.getEdgeB()->getVertexA(),*f.getEdgeA()->getVertexA()))
	{
		if(!compareVertices(*f.getEdgeB()->getVertexA(),*f.getEdgeA()->getVertexB()))
			{
			third = *f.getEdgeB()->getVertexA();
			//cout << "third!!! x: " << third.getX()<<endl;
			}
	}
	if(!compareVertices(*f.getEdgeB()->getVertexB(),*f.getEdgeA()->getVertexA()))
	{
		if(!compareVertices(*f.getEdgeB()->getVertexB(),*f.getEdgeA()->getVertexB()))
		{
		third = *f.getEdgeB()->getVertexB();
		//cout << "third!!! x: " << third.getX()<<endl;
		}
	}
	uniqueVertsStr = "v1: "+vertexToString(first)+" v2: "+vertexToString(second)+" v3: "+vertexToString(third);
	return uniqueVertsStr;
}

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

Vertex GeometryOps::multVert(Vertex v,float factor){
	float x =(v.getX()*factor);
	float y =(v.getY()*factor);
	float z =(v.getZ()*factor);
	Vertex returnV = Vertex(x,y,z);
	return returnV;
}

GeometryOps::twoVert GeometryOps::multTwoVerts(Edge e,float factor){
	GeometryOps::twoVert twoVertStruct;
	twoVertStruct.vertOne=multVert(*e.getVertexA(),factor);
	twoVertStruct.vertTwo=multVert(*e.getVertexB(),factor);
	return twoVertStruct;
}

bool GeometryOps::edgeContainsVertex(Edge e, Vertex * v){
	bool doesContain=false;
	if(compareVertices(*e.getVertexA(),*v)) doesContain=true;
	if(compareVertices(*e.getVertexB(),*v)) doesContain=true;
	return doesContain;
}

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

GeometryOps::sixFace GeometryOps::getAdjacentFaces(Vertex v, Face*ptr, int i){
	GeometryOps::sixFace adjFaces;
	int found = 0;
	for (int it=0;it<i;it++)
	{
		if(faceContainsVertex(ptr[it],v))
		{
			//cout << "Face At! : " << it << "\n";
			if(found==0){
				found++;
				adjFaces.faceOne=ptr[it];
				//cout << "1aFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==1)
			{
				found++;
				adjFaces.faceTwo=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==2)
			{
				found++;
				adjFaces.faceThree=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==3)
			{
				found++;
				adjFaces.faceFour=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==4)
			{
				found++;
				adjFaces.faceFive=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==5)
			{
				found++;
				adjFaces.faceSix=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
		}
	}
	adjFaces.contains = found;
	return adjFaces;
}

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
				//cout << "1aFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==1)
			{
				found++;
				adjFaces.faceTwo=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==2)
			{
				found++;
				adjFaces.faceThree=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==3)
			{
				found++;
				adjFaces.faceFour=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==4)
			{
				found++;
				adjFaces.faceFive=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
			else if (found==5)
			{
				found++;
				adjFaces.faceSix=ptr[it];
				//cout << "1bFace a centroid (x) is : " << ptr[it].getCentroid().getX() <<endl;
				//cout << "Face a centroid (y) is : " << ptr[it].getCentroid().getY() <<endl;
				//cout << "Face a centroid (z) is : " << ptr[it].getCentroid().getZ() <<endl;
			}
		}
	}
	adjFaces.contains = found;
	return adjFaces;
}

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

Vertex GeometryOps::getQ(Vertex v, Face*ptr, int i){
	GeometryOps::sixFace faces = getAdjacentFaces(v,ptr,i);
	Vertex newQ;
	//cout << "Q six face contains: " << faces.contains << "\n";
	if(faces.contains==3) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid();
	if(faces.contains==4) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid();
	if(faces.contains==5) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid();
	if(faces.contains==6) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid()+faces.faceSix.getCentroid();

	return newQ/faces.contains;
}

Vertex GeometryOps::getQ(Vertex v, QFace*ptr, int i){
	GeometryOps::sixQFace faces = getAdjacentFaces(v,ptr,i);
	Vertex newQ;
	if(faces.contains==3) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid();
	if(faces.contains==4) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid();
	if(faces.contains==5) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid();
	if(faces.contains==6) newQ = faces.faceOne.getCentroid()+faces.faceTwo.getCentroid()+faces.faceThree.getCentroid()+faces.faceFour.getCentroid()+faces.faceFive.getCentroid()+faces.faceSix.getCentroid();
	return newQ/faces.contains;
}

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

Vertex GeometryOps::getSandStuff(Vertex v, Edge*ptr, int i){
	GeometryOps::eightEdge edges = getIncidentEdges(&v,ptr,i);
	Vertex sAnd = v*(edges.contains-3);
	return sAnd;
}

Vertex GeometryOps::generateNewVertexPoint(Vertex * v, Face*facePtr, Edge*edgePtr, int faceSize, int edgeSize){
	GeometryOps::eightEdge edges = getIncidentEdges(v,edgePtr,edgeSize);
	Vertex jeden = getQ(*v,facePtr,faceSize);
	Vertex dwa = get2R(*v,edgePtr,edgeSize);
	Vertex trzy = getSandStuff(*v,edgePtr,edgeSize);
	Vertex polishAverageOfVertices = ((jeden/edges.contains)+(dwa/edges.contains)+(trzy/edges.contains));
	return polishAverageOfVertices;
}

Vertex GeometryOps::generateNewVertexPoint(Vertex * v, QFace*facePtr, Edge*edgePtr, int faceSize, int edgeSize){
	GeometryOps::eightEdge edges = getIncidentEdges(v,edgePtr,edgeSize);
	Vertex jeden = getQ(*v,facePtr,faceSize);
	Vertex dwa = get2R(*v,edgePtr,edgeSize);
	Vertex trzy = getSandStuff(*v,edgePtr,edgeSize);
	Vertex polishAverageOfVertices = ((jeden/edges.contains)+(dwa/edges.contains)+(trzy/edges.contains));
	return polishAverageOfVertices;
}

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
	return Vertex(); // run twoEdgesIsCommonVertex to not catch this nasty thing.

}

bool GeometryOps::twoEdgesIsCommonVertex(Edge a, Edge b){
	if(compareVertices(*a.getVertexA(),*b.getVertexA())||
			compareVertices(*a.getVertexA(),*b.getVertexB())||
			compareVertices(*a.getVertexB(),*b.getVertexA())||
			compareVertices(*a.getVertexB(),*b.getVertexB())){
		return true;
	}
	return false;
}

bool GeometryOps::existsInNewFaceArray(Face f, Face*facePtr,int faceArraySize){
	bool exists = false;
	//not needed
	return exists;
}

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
