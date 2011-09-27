//
//  Boolean.cpp
//  vm
//
//  Created by Dracks on 18/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Boolean.h"

namespace ofxBI{
	//class BooleanClass: public SDK::SuperClass {
	BooleanObject::BooleanClass(){}
	
	BooleanObject::~BooleanClass(){}
	
	void ofxBoolean(BuiltInCall* call){
		call->clearAndSetReturn(call->get<IntegerObject>(1));
	}
	BooleanObject::BooleanClass* getNewInstance(bool v){
		return new IntegerObject(v, DataCache);
	}
	
	//class BooleanObject: public SDK::Primitive<bool> {
	BooleanObject::BooleanObject(bool v, SuperObject* base): Primitive(v, base){
		
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
}