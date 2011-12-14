//============================================================================
// Name        : SubDivide.h
// Author      : Mikey
// Version     : 1.0
// Copyright   :
// Description : Organizes my subdivision program to run
//               both implementations recursively. - in C++, Ansi-style
//============================================================================

#ifndef SUBDIVIDE_H_
#define SUBDIVIDE_H_
#include "SetUpCube.h"
#include "Catmull.h"
#include "Butterfly.h"


class SubDivide {
private:
	int iterations;
	int type;
	SetUpCube * cube;
	Catmull * lastCatmull;
	Catmull * currentCatmull;
	Butterfly * lastButterfly;
	Butterfly * currentButterfly;

public:
	SubDivide();
	virtual ~SubDivide();
	void apply(int type);
	void draw(bool faces, bool lines, bool points);
	void printState();
};

#endif /* SUBDIVIDE_H_ */
