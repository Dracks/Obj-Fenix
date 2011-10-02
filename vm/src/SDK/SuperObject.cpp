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
	
	SuperObject::SuperObject(std::string name, Super* obj):Super(name+" Instance"){
			this->copyContents(obj);
			
		};
	SuperObject::~SuperObject(){};

};