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
	OfxClass::OfxClass(string name, SuperClass* parent):SuperClass(101){
		this->parent=parent;
		this->setName(name);
	}
	OfxClass::~OfxClass(){};
		
	OfxObject* OfxClass::getNewInstance(){
		return new OfxObject(this->getOfxName(), this->getCache());
	}

	
//	class OfxObject: public SuperObject{
	OfxObject::OfxObject(string name, Super* obj):SuperObject(102, obj){
		this->setName(name);
	}
	OfxObject::~OfxObject(){
	}

}