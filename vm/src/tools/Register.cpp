//
//  Register.cpp
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Register.h"

namespace ofxtools{

	vector<OnStartUp*> OnStartUp::registerList;

	//class Register{
	OnStartUp::OnStartUp(){
		registerList.push_back(this);
	}

	void OnStartUp::registerAll(Adapter* adaptador) {
		int size=registerList.size();
		printf("Registrant-ho tot (%d) \n", size);
		for(unsigned int i=0; i<registerList.size(); i++){
			registerList[i]->execute(adaptador);
		}
	}
}