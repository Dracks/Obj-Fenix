//
//  Adapter.cpp
//  vm
//
//  Created by Dracks on 19/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Adapter.h"

#include "../SDK/OfxClass.h"
#include "../SDK/OfxMethod.h"

namespace ofxtools{
	using namespace SDK;
	using namespace ofxbytecode;
	using namespace std;
	
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
		Library* lib=Library::getLibrary();
		
		map<string, SuperClass*>::iterator found;
		found=ofxDataCache.find(cache->getName());
		if (found==ofxDataCache.end()){
			cerr << "Warning: Clase no disponible " << cache->getName() << endl;
			/// @TODO L'em ben liat-> Fer algun tipus d'excepció amb warnings i aquestes historietes
		}else {
			SuperClass* obj=found->second;
			map<string, Method*> biMethodList=obj->getRegisteredMethods();
			vector<pair<int, string> > ofxMethodList=cache->getListMethod();
			for (unsigned int i=0; i<ofxMethodList.size(); i++){
				map<string, Method*>::iterator found=biMethodList.find(ofxMethodList[i].second);
				if (found==biMethodList.end()){
					cerr << "Warning: Metode no disponible "<< ofxMethodList[i].second <<"en" << cache->getName() << endl;
					/// @TODO L'em ben liat2-> Fer algun tipus d'excepció amb warnings i aquestes historietes
				} else {
					/// @TODO Make a new class for know when is static and isn't static, and others things. 
					obj->addInstanceMethod(ofxMethodList[i].second, ofxMethodList[i].first, found->second);
				}
			}
			this->applyProperties(obj, cache);
			
			lib->addClass(cache->getUID(), cache->getName(), obj);
		}
	}
	
	void Adapter::applyOfx(OfxCacheClass* cache){
		Library* lib=Library::getLibrary();
		OfxClass* obj=new OfxClass(cache->getName(), lib->getClass(cache->getParent()));
		vector<OfxCacheMethod*> listMethods=cache->getMethods();
		for (unsigned int i=0; i<listMethods.size(); i++){
			OfxCacheMethod* cacheMethod=listMethods[i];
			if (cacheMethod->isStatic){
				obj->addMethod(cacheMethod->name, cacheMethod->ID, new OfxMethod(cacheMethod->name, cacheMethod->line));
			} else if (cacheMethod->constructor) {
				obj->addMethod(cacheMethod->name, cacheMethod->ID, new OfxConstructor(cacheMethod->name, cacheMethod->line));
			} else {
				obj->addInstanceMethod(cacheMethod->name, cacheMethod->ID, new OfxMethod(cacheMethod->name, cacheMethod->line));
			}
			//delete cacheMethod;
		}
		
		this->applyProperties(obj, cache);
		
		lib->addClass(cache->getUID(), cache->getName(), obj);
	}
	
	void Adapter::addClass(SuperClass* c){
		ofxDataCache[c->getOfxName()]=c;
	}
	
	void Adapter::assignClass(CacheClass* c){
		biDataCache.push_back(c);
	}
	
	void Adapter::apply(){
		unsigned int i;
		for (i=0; i<biDataCache.size(); i++){
			biDataCache[i]->apply(this);
			delete biDataCache[i];
		}
		biDataCache.clear();
	}
		
}