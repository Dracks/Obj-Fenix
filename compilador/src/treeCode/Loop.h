/*
 *  Loop.h
 *  compilador
 *
 *  Created by dracks on 27/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef LOOP_H
#define LOOP_H

#include "Base.h"
#include <iostream>
#include <vector>
#include "Expresion.h"
//using namespace vector;
using namespace std;

class Loop: public Base{
public:
  	Loop(int line_);
	void semantic();
  	void addSentence(Base* sent);
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
protected:
	vector<Base*> code;
};

class While: public Loop{
public:
	While(AbstractExpresion* cond, int line_);
	void semantic();
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
protected:
	AbstractExpresion* condition;
};

class DoWhile: public While{
public:
	//void generateByteCode();
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
};
/*
class For: public While {
public:
	For(AbstractExpresion* Initializer, AbstractExpresion* cond, AbstractExpresion* Increment, int line_);
	void semantic();
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj){};
private:
	Base* Initializer;
	Base* Increment;
};*/

#endif
