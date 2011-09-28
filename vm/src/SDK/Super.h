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
	class Super;
	class Method;
}

#include "Stackable.h"

namespace SDK{
	/**
	 * @class Method
	 * @brief An abstract class of a Method, it only has name of the method and define the method for call it. His childs has the really contents
	 */
	class Method: public Stackable{
	private:
		string name;
	public:
		/**
		 * @fn Method(string name)
		 * @param name the name of the method that it represents
		 */
		Method(string name): Stackable(name){};
		~Method();
		
		/**
		 * @fn inline string getName()
		 * @return the name of the Method
		 */
		inline string getName();
		
		/**
		 * @fn virtual int call(Stack<Stackable>*)=0;
		 * @brief The abstract method that defines the name of the method for call it.
		 */
		virtual int call(Stack<Stackable>*)=0;
	};
	
	
	/**
	 * @class Super
	 * @brief Is the clas that implements all the bases of all classes BI and Ofx.
	 * Implements the method for register and acces to all Methods and propierties
	 */
	class Super: public Stackable{
	private:
		map<int, Method*> methodList; // Donat un UID hem de retornar un metode
		map<int, SuperObject*> propertyList;
		
		map<string, int> methodTranslation;
		map<string, int> propertyTranslation;
	protected:
		/**
		 * @fn Super(string name)
		 * @brief constructor
		 */
		Super(string name): Stackable(name){};
		~Super();
		
		virtual vector<Method*> getMethodList(){};
		
		/**
		 * @fn inline void addMethod(string, int, Method*)
		 * @param name the name of the method to be added
		 * @param uid the UID of the method inside the object
		 * @param method The pointer to the Method class
		 * @brief Add a new method to the class, 
		 */
		inline void addMethod(string name, int uid, Method* method);
		
		/**
		 * @fn inline void addProperty(string, int);
		 * @param name the name of the property to be added
		 * @param uid the UID of the property inside the object
		 * @brief Add a new method to the class, 
		 */
		inline void addProperty(string name, int uid);
		
		/**
		 * @brief get Method from an UID
		 * @param uid UID from method
		 * @return Method you wish or null if not found
		 */
		inline Method* getMethod(int uid);
		
		/**
		 * @brief Get a method from this name
		 * @param name the name of the Method that you wish
		 * @return Method you wish or null if don't found
		 */
		inline Method* getMethod(string name);
		
		/**
		 * @brief Get a propety identified by UID
		 * @param uid UID of the property that you wish
		 * @return SuperObject that is an instance of the object that you wish
    	 */
		inline SuperObject* getProperty(int uid);
		
		/**
		 * @brief Get a propety identified by the name of this in the bytecode
		 * @param name the name of the property that you need.
		 * @return Superobject that is the instance that contains the property
    	 */
		inline SuperObject* getProperty(string name);
		
		/**
		 * @brief Save a new instance of a property in an specified UID
		 * @param uid the uid in where need to store the object
		 * @param obj the object that is an instance of you need.
    	 */
		inline void storePropiety(int uid, SuperObject* obj);
		
		/**
		 * @brief get an object from the name, it need the type of object you need, and it returns the object casted
		 * @param pName name of the instance you need
		 * @return Instance of the property you need
    	 */
		template <class T>
		inline T* get(string pName){
			return checkAndCast<T>(propertyList[propertyTranslation[pName]]);
		};
		/**
		 * @brief set an object by the name in the property list
		 * @param pName the name of the object you wish to store
		 * @param obj the object you wish store
    	 */
		template <class T>
		inline void set(string pName, T* obj){
			propertyList[propertyTranslation[pName]]=obj;
		}
	};
	
}
#endif
