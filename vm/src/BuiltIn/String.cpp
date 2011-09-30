//
//  String.cpp
//  vm
//
//  Created by Dracks on 25/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "String.h"

namespace ofxBI {
	using namespace SDK;
//	class StringClass: public SDK::SuperClass {
	StringClass::StringClass(){}
	StringClass::~StringClass(){}
	StringObject* StringClass::getNewInstance(string v){
		return new StringObject(v, this->getCache());
	}
		
	void StringClass::ofxString(BICall* call){
		call->clearAndSetReturn(call->get<StringObject>(1));
	}
	
//	class StringObject: public SDK::Primitive<string> {
	StringObject::StringObject(string v, SuperObject* base): Primitive<string>(v,base){}
	
	StringObject::~StringObject(){}
	
	void StringObject::ofxAdd(BICall* call){
		string tmp=this->value;
		tmp+=call->get<StringObject>(1)->value;
		call->clearAndSetReturn( 
								checkAndCast<StringClass>(ofxbytecode::Library::getLibrary()->getClass("String"))->getNewInstance(tmp));
	}
	
	/*void StringObject::ofxSub(BICall* call){
		
	}
	void StringObject::ofxEqual(BICall* call){
		
	}//*/
}