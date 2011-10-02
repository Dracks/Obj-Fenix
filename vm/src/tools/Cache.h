//
//  Cache.h
//  vm
//
//  Created by Dracks on 27/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Cache_h
#define vm_Cache_h
namespace ofxtools{
	class CacheClass;
	class NativeCacheClass;
	class OfxCacheMethod;
	class OfxCacheClass;
};

#include "Adapter.h"

namespace ofxtools {
	class CacheClass {
		//friend class Adapter;
	private:
		int ID;
		std::string name;
		std::vector<std::pair<int, std::string> > properties;
	public:
		CacheClass(int, std::string);
		virtual ~CacheClass();
		virtual void apply(Adapter*)=0;
		virtual std::string getName();
		virtual int getUID();
		
		virtual void addProperty(int uid, std::string name);
		virtual std::vector<std::pair<int, std::string> > getProperties();
	};
	
	class NativeCacheClass: public CacheClass {
	private:
		std::vector<std::pair<int, std::string> > methods;
	public:
		NativeCacheClass(int, std::string);
		~NativeCacheClass();
		std::vector<std::pair<int, std::string> > getListMethod();
		void addMethod(int, std::string);
		
		virtual void apply(Adapter*);
	};
	
	class OfxCacheMethod {
		friend class Adapter;
	private:
		int ID;
		std::string name;
		int line;
		bool constructor;
		bool isStatic;
	public:
		
		OfxCacheMethod(int, std::string, int);
		void setConstructor(bool v);
		void setIsStatic(bool v);
		virtual ~OfxCacheMethod();
	};
	
	class OfxCacheClass: public CacheClass {
	private:
		int parent;
		std::vector<OfxCacheMethod*> methods;
	public:
		OfxCacheClass(int, std::string, int);
		~OfxCacheClass();
		virtual void apply(Adapter*);
		void addMethod(OfxCacheMethod*);
		int getParent();
		std::vector<OfxCacheMethod*> getMethods();
	};
};
#endif
