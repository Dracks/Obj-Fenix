//
//  Register.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Register_h
#define vm_Register_h


#define registerClass(C) namespace RegistradorDe##C { R::RegisterClass<C> startup; } 
namespace ofxtools{
	class OnStartUp;
	class RegisterClass;
	class RegisterMethodCollection;
}

#include "../SDK/BIMethod.h"

namespace ofxtools{
	class OnStartUp{
	private:
		static vector<OnStartUp*> registerList;
	public:
		OnStartUp();
		virtual	void execute(Adapter*)=0;
		static void registerAll(Adapter*);
	};
	
	vector<Register*> Register::registerList;
	
	template<class T>
	class RegisterClass: public OnStartUp{
	private:
		T* obj;
	public:
		virtual void execute(Adapter* adaptador){
			adaptador->registerClass(new T());
		}
	};
	/*
	template<class Template>
	class RegisterMethodCollection {
	private:
		vector<pair<string, void (Template::*)(SDK::BICall*)> > llista;
	public:
		add(string name, void (Template::*method)(SDK::BICall*)){
			llista.push_back(new pair<string, void (Template::*)(SDK::BICall*)>(name, method));
		}
	}*/
}


#endif
