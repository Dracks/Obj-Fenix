//
//  Cache.cpp
//  vm
//
//  Created by Dracks on 27/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>


namespace tools {
//	class CacheClass {
	CacheClass::CacheClass(int, string);
	CacheClass::~CacheClass();
		void CacheClass::apply(Adapter*)=0;
		string CacheClass::getName();
		int CacheClass::getUID();
		
		void CacheClass::addProperty(int uid, string name);
		vector<pair<int, string> > CacheClass::getProperties();
	
//	class NativeCacheClass: public CacheClass {
	vector<pair<int, string> > NativeCacheClass::getListMethod(){
	}
	void NativeCacheClass::addMethod(int, string){}
		
	void NativeCacheClass::apply(Adapter*){}
	
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