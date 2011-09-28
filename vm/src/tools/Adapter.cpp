//
//  Adapter.cpp
//  vm
//
//  Created by Dracks on 19/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>


namespace tools{
	using namespace SDK;
	using namespace ofxbytecode;
	//class Adapter {
	Adapter::Adapter();
	Adapter::~Adapter();
		
	void Adapter::applyNative(NativeCacheClass* cache){
		
	}
	
	void Adapter::applyOfx(OfxCacheClass* cache){
		Library* lib=Library::getData()
		OfxClass* obj=new OfxClass(cache->getName(), lib->getClass(cache->getParent()));
		
		
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
		}
	}
		
}