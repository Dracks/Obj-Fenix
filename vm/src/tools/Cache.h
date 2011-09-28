//
//  Cache.h
//  vm
//
//  Created by Dracks on 27/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Cache_h
#define vm_Cache_h
namespace tools{
	class CacheClass;
	class NativeCacheClass;
	class OfxCacheMethod;
	class OfxCacheClass;
}

#include "Adapter.h"

namespace tools {
	class CacheClass {
		//friend class Adapter;
	private:
		int ID;
		string name;
	public:
		CacheClass(int, string);
		virtual ~CacheClass();
		virtual void apply(Adapter*)=0;
		string getName();
		int getUid();
	};
	
	class NativeCacheClass: public CacheClass {
	private:
		vector<pair<int, string> > methods;
	public:
		vector<pair<int, string> > getListMethod();
		void addMethod(int, string);
		
		void apply(Adapter*);
	};
	
	class OfxCacheMethod {
		friend class Adapter;
	private:
		int ID;
		string name;
		int line;
	public:
		
		OfxCacheMethod(int, string, int);
		virtual ~OfxCacheMethod();
	};
	
	class OfxCacheClass: public CacheClass {
	private:
		int parent;
		vector<OfxCacheMethod*> methods;
	public:
		OfxCacheClass(int, string, int);
		void apply(Adapter*);
		void addMethod(OfxCacheMethod*);
		int getParent();
		vector<OfxCacheMethod*> getMethods();
	};
}
#endif
