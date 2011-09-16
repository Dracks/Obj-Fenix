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
private:
	SuperClass* parent;
public:
	ofxClass(string, SuperClass*);
	ofxObject* getNewInstance();
}

class ofxObject: public SuperObject{
private:
	SuperObject* parent;
public:
	ofxObject(Super*);
}


#endif
