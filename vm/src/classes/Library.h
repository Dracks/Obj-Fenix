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

#include "../BuiltIn/class.h"

#ifndef LIBRARY_H
#define LIBRARY_H
using namespace objfenix;

namespace ofxbytecode{

	class Library{
	private:
		vector<Class*> classList;
		vector<Class*> constantList;
		map<string,int> classID;
		map<string,int> constantID;
	public:
		void addClass(int cid, string name, Class* c);
		Class* getClass(int cid);
		Class* getClass(string name);
		
		void addConstant(int cid, Class* c); // Class => BuiltInClass
		Class* getConstant(int cid);
	};
}

#endif