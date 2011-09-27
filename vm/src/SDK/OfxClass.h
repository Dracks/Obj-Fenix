//
//  ofxClass.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_ofxClass_h
#define vm_ofxClass_h

namespace SDK{
	class ofxClass;
	class ofxObject;
}

#include "SuperClass.h"
#include "SuperObject.h"

namespace SDK{
	class OfxClass: public SuperClass{
	private:
		SuperClass* parent;
	public:
		OfxClass(string, SuperClass*);
		~OfxClass();
		ofxObject* getNewInstance();
	};
	
	class OfxObject: public SuperObject{
	private:
		SuperObject* parent;
	public:
		OfxObject(Super*);
		~OfxObject();
	};
}


#endif
