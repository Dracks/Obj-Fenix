//
//  Integer.cpp
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Integer.h"
#include "String.h"
#include "../tools.h"

using namespace SDK;

namespace ofxBI{
	
	
	registerClass(IntegerClass);
	//ofxtools::RegisterClass<ofxBI::IntegerClass> startupInteger();
	
	//class IntegerClass: public SDK::SuperClass {
	IntegerClass::IntegerClass():SuperClass(3){
		this->setName("Integer");
		cache=NULL;
	}
	IntegerClass::~IntegerClass(){}
	
	void IntegerClass::ofxInteger(BICall* call){
		call->clearAndSetReturn(call->get<IntegerObject>(1));
	}
	
	void IntegerClass::ofxIntegerFromString(BICall* call){
		StringObject* str=call->get<StringObject>(1);
		call->clearAndSetReturn(this->getNewInstance(atoi(str->getValue().c_str())));
	}
	
	IntegerObject* IntegerClass::getNewInstance(int v){
		if (cache==NULL){
			cache=new IntegerObject(v, this->getCache());
		}
		IntegerObject* ret=new IntegerObject(*cache);
		ret->setValue(v);
		return ret;
		//return new IntegerObject(v, this->getCache());
	}
	
	std::map< std::string, SDK::Method * > IntegerClass::getRegisteredMethods(){
		map< string, Method*> ret=SuperClass::getRegisteredMethods();
		
		ret["Integer(Object)"]=new BIMethod<IntegerClass>("Integer(Object)",1,&IntegerClass::ofxInteger);
		ret["Integer(String)"]=new BIMethod<IntegerClass>("Integer(String)",1,&IntegerClass::ofxIntegerFromString);
		ret["inc"]=new BIMethod<IntegerObject>("inc",0,&IntegerObject::ofxInc);
		
		ret["dec"]=new BIMethod<IntegerObject>("dec",0,&IntegerObject::ofxDec);
		
		ret["add(Integer)"]=new BIMethod<IntegerObject>("add(Integer)",1,&IntegerObject::ofxAdd);
		ret["sub(Integer)"]=new BIMethod<IntegerObject>("sub(Integer)",1,&IntegerObject::ofxSub);
		ret["mul(Integer)"]=new BIMethod<IntegerObject>("mul(Integer)",1,&IntegerObject::ofxMul);
		ret["div(Integer)"]=new BIMethod<IntegerObject>("div(Integer)",1,&IntegerObject::ofxDiv);
		ret["equal(Integer)"]=new BIMethod<IntegerObject>("equal(Integer)",1,&IntegerObject::ofxEqual);
		ret["dif(Integer)"]=new BIMethod<IntegerObject>("dif(Integer)",1,&IntegerObject::ofxDif);
		ret["lower(Integer)"]=new BIMethod<IntegerObject>("lower(Integer)",1,&IntegerObject::ofxLower);
		ret["greater(Integer)"]=new BIMethod<IntegerObject>("greater(Integer)",1,&IntegerObject::ofxGreater);
		ret["toString"]=new BIMethod<IntegerObject>("toString",0,&IntegerObject::ofxToString);
		//ret[""]=new BIMethod<IntegerObject>("",,);
		
		return ret;
	};
	
	
	//	class IntegerObject: public SDK::Primitive<int> {
	IntegerObject::IntegerObject(int v, ofxMap* base): Primitive<int>(v,base){}
	
	IntegerObject::~IntegerObject(){}
	
	void IntegerObject::ofxInc(SDK::BICall* call){
		this->value++;
		call->clearAndSetReturn(this);
	};
	
	void IntegerObject::ofxDec(SDK::BICall* call){
		this->value--;
		call->clearAndSetReturn(this);
	};
	
	void IntegerObject::ofxAdd(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value+tmp));
	}
	
	
	void IntegerObject::ofxSub(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value+tmp));
		
	}
	
	void IntegerObject::ofxMul(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value*tmp));
	}
	
	void IntegerObject::ofxDiv(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value+tmp));
		
	}
	
	void IntegerObject::ofxDif(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<BooleanClass>(ofxbytecode::Library::getLibrary()->getClass("Boolean"))->getNewInstance(this->value!=tmp));
	}
	
	void IntegerObject::ofxEqual(BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<BooleanClass>(ofxbytecode::Library::getLibrary()->getClass("Boolean"))->getNewInstance(this->value==tmp));
	}
	
	void IntegerObject::ofxLower(SDK::BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		BooleanObject* test=checkAndCast<BooleanClass>(ofxbytecode::Library::getLibrary()->getClass("Boolean"))->getNewInstance(this->value<tmp);
		//std::cout << "Debug: " <<  test->getValue() << endl;
		call->clearAndSetReturn(test);
	};
	
	void IntegerObject::ofxGreater(SDK::BICall* call){
		int tmp=call->get<IntegerObject>(1)->value;
		BooleanObject* test=checkAndCast<BooleanClass>(ofxbytecode::Library::getLibrary()->getClass("Boolean"))->getNewInstance(this->value>tmp);
		//std::cout << "Debug: " <<  test->getValue() << endl;
		call->clearAndSetReturn(test);
	};
	
	void IntegerObject::ofxToString(SDK::BICall* call){
		//int tmp=call->get<IntegerObject>(1)->value;
		call->clearAndSetReturn(checkAndCast<StringClass>(ofxbytecode::Library::getLibrary()->getClass("String"))->getNewInstance(convert<int>(this->value)));
	};
}