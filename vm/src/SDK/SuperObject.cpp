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
	
	SuperObject::SuperObject(string name): Super(name+" Cache"){
	}
	
	SuperObject::SuperObject(string name, Super* obj):Super(name+" Instance"){
			this->copyContents(obj);
			
		};
	
	SuperObject::~SuperObject(){};

};