//
//  String.cpp
//  vm
//
//  Created by Dracks on 25/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

namespace ofxBI {
	
//	class StringClass: public SDK::SuperClass {
	StringClass::StringClass(){}
	StringClass::~StringClass(){}
	StringObject* StringClass::getNewInstance(string v){
		return new StringObject(v, DataCache);
	}
		
	void StringClass::ofxString(BuiltInCall* call){
		call->clearAndSetReturn(call->get<StringObject>(1));
	}
	
//	class StringObject: public SDK::Primitive<string> {
	StringClass::StringObject(int v, SuperObject* base): Primitive(v,base){}
	StringClass::~StringObject(){}
	void StringClass::ofxAdd(BICall* call){
		string tmp=this->value;
		tmp+=call->get<StringClass>(1)->value;
		call->clearAndSetReturn( checkAndCast<StringClass>(ofxbytecode::Library::getData()->getClass("String"))->getNewInstance(tmp));
	}
	
	/*void StringClass::ofxSub(BICall* call){
		
	}
	void StringClass::ofxEqual(BICall* call){
		
	}//*/
//}