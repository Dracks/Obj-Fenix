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
	
	
	Library* Library::data;
	
	Library* Library::getLibrary(){
		if (data==NULL){
			data=new Library();
		}
		return data;
	}
	
	void Library::addClass(int cid, string name, SuperClass* c){
		classList[cid]=c;
		classID[name]=cid;
	}
	
	SuperClass* Library::getClass(int cid){
		return classList[cid];
	}
	
	SuperClass* Library::getClass(string name){
		return classList[classID[name]];
	}
		
	void Library::addConstant(int cid, SuperObject* c){
		constantList[cid]=c;
	}
	
	SuperObject* Library::getConstant(int cid){
		return constantList[cid];
	}
}