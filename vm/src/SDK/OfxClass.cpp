//
//  ofxClass.cpp
//  vm
//
//  Created by Dracks on 17/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "OfxClass.h"
namespace SDK{
	//class OfxClass: public SuperClass{
	OfxClass::OfxClass(string name, SuperClass* parent):SuperClass(name){
		this->parent=parent;
	}
	OfxClass::~OfxClass(){};
		
	OfxObject* OfxClass::getNewInstance(){
		return new OfxObject(this->getOfxName(), this->getCache());
	}

	
//	class OfxObject: public SuperObject{
	OfxObject::OfxObject(string name, Super* obj):SuperObject(name, obj){
		
	}
	OfxObject::~OfxObject(){
	}

}