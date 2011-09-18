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

	class Library{
	private:
		vector<SDK::SuperClass*> classList;
		vector<SDK::SuperObject*> constantList;
		map<string,int> classID;
		map<string,int> constantID;
	public:
		void addClass(int cid, string name, SDK::SuperClass* c);
		SDK::SuperClass* getClass(int cid);
		SDK::SuperClass* getClass(string name);
		
		void addConstant(int cid, SDK::SuperObject* c); // Class => BuiltInClass
		SDK::SuperObject* getConstant(int cid);
	};
}

#endif