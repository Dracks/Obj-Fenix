//
//  Boolean.cpp
//  vm
//
//  Created by Dracks on 18/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Boolean.h"
#include "../SDK/BIMethod.h"

namespace ofxBI{
	
	registerClass(BooleanClass);
	
	using namespace SDK;
	using namespace std;
	//class BooleanClass: public SDK::SuperClass {
	BooleanClass::BooleanClass():SuperClass(1){
		bTrue=NULL;
		bFalse=NULL;
		this->setName("Boolean");
	}
	
	BooleanClass::~BooleanClass(){}
	
	void BooleanClass::ofxBoolean(BICall* call){
		call->clearAndSetReturn(call->get<BooleanObject>(1));
	}
	BooleanObject* BooleanClass::getNewInstance(bool v){
		if (bTrue==NULL){
			bTrue=new BooleanObject(true, this->getCache());
			bFalse=new BooleanObject(false, this->getCache());
		} 
		if (v){
			return bTrue;
		} else {
			return bFalse;
		}
		 
		//return new BooleanObject(v, this->getCache());
	}
	
	map< std::string, Method * > BooleanClass::getRegisteredMethods(){
		map< string, Method*> ret=SuperClass::getRegisteredMethods();
		ret["Boolean(Object)"]=new BIMethod<BooleanClass>("Boolean(Object)",1,&BooleanClass::ofxBoolean);
		ret["and(Boolean)"]=new BIMethod<BooleanObject>("and(Boolean)",1,&BooleanObject::ofxAnd);
		ret["or(Boolean)"]=new BIMethod<BooleanObject>("or(Boolean)",1,&BooleanObject::ofxOr);
		
		return ret;
	}
	
	//class BooleanObject: public SDK::Primitive<bool> {
	BooleanObject::BooleanObject(bool v, SuperObject* base): Primitive<bool>(v, base){
		
	}

	BooleanObject::~BooleanObject(){}
	
	void BooleanObject::ofxAnd(BICall* call){
		/*bool tmp=call->get<BooleanObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<BooleanClass>(tools::Adapter::getData()->getClass("Boolean"))->getNewInstance(this->value && tmp));
		 */
		
		if (value) {
			call->clearAndSetReturn(call->get<BooleanObject>(1));
		} else {
			call->clearAndSetReturn(this);
		}
	}
	
	void BooleanObject::ofxOr(BICall* call){
		/*bool tmp=call->get<BooleanObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<BooleanClass>(tools::Adapter::getData()->getClass("Boolean"))->getNewInstance(this->value || tmp));*/
		
		if (value) {
			call->clearAndSetReturn(this);
		} else {
			call->clearAndSetReturn(call->get<BooleanObject>(1));
		}
	}
};