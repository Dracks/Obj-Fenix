/*
 *  Library.h
 *  vm
 *
 *  Created by dracks on 22/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

namespace ofxbytecode{
	class Library;
};

/*#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"
 */
#include <vector>
#include <map>
#include <iostream>

#ifndef LIBRARY_H
#define LIBRARY_H
//using namespace objfenix;

namespace SDK{
	class SuperClass;
	class SuperObject;
}
namespace ofxbytecode{
	/**
	 * @class Library
	 * @brief This class contains all definitions of classes and constants organitzed with name and UID
	 */
	class Library{
	private:
		std::map<int, SDK::SuperClass*> classList;
		std::map<int, SDK::SuperObject*> constantList;
		std::map<std::string,int> classID;
		std::map<std::string,int> constantID;
		
		Library();
		~Library();
		
		static Library* data;
		
	public:
		/**
		 * @brief obtain Library as a singleton
		 * @return the only instance of Library in all the execution.
		 */
		static Library* getLibrary(){
			if (data==NULL){
				data=new Library();
			}
			//std::cout << data << std::endl;
			return data;
		};
		
		void addClass(int cid, std::string name, SDK::SuperClass* c);
		SDK::SuperClass* getClass(int cid);
		SDK::SuperClass* getClass(std::string name);
		
		void addConstant(int cid, SDK::SuperObject* c); // Class => BuiltInClass
		SDK::SuperObject* getConstant(int cid);
	};
};

#endif