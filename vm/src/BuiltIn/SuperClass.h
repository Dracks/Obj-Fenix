//
//  SuperClass.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_SuperClass_h
#define vm_SuperClass_h
class SuperClass;

#include "SuperObject.h"


class SuperClass: public Stackable{
private:
	SuperObject* DataCache;
	map<> methodList; // Donat un UID hem de retornar un methodList
	map<> propietyList;
protected:
	void addMethod();
	void addPropiety();
}


#endif
