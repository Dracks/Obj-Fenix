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
}

#include "Super.h"

namespace SDK{
	class SuperObject: public Super{
	public:
		SuperObject(string name, Super*):Super(name){};
		~SuperObject(){};
	}
}

#endif
