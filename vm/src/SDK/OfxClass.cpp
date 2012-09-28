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
		//cout << "puta mierda!" << this->getCache() << endl;
		return new OfxObject(this->getOfxName(), this->getCache());
	}

	
//	class OfxObject: public SuperObject{
	OfxObject::OfxObject(string name, ofxMap* obj):SuperObject(102, obj){
		//cout << "Ei que això es així" << obj << endl;
		this->setName(name);
	}
	OfxObject::~OfxObject(){
	}

}