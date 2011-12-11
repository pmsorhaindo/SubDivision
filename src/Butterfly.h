/*
 * Butterfly.h
 *
 *  Created on: 11 Dec 2011
 *      Author: mikey
 */

#ifndef BUTTERFLY_H_
#define BUTTERFLY_H_
#include "GeometryOps.h"
#include <iostream>

class Butterfly {
public:
	Butterfly();
	Butterfly(int v, int e, int f, Vertex *ova, Edge *oea, Face *ofa);
	virtual ~Butterfly();
};

#endif /* BUTTERFLY_H_ */
