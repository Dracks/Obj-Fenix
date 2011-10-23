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
	
	registerClass(StringClass)
	
//	class StringClass: public SDK::SuperClass {
	StringClass::StringClass(): SuperClass(5){
		this->setName("String");
	}
	
	StringClass::~StringClass(){}
	
	StringObject* StringClass::getNewInstance(string v){
		return new StringObject(v, this->getCache());
	}
		
	void StringClass::ofxString(BICall* call){
		call->clearAndSetReturn(call->get<StringObject>(1));
	}
	
	std::map< std::string, SDK::Method * > StringClass::getRegisteredMethods(){
		map< string, Method*> ret=SuperClass::getRegisteredMethods();
		//ret[""]=new BIMethod<IntegerObject>("",,);
		ret["String(Object)"]=new BIMethod<StringClass>("String(Object)",1,&StringClass::ofxString);
		ret["add(String)"]=new BIMethod<StringObject>("add(String)",1,&StringObject::ofxAdd);
		
		return ret;
	};
	
//	class StringObject: public SDK::Primitive<string> {
	StringObject::StringObject(string v, ofxMap* base): Primitive<string>(v,base){}
	
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