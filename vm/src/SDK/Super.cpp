//
//  Super.cpp
//  vm
//
//  Created by Dracks on 17/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Super.h"

namespace SDK{
	//class Method: public Stackable{
	
	Method::Method(std::string name): Stackable(name,0){};
	Method::~Method(){}
		
		
	//int Method:call(ofxbytecode::Stack<Stackable*>*)=0;

	
	
	//class Super: public Stackable{
	
	Super::Super(std::string name): Stackable(name,0){};
	Super::~Super(){};
		
	std::vector<Method*> Super::getMethodList(){};
	
	//inline 
	void Super::addMethod(std::string name, int uid, Method* method){
		this->methodList[uid]=method;
		this->methodTranslate[name]=uid;
	};
		
	//inline 
	void Super::addProperty(std::string name, int uid){
		this->propertyList[uid]=NULL;
		this->propertyTranslate[name]=uid;
	}
	
	//inline 
	void Super::copyContents(Super* instance){
		this->methodList=instance->methodList;
		this->propertyList=instance->propertyList;
		this->methodTranslate=instance->methodTranslate;
		this->propertyTranslate=instance->propertyTranslate;
	}
		
	//inline 
	Method* Super::getMethod(int uid){
		return this->methodList[uid];
	}
		
	//inline 
	Method* Super::getMethod(std::string name){
		return this->methodList[this->methodTranslate[name]];
	}
	
	int Super::getMethodUid(std::string name){
		return this->methodTranslate[name];
	}
		
	//inline 
	SuperObject* Super::getProperty(int uid){
		return this->propertyList[uid];
	}
		
	//inline 
	SuperObject* Super::getProperty(std::string name){
		return this->propertyList[this->propertyTranslate[name]];
	}
		
	//inline 
	void Super::storePropiety(int uid, SuperObject* obj){
		this->propertyList[uid]=obj;
	}
		
}