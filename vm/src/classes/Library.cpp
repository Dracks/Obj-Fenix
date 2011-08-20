/*
 *  Library.cpp
 *  vm
 *
 *  Created by dracks on 22/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Library.h"

namespace ofxbytecode{
	//class Library{
	
	void Library::addClass(int cid, string name, Class* c){
		classList[cid]=c;
		classID[name]=cid;
	}
	
	Class* Library::getClass(int cid){
		return classList[cid];
	}
	
	Class* Library::getClass(string name){
		return classList[classID[name]];
	}
		
	void Library::addConstant(int cid, Class* c){
		constantList[cid]=c;
	}
	
	Class* Library::getConstant(int cid){
		return constantList[cid];
	}
}