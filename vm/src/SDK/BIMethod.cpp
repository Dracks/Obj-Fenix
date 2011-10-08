//
//  BIMethod.cpp
//  vm
//
//  Created by Dracks on 17/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "BIMethod.h"

namespace SDK{
	using namespace std;
	// template<class Template> class BIMethod: public Method{
	//	class BICall{
	BICall::BICall(string name, ofxbytecode::Stack<Stackable*>* stack, int arguments){
		this->name=name;
		this->stack=stack;
		this->nArguments=arguments;
		this->baseStack=stack->getTop()-arguments;
	}
	
	BICall::~BICall(){};
	
	
	void BICall::clear(){
		this->stack->reseTop(baseStack);
	}
	
	void BICall::clearAndSetReturn(Super* retValue){
		this->clear();
		this->stack->set(stack->getTop(), retValue);
	}
	
}