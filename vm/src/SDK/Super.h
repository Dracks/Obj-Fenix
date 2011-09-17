//
//  Super.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Super_h
#define vm_Super_h

namespace SDK{
	class Super;
	class Method;
}

#include "Stackable.h"

namespace SDK{

	class Method: public Stackable{
	private:
		string name;
	public:
		Method(string name): Stackable(name){};
		~Method();
		string getName();
		virtual int call(Stack<Stackable>*)=0;
	}
	
	
	
	class Super: public Stackable{
	private:
		map<int, Method*> methodList; // Donat un UID hem de retornar un methodList
		map<int, SuperObject*> propertyList;
		
		map<string, int> methodTranslation;
		map<string, int> propertyTranslation;
	protected:
		Super(string name): Stackable(name){};
		~Super();
		inline void addMethod(string, int, Method*);
		inline void addProperty(string, int);
		inline Method* getMethod(int);
		inline Method* getMethod(string);
		inline SuperObject* getProperty(int);
		inline SuperObject* getProperty(string);
		inline void storePropiety(int, SuperObject*);
	}
	
}
#endif
