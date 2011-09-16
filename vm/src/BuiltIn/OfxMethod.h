//
//  ofxMethod.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_ofxMethod_h
#define vm_ofxMethod_h

class BIMethod;

#include "Super.h"

class OfxMethod: public Method{
private:
	int lineToCall;
public:
	OfxMethod(int line){
		lineToCall=line;
	}
	virtual ~OfxMethod(){}
	virtual int call(Stack<Stackable>*){
		return lineToCall;
	}
}

#endif
