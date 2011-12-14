/*
 * SubDivide.h
 *
 *  Created on: 14 Dec 2011
 *      Author: mikey
 */

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
	void draw();
};

#endif /* SUBDIVIDE_H_ */
