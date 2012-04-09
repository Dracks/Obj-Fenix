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
	using namespace std;
	vector<OnStartUp*> OnStartUp::registerList;
	//std::map<string, maker_ptr*, less<string> > publicRegisterList;
	//vector<maker_ptr*> publicRegisterList;
	

	//class Register{
	OnStartUp::OnStartUp(){
		registerList.push_back(this);
		//cout << registerList.size() << endl;
	}
	
	void OnStartUp::addClass(OnStartUp* r){
		OnStartUp::registerList.push_back(r);
	}
	/*void OnStartUp::addMaker(maker_ptr* f){
		publicRegisterList.push_back(f);
	}*/

	void OnStartUp::registerAll(Adapter* adaptador) {
		int size=registerList.size();
		printf("Registrant-ho tot (%d) \n", size);
		for(unsigned int i=0; i<size; i++){
			registerList[i]->execute(adaptador);
		}
		
		/*map<string, maker_ptr*>::iterator iter;
		for (iter=publicRegisterList.begin(); iter!=publicRegisterList.end(); iter++){
			iter->second()->execute(adaptador);
		}//*/
		/*size=publicRegisterList.size();
		printf("Registrant-ho tot (%d) \n", size);
		for(unsigned int i=0; i<size; i++){
			publicRegisterList[i]()->execute(adaptador);
		}//*/
	}
}