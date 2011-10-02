/*
 *  Library.cpp
 *  vm
 *
 *  Created by dracks on 22/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Library.h"

#include "../SDK/SuperClass.h"

namespace ofxbytecode{
	//class Library{
	using namespace SDK;
	
	Library::Library(){};
	Library::~Library(){data=NULL;};
	
	Library* Library::data;
	
	inline Library* Library::getLibrary(){
		if (data==NULL){
			data=new Library();
		}
		return data;
	}
	
	inline void Library::addClass(int cid, string name, SuperClass* c){
		classList[cid]=c;
		classID[name]=cid;
	}
	
	inline SuperClass* Library::getClass(int cid){
		return classList[cid];
	}
	
	inline SuperClass* Library::getClass(string name){
		return classList[classID[name]];
	}
		
	inline void Library::addConstant(int cid, SuperObject* c){
		constantList[cid]=c;
	}
	
	inline SuperObject* Library::getConstant(int cid){
		return constantList[cid];
	}
}