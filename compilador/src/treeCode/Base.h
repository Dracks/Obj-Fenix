/*
 *  Base.h
 *  compilador
 *
 *  Created by dracks on 27/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef BASE_H
#define BASE_H

#include "../generator/OFXByteCode.h"
using namespace std;

class Base{
private:
	int line;
public:
	Base(int line_){line=line_;};
	virtual void semantic()=0;
	virtual ~Base(){};
	virtual int getLine(){return line;};
	virtual bool isReturn(){return false;};
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj){return obj->getJmpQueue();};
};

#endif