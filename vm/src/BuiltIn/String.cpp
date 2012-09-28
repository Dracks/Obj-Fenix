//
//  String.cpp
//  vm
//
//  Created by Dracks on 25/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "String.h"
#include "Integer.h"

namespace ofxBI {
	using namespace SDK;
	
	registerClass(StringClass)
	
//	class StringClass: public SDK::SuperClass {
	StringClass::StringClass(): SuperClass(5){
		this->setName("String");
	}
	
	StringClass::~StringClass(){}
	
	StringObject* StringClass::getNewInstance(string v){
		return new StringObject(this, v);
	}
		
	void StringClass::ofxString(BICall* call){
		call->clearAndSetReturn(call->get<StringObject>(1));
	}
	
	std::map< std::string, SDK::Method * > StringClass::getRegisteredMethods(){
		map< string, Method*> ret=SuperClass::getRegisteredMethods();
		//ret[""]=new BIMethod<IntegerObject>("",,);
		ret["String(Object)"]=new BIMethod<StringClass>("String(Object)",1,&StringClass::ofxString);
		ret["add(String)"]=new BIMethod<StringObject>("add(String)",1,&StringObject::ofxAdd);
		ret["prefix(Integer)"]=new BIMethod<StringObject>("prefix(Integer)",1,&StringObject::ofxPrefix);
		ret["sufix(Integer)"]=new BIMethod<StringObject>("sufix(Integer)",1,&StringObject::ofxSufix);
		ret["substring(Integer, Integer)"]=new BIMethod<StringObject>("substring(Integer, Integer)",2,&StringObject::ofxSubstring);
		ret["length"]=new BIMethod<StringObject>("length",0,&StringObject::ofxLength);
		
		return ret;
	};
	
//	class StringObject: public SDK::Primitive<string> {
	StringObject::StringObject(StringClass* ci, string v): Primitive<string>(v,ci->getCache()){
		this->classInstance=ci;
	}
	
	StringObject::~StringObject(){}
	
	void StringObject::ofxAdd(BICall* call){
		string tmp=this->value;
		tmp+=call->get<StringObject>(1)->value;
		call->clearAndSetReturn( 
								classInstance->getNewInstance(tmp));
	}
	
	void StringObject::ofxPrefix(BICall* call){
		int tmp=call->get<IntegerObject>(1)->getValue();
		call->clearAndSetReturn(classInstance->getNewInstance(this->value.substr(0,tmp)));
	}
	
	void StringObject::ofxSufix(BICall* call){
		int tmp=call->get<IntegerObject>(1)->getValue();
		call->clearAndSetReturn(classInstance->getNewInstance(this->value.substr(tmp,0)));
	}
	
	void StringObject::ofxSubstring(BICall* call){
		int ini=call->get<IntegerObject>(1)->getValue();
		int size=call->get<IntegerObject>(2)->getValue();
		call->clearAndSetReturn(classInstance->getNewInstance(this->value.substr(ini,size)));
	}
	
	void StringObject::ofxLength(BICall* call){
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value.size()));
	}
	
	/*void StringObject::ofxSub(BICall* call){
		
	}
	void StringObject::ofxEqual(BICall* call){
		
	}//*/
}