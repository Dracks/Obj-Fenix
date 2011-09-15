//
//  SuperObject.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_SuperObject_h
#define vm_SuperObject_h

class SuperObject;



class SuperObject: public Stackable{
private:
	map<> methodList; // Donat un UID hem de retornar un methodList
	map<> propietyList;
protected:
	SuperObject(SuperObject*);
	void addMethod();
	void addPropiety();
}

#endif
