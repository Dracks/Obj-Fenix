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
	class Method;
	class Super;

}

#include "Stackable.h"

#include <map>
#include <vector>
#include "../classes/Stack.h"
#include "../classes/Thread.h"
#include "../tools/Adapter.h"

//class ofxtools::Adapter;

namespace SDK{
	/**
	 * @class Method
	 * @brief An abstract class of a Method, it only has name of the method and define the method for call it. His childs has the really contents
	 */
	class Method: public Stackable{
	public:
		/**
		 * @fn Method(string name)
		 * @param name the name of the method that it represents
		 */
		Method(int type);
		~Method();
		
		/**
		 * @fn virtual int call(Stack<Stackable*>*)=0;
		 * @brief The abstract method that defines the name of the method for call it.
		 */
		virtual int call(ofxbytecode::Stack<Stackable*>*)=0;
	};
	
	
	/**
	 * @class Super
	 * @brief Is the clas that implements all the bases of all classes BI and Ofx.
	 * Implements the method for register and acces to all Methods and propierties
	 */
	class Super: public Stackable{
		friend class ofxtools::Adapter;
		friend class ofxbytecode::Thread;
		friend class SDK::SuperClass;
	private:
		std::map<int, Method*> methodList; // Donat un UID hem de retornar un metode
		std::map<int, SuperObject*> propertyList;//*/
		
		/*std::vector<Method*> methodList; // Donat un UID hem de retornar un metode
		std::vector<SuperObject*> propertyList;//*/
		
		std::map<std::string, int> methodTranslate;
		std::map<std::string, int> propertyTranslate;
	protected:
		/**
		 * @fn Super(string name)
		 * @brief constructor
		 */
		Super(int type);
		~Super();
		
		virtual std::vector<Method*> getMethodList();
		
		/**
		 * @param name the name of the method to be added
		 * @param uid the UID of the method inside the object
		 * @param method The pointer to the Method class
		 * @brief Add a new method to the class, 
		 */
		void addMethod(std::string name, int uid, Method* method);
		
		/**
		 * @param name the name of the property to be added
		 * @param uid the UID of the property inside the object
		 * @brief Add a new method to the class, 
		 */
		void addProperty(std::string name, int uid);
		
		/**
		 * @brief copy the contents of another instance of this, for know the methods and properties of the object
		 * @param instance the object to obtain methodList and PropertyList
    	 */
		void copyContents(Super* instance);
	public:
		/**
		 * @brief get Method from an UID
		 * @param uid UID from method
		 * @return Method you wish or null if not found
		 */
		Method* getMethod(int uid);
		
		/**
		 * @brief Get a method from this name
		 * @param name the name of the Method that you wish
		 * @return Method you wish or null if don't found
		 */
		Method* getMethod(std::string name);
		
		/**
		 * @brief Get uid method from this name
		 * @param name the name of the Method that you wish
		 * @return uid from this method or null if don't found
		 */
		int getMethodUid(std::string name);
		
		/**
		 * @brief Get a propety identified by UID
		 * @param uid UID of the property that you wish
		 * @return SuperObject that is an instance of the object that you wish
    	 */
		SuperObject* getProperty(int uid);
		
		/**
		 * @brief Get a propety identified by the name of this in the bytecode
		 * @param name the name of the property that you need.
		 * @return Superobject that is the instance that contains the property
    	 */
		SuperObject* getProperty(std::string name);
		
		/**
		 * @brief Save a new instance of a property in an specified UID
		 * @param uid the uid in where need to store the object
		 * @param obj the object that is an instance of you need.
    	 */
		void storePropiety(int uid, SuperObject* obj);
		
		/**
		 * @brief get an object from the name, it need the type of object you need, and it returns the object casted
		 * @param pName name of the instance you need
		 * @return Instance of the property you need
    	 */
		template <class T>
		inline T* get(std::string pName){
			return checkAndCast<T>(propertyList[propertyTranslate[pName]]);
		};
		/**
		 * @brief set an object by the name in the property list
		 * @param pName the name of the object you wish to store
		 * @param obj the object you wish store
    	 */
		template <class T>
		inline void set(std::string pName, T* obj){
			propertyList[propertyTranslate[pName]]=obj;
		}
	};
	
}
#endif
