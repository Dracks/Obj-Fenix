//
//  SuperGlue.h
//  vm
//
//  Created by Dracks on 19/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Adapter_h
#define vm_Adapter_h

namespace tools{
	class Adapter;
	class CacheClass;
	class NativeCacheClass;
}

#include "../classes/Library.h"

namespace tools {
	class Adapter {
	private:
		static Library* data;
		
		map<string, SuperClass*> ofxDataCache;
		vector<CacheClass*> biDataCache;
		
		
		
	public:
		static Library* getData();
		
		void applyNative(NativeCacheClass*);
		void applyOfx(OfxCacheClass*);
		
		Adapter();
		~Adapter();
		
		void registerClass(SuperClass*);
		void assignClass(CacheClass*);
		
		void apply();
		
	}
	
	class CacheClass {
		friend class Adapter;
	private:
		int ID;
		string name;
	public:
		CacheClass(int, string);
		virtual ~CacheClass();
		virtual void apply(Adapter*)=0;
	}
	
	class NativeCacheClass: public CacheClass {
	private:
		vector<pair<int, string> > methods;
	public:
		vector<pair<int, string> > getListMethod();
		void addMethod(int, string);
		
		void apply(Adapter*);
	}
	
	class OfxCacheMethod {
		friend class Adapter;
	private:
		int ID;
		string name;
		int line;
	public:
		
		OfxCacheMethod(int, string, int);
		virtual ~OfxCacheMethod();
	}
	
	class OfxCacheClass: public CacheClass {
	private:
		int parent;
		vector<OfxCacheMethod*> methods;
	public:
		OfxCacheClass(int, string, int);
		void apply(Adapter*);
		void addMethod(OfxCacheMethod*);
	}
}


#endif
