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
