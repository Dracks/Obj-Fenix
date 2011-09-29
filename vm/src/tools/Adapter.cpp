//
//  Adapter.cpp
//  vm
//
//  Created by Dracks on 19/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Adapter.h"

namespace ofxtools{
	using namespace SDK;
	using namespace ofxbytecode;
	
	//class Adapter {
	Adapter::Adapter(){};
	Adapter::~Adapter(){};
		
	void Adapter::applyProperties(SuperClass* obj, CacheClass* cache){
		vector<pair<int, string> > listProperties=cache->getProperties();
		for (unsigned int i=0; i<listProperties.size(); i++){
			obj->addInstanceProperty(listProperties[i].second, listProperties[i].first);
		}
	}
	
	void Adapter::applyNative(NativeCacheClass* cache){
		Library* lib=Library::getData()
		
		map<string, SuperClass*>::iterator found=ofxDataCache.find(cache->getName());
		if (found==biDataCache.end()){
			/// @TODO L'em ben liat-> Fer algun tipus d'excepció amb warnings i aquestes historietes
		}
		SuperClass* obj=found->second;
		map<string, Method*> biMethodList=obj->getRegisteredMethods();
		vector<pair<int, string> > ofxMethodList=cache->getListMethod();
		for (unsigned int i=0; i<ofxMethodList.size(); i++){
			map<string, SuperClass*>::iterator found=biMethodList.find(ofxMethodList[i].second);
			if (found==biDataCache.end()){
				/// @TODO L'em ben liat2-> Fer algun tipus d'excepció amb warnings i aquestes historietes
			}
			/// @TODO Make a new class for know when is static and isn't static, and others things. 
			obj->addInstanceMethod(ofxMethodList[i].second, ofxMethodList[i].first, *found);
		}
		
		this->applyProperties(obj, cache);
		
		lib->addClass(cache->getUID(), cache->getName(), obj);	
	}
	
	void Adapter::applyOfx(OfxCacheClass* cache){
		Library* lib=Library::getData()
		OfxClass* obj=new OfxClass(cache->getName(), lib->getClass(cache->getParent()));
		vector<OfxCacheMethod*> listMethods=cache->getMethodList();
		for (unsigned int i=0; i<listMethods.size(); i++){
			OfxCacheMethod* cacheMethod=listMethods[i];
			if (cacheMethod->isStatic){
				obj->addMethod(cacheMethod->getName(), cacheMethod->getUID(), new OfxMethod(cacheMethod->getName(), cacheMethod->getLine()));
			} else if (cacheMethod->isConstructor) {
				obj->addMethod(cacheMethod->getName(), cacheMethod->getUID(), new OfxConstructor(cacheMethod->getName(), cacheMethod->getLine()));
			} else {
				obj->addInstanceMethod(cacheMethod->getName(), cacheMethod->getUID(), new OfxMethod(cacheMethod->getName(), cacheMethod->getLine()));
			}
			//delete cacheMethod;
		}
		
		this->applyProperties(obj, cache);
		
		lib->addClass(cache->getUID(), cache->getName(), obj);
	}
	
	void Adapter::registerClass(SuperClass* c){
		ofxDataCache[c->getName()]=c;
	}
	
	void Adapter::assignClass(CacheClass* c){
		biDataCache.push_back(c);
	}
	
	void Adapter::apply(){
		unsigned int i;
		for (i=0; i<biDataCache.size(); i++){
			biDataCache[i]->apply();
			delete biDataCache[i];
		}
		biDataCache.clear();
	}
		
}