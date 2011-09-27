/*
 *  Library.h
 *  vm
 *
 *  Created by dracks on 22/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

namespace ofxbytecode{
	class Library;
}

#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"

#ifndef LIBRARY_H
#define LIBRARY_H
using namespace objfenix;

namespace ofxbytecode{
	/**
	 * @class Library
	 * @brief This class contains all definitions of classes and constants organitzed with name and UID
     */
	class Library{
	private:
		vector<SDK::SuperClass*> classList;
		vector<SDK::SuperObject*> constantList;
		map<string,int> classID;
		map<string,int> constantID;
		Library();
		~Library(){data=NULL};
		
		static Library* data;
		
	public:
		/**
		 * @brief obtain Library as a singleton
		 * @return the only instance of Library in all the execution.
    	 */
		static Library* getLibrary();
		
		void addClass(int cid, string name, SDK::SuperClass* c);
		inline SDK::SuperClass* getClass(int cid);
		inline SDK::SuperClass* getClass(string name);
		
		void addConstant(int cid, SDK::SuperObject* c); // Class => BuiltInClass
		inline SDK::SuperObject* getConstant(int cid);
	};
}

#endif