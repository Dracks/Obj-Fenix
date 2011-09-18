//
//  SuperObject.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_SuperObject_h
#define vm_SuperObject_h

namespace SDK{
	class SuperObject;
	class Primitive;
}

#include "Super.h"

namespace SDK{
	class SuperObject: public Super{
	public:
		SuperObject(string name, Super*):Super(name){};
		~SuperObject(){};
	}
	
	template<class Template>
	class Primitive: public SuperObject{
	protected: 
		Template value;
		Primitive(Template v, SuperObject* base): SuperObject(base->getName()){
			value=v;
		}
	public:
		Template getValue(){
			return value;
		}
	}
}

#endif
