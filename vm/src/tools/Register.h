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

class Register{
private:
	static vector<Register*> registerList;
public:
	Register();
	virtual	void* execute()=0;
	static void registerAll();
};

vector<Register*> Register::registerList;

template<class T>
class RegisterClass: public Register{
private:
	T* obj;
public:
	virtual void* execute(){
		obj=new T();
		return obj;
	}
};

#endif
