//
//  Integer.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Integer_h
#define vm_Integer_h

class IntegerClass;
class IntegerObject;

#include "../tools/Register.h"

registerClass(IntegerClass)

class IntegerClass: public SuperClass {
public:
	IntegerClass();
	~IntegerClass();
	IntegerObject* ofxInteger(BuiltInCall* call);
}

class IntegerObject: public SuperObject {
	friend class IntegerClass;
private:
	int v;
protected:
	IntegerObject(int v, SuperObject* base);
public:
	~IntegerObject();
	IntegerObject* ofxAdd(BuiltInCall* call);
	IntegerObject* ofxSub(BuiltInCall* call);
}



#endif
