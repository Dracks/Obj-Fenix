//
//  SuperClass.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_SuperClass_h
#define vm_SuperClass_h

namespace SDK{
	class SuperClass;
}

#include "SuperObject.h"


namespace SDK {
	class SuperClass: public Super{
	private:
		SuperObject* DataCache;
	protected:
		SuperClass();
		~SuperClass();
		SuperObject* getCache();
		
		inline void addInstanceMethod(string, int, Method*);
		inline void addInstanceProperty(string, int);
	};
}


#endif
