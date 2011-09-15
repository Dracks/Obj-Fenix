//
//  Register.cpp
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Register.h"

//class Register{
Register::Register(){
	registerList.push_back(this);
}

void Register::registerAll() {
	int size=registerList.size();
	printf("Registrant-ho tot (%d) \n", size);
	for(unsigned int i=0; i<registerList.size(); i++){
		printf("%d\n", i);
		registerList[i]->execute();
	}
}


vector<Register*> Register::registerList;