//
//  SuperObject.cpp
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "SuperObject.h"

namespace SDK{
	//class SuperObject: public Super{
	
	using namespace std;
	
	SuperObject::SuperObject(int type): Super(type){
		
	}
	
	SuperObject::SuperObject(int type, ofxMap* obj):Super(type){
		this->copyContents(obj);
		//this->setName(name);
			
	};
	
	SuperObject::~SuperObject(){};

};