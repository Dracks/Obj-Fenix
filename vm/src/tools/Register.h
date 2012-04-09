//
//  Register.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Register_h
#define vm_Register_h


//#define registerClass(Class) namespace RegistradorDe##Class { extern "C"{ ofxtools::RegisterClass<Class>* hiddenStartUp##Class=new ofxtools::RegisterClass<Class>(); } }

//#define registerClass(Class) namespace hiddenStartUp##Class { extern "C" {\
  Class* maker##Class(){return new Class();}\
  class Register{ \
    public: Register(){\
      ofxtools::RegisterClass<Class> *tmp= new ofxtools::RegisterClass<Class>(); \
      tmp->set(maker##Class()); \
      ofxtools::OnStartUp::addClass(tmp);\
    }\
  };\
  Register tmp##Class; }\
} \

//#define registerClass(Class) namespace hiddenStartUp##Class { extern "C" {\
  ofxtools::OnStartUp* maker##Class(){return new ofxtools::RegisterClass<Class>();}\
  class Register{ \
    public: Register(){\
		cout << "Hola Mon!" << endl;\
		ofxtools::publicRegisterList[" Class "]=maker##Class;\
    }\
  };\
  Register tmp##Class; }\
} \

//#define registerClass(Class) namespace hiddenStartUp##Class { extern "C" {\
ofxtools::OnStartUp* maker##Class(){return new ofxtools::RegisterClass<Class>();}\
class Register{ \
public: Register(){\
cout << "Hola Mon!" << endl;\
maker##Class(); \
ofxtools::publicRegisterList.push_back(maker##Class);\
ofxtools::OnStartUp::addMaker(maker##Class);\
cout << ofxtools::publicRegisterList.size() << endl;\
}\
};\
Register tmp##Class; }\
} \

#define registerClass(Class) namespace hiddenStartUp##Class { extern "C" {\
ofxtools::OnStartUp* maker##Class(){return new ofxtools::RegisterClass<Class>();}\
class Register{ \
public: Register(){\
maker##Class(); \
}\
};\
Register tmp##Class; }\
} \


namespace ofxtools{
	class OnStartUp;
	
	template<class T>
	class RegisterClass;
	
	//typedef OnStartUp *maker_ptr();
	
//	class RegisterMethodCollection;
};

// #include "../SDK/BIMethod.h"
#include <iostream>
#include <map>
#include <string>
#include "Adapter.h"


namespace ofxtools{
	
	//extern std::vector<maker_ptr*> publicRegisterList;
	
	class OnStartUp{
	private:
		static std::vector<OnStartUp*> registerList;
	public:
		OnStartUp();
		virtual ~OnStartUp(){};
		virtual	void execute(Adapter*)=0;
		//static void addMaker(maker_ptr*);
		static void addClass(OnStartUp* r);
		static void registerAll(Adapter*);
	};
	
	
	
	template<class T>
	class RegisterClass: public OnStartUp{
	//private:
		//T* obj;
	public:
		RegisterClass():OnStartUp(){
			//std::cout << "registrant" << std::endl;
		};
		~RegisterClass(){};
/*		
		void set(T* obj){			
			this->obj=obj;
		};//*/
		
		virtual void execute(Adapter* adaptador){
			T* obj=new T();
			std::cout << obj->getName() << std::endl;
			adaptador->addClass(obj);
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
};


#endif
