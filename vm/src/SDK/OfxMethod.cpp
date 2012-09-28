//
//  OfxMethod.cpp
//  vm
//
//  Created by Dracks on 17/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "OfxMethod.h"

namespace SDK{
	//class OfxMethod: public Method{
	OfxMethod::OfxMethod(int type, int line): Method(type){
			lineToCall=line;
		}
	
	OfxMethod::OfxMethod(string name, int line): Method(103){
		//cout << "ofxMethod " << name << " ( " << line << " ) " << endl;
		lineToCall=line;
		this->setName(name);
	}
	
	OfxMethod::~OfxMethod(){}

	int OfxMethod::call(ofxbytecode::Stack<Stackable*>*){
		//cout << "ofxCall" << endl;
		return lineToCall;
	}
	//};
	
	//class OfxConstructor: public OfxMethod{
	OfxConstructor::OfxConstructor(string name, int line, OfxClass* base): OfxMethod(104, line){
		this->base=base;
		this->setName(name);
	}
	
	OfxConstructor::~OfxConstructor(){}
		
	
	int OfxConstructor::call(ofxbytecode::Stack<Stackable*>* stack){
		//Accedir a la clase OfxClass i generar nova instancia
		//cout << "calling constructor " << endl;
		stack->pop();
		stack->push(base->getNewInstance());
		return lineToCall;
	}
	//};
}