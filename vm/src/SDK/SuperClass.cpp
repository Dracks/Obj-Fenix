//
//  SuperClass.cpp
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "SuperClass.h"

namespace SDK{
	using namespace std;
	//class SuperClass: public Super{
	SuperClass::SuperClass(int type):Super(type){
		//this->ofxName=name;
		this->instanceInfo=new ofxMap(type);
	};
	
	void SuperClass::setName(string name){
		this->ofxName=name;
		Stackable::setName(name+" Class");
	};
	
	SuperClass::~SuperClass(){
		delete this->instanceInfo;
		
	};
		
	ofxMap* SuperClass::getCache(){
		return this->instanceInfo;
	};
		
	std::map<std::string, Method*> SuperClass::getRegisteredMethods(){
		std::map<std::string, Method*> ret;
		return ret;
	};
		
	//inline 
	void SuperClass::addInstanceMethod(string name, int uid, Method* method){
		//cout << "addInstanceMethod: " << name << endl;
		this->instanceInfo->addMethod(name, uid, method);
	};
	
	//inline 
	void SuperClass::addInstanceProperty(string name, int uid){
		this->instanceInfo->addProperty(name, uid);
	};
	
	string SuperClass::getOfxName(){
		return ofxName;
	};
	
}