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


namespace tools {
//	class CacheClass {
	CacheClass::CacheClass(int, string){

        }

	CacheClass::~CacheClass(){}

        string CacheClass::getName(){
            return this->name;

        }
        int CacheClass::getUID(){
            return this->ID;
        }
		
        void CacheClass::addProperty(int uid, string name){
            this->properties.push_back(new pair<int, string>(uid, name));
        }

        vector<pair<int, string> > CacheClass::getProperties(){
            return this->properties;
        }
	
//	class NativeCacheClass: public CacheClass {
	vector<pair<int, string> > NativeCacheClass::getListMethod(){
            return this->methods;
	}
	void NativeCacheClass::addMethod(int id, string name){
            this->methods.push_back(new pair(id, name));
        }
		
	void NativeCacheClass::apply(Adapter* obj){
            obj->applyNative(this);
        }
	
//	class OfxCacheMethod {
		
	OfxCacheMethod::OfxCacheMethod(int, string, int){}
	
	void OfxCacheMethod::setConstructor(bool v){}
	
	void OfxCacheMethod::setIsStatic(bool v){}
	
	OfxCacheMethod::~OfxCacheMethod(){}
	
//	class OfxCacheClass: public CacheClass {
	OfxCacheClass::OfxCacheClass(int, string, int){}
	
	void OfxCacheClass::apply(Adapter*){}
	
	void OfxCacheClass::addMethod(OfxCacheMethod*){}
	
	int OfxCacheClass::getParent(){}
	
	vector<OfxCacheMethod*> OfxCacheClass::getMethods(){}
}