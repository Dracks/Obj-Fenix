//
//  Cache.cpp
//  vm
//
//  Created by Dracks on 27/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Cache.h"


namespace ofxtools {
//	class CacheClass {
	CacheClass::CacheClass(int id, string name){
            this->ID=id;
            this->name=name;
        }

	CacheClass::~CacheClass(){}

        string CacheClass::getName(){
            return this->name;

        }
        int CacheClass::getUID(){
            return this->ID;
        }
		
        void CacheClass::addProperty(int uid, string name){
            this->properties.push_back(make_pair(uid, name));
        }

        vector<pair<int, string> > CacheClass::getProperties(){
            return this->properties;
        }
	
//	class NativeCacheClass: public CacheClass {
	vector<pair<int, string> > NativeCacheClass::getListMethod(){
            return this->methods;
	}
	void NativeCacheClass::addMethod(int id, string name){
            this->methods.push_back(make_pair(id, name));
        }
		
	void NativeCacheClass::apply(Adapter* obj){
            obj->applyNative(this);
        }
	
//	class OfxCacheMethod {
		
	OfxCacheMethod::OfxCacheMethod(int id, string name, int line) {
		this->ID=id;
		this->name=name;
		this->line=line;
		this->constructor=false;
        }

	OfxCacheMethod::~OfxCacheMethod(){}
	
	void OfxCacheMethod::setConstructor(bool v){
		this->constructor=v;
	}
	
	void OfxCacheMethod::setIsStatic(bool v){
		this->isStatic=v;
	}
	
//	class OfxCacheClass: public CacheClass {
	OfxCacheClass::OfxCacheClass(int id, string name, int parent): CacheClass(id, name){
		this->parent=parent;
	}
	
	void OfxCacheClass::apply(Adapter* obj){
		obj->applyOfx(this);
	}
	
	void OfxCacheClass::addMethod(OfxCacheMethod* method){
		this->methods.push_back(method);
	}
	
	int OfxCacheClass::getParent(){
		return this->parent;
	}
	
	vector<OfxCacheMethod*> OfxCacheClass::getMethods(){
		return this->methods;
	}
}