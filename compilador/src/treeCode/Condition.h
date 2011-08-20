/*
 *  condition.h
 *  compilador
 *
 *  Created by Jaume Singla Valls on 03/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef CONDITION_H
#define CONDITION_H

#include "Base.h"
#include <iostream>
#include <vector>
#include "Expresion.h"
using namespace std;

class Condition: public Base{
public:
	Condition(AbstractExpresion* cond_, Base* alt_, int line_):Base(line_){
		condition=cond_;
		alternative=alt_;
	}
	void semantic();
	void addSentence(Base* sent){code.push_back(sent);}
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
private:
	AbstractExpresion* condition;
	vector<Base*> code;
	Base* alternative;
};

class Else: public Base{
public:
	Else(int line_): Base(line_){}
	void addSentence(Base* sent){code.push_back(sent);}
	void semantic();
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
private:
	vector<Base*> code;
};

#endif