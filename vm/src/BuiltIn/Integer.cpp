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
	using namespace SDK;
	
	registerClass(IntegerClass);
	
	//class IntegerClass: public SDK::SuperClass {
	IntegerClass::IntegerClass():SuperClass("Integer"){}
	IntegerClass::~IntegerClass(){}
	
	void IntegerClass::ofxInteger(BICall* call){
		call->clearAndSetReturn(call->get<IntegerObject>(1));
	}
	
	IntegerObject* IntegerClass::getNewInstance(int v){
		return new IntegerObject(v, this->getCache());
	}
	
	std::map< std::string, SDK::Method * > IntegerClass::getRegisteredMethods(){
		map< string, Method*> ret=SuperClass::getRegisteredMethods();
		
		ret["Integer(Object)"]=new BIMethod<IntegerClass>("Integer(Object)",1,&IntegerClass::ofxInteger);
		ret["add(Integer)"]=new BIMethod<IntegerObject>("add(Integer)",1,&IntegerObject::ofxAdd);
		ret["sub(Integer)"]=new BIMethod<IntegerObject>("sub(Integer)",1,&IntegerObject::ofxSub);
		ret["equal(Integer)"]=new BIMethod<IntegerObject>("equal(Integer)",1,&IntegerObject::ofxEqual);
		//ret[""]=new BIMethod<IntegerObject>("",,);
		
		return ret;
	};
	
	
	//	class IntegerObject: public SDK::Primitive<int> {
	IntegerObject::IntegerObject(int v, SuperObject* base): Primitive<int>(v,base){}
	
	IntegerObject::~IntegerObject(){}
	
	void IntegerObject::ofxAdd(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value+tmp));
	}
	void IntegerObject::ofxSub(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value+tmp));
		
	}
	void IntegerObject::ofxEqual(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<BooleanClass>(ofxbytecode::Library::getLibrary()->getClass("Boolean"))->getNewInstance(this->value==tmp));
	}
}