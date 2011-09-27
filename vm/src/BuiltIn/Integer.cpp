//
//  Integer.cpp
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Integer.h"

namespace ofxBI{
	
	//class IntegerClass: public SDK::SuperClass {
	IntegerClass::IntegerClass(){}
	IntegerClass::~IntegerClass(){}
	void IntegerClass::ofxInteger(BuiltInCall* call){
		call->clearAndSetReturn(call->get<IntegerObject>(1));
	}
	IntegerObject* IntegerClass::getNewInstance(int v){
		return new IntegerObject(v, DataCache);
	}
	
	
	//	class IntegerObject: public SDK::Primitive<int> {
	IntegerObject::IntegerObject(int v, SuperObject* base): Primitive(v,base){}
	
	IntegerObject::~IntegerObject(){}
	
	void IntegerObject::ofxAdd(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getData()->getClass("Integer"))->getNewInstance(this->value+tmp));
	}
	void IntegerObject::ofxSub(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getData()->getClass("Integer"))->getNewInstance(this->value+tmp));
		
	}
	void IntegerObject::ofxEqual(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<BooleanClass>(ofxbytecode::Library::getData()->getClass("Boolean"))->getNewInstance(this->value==tmp));
	}
}