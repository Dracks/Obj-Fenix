//
//  List.h
//  vm
//
//  Created by Dracks on 28/09/12.
//
//

#ifndef __vm__List__
#define __vm__List__

namespace ofxBI{
	class ListClass;
	class ListObject;
}


#include "../tools/Register.h"
#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"
#include "Boolean.h"


#include <iostream>

namespace ofxBI{
	
	/**
	 * @brief The implementation of List class
	 */
	/*
	 def get (index:Integer) return Object;
	 def length return Integer;
	 def add (elem:Object);
	 def addFirst (elem:Object);
	 def first  return Object;
	 def removeFirst return Object;
	 def last  return Object;
	 def pop  return Object;
	 */
	class ListClass: public SDK::SuperClass{
	public:
		ListClass();
		~ListClass();
		ListObject* getNewInstance();
		
		void ofxList(SDK::BICall* call);
		void ofxListObject(SDK::BICall* call);
		std::map< std::string, SDK::Method * > getRegisteredMethods();
	};

	class ListObject: public SDK::Primitive<vector<SDK::SuperObject*> >{
		friend class ListClass;
	private:
		
	protected:
		ListObject(ListClass* ci);
	public:
		~ListObject();
		void ofxGet(SDK::BICall* call);
		void ofxAdd(SDK::BICall* call);
		void ofxLength(SDK::BICall* call);
		void ofxAddFirst(SDK::BICall* call);
		void ofxFirst(SDK::BICall* call);
		void ofxRemoveFirst(SDK::BICall* call);
		void ofxLast(SDK::BICall* call);
		void ofxPop(SDK::BICall* call);
	};
}

#endif /* defined(__vm__List__) */
