//
//  ofxClass.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_ofxClass_h
#define vm_ofxClass_h
class ofxClass;
class ofxObject;

#include "SuperClass.h"
#include "SuperObject.h"

class ofxClass: public SuperClass{
public:
	ofxClass(string);
	ofxObject* getNewInstance();
}

class ofxObject: public SuperObject{
public:
	ofxObject(Super*);
}


#endif
