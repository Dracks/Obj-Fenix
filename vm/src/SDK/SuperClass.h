//
//  SuperClass.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_SuperClass_h
#define vm_SuperClass_h

namespace SDK{
	class SuperClass;
};

#include "Super.h"
#include "SuperObject.h"


namespace SDK {
	/**
	 * @class SuperClass
	 * @brief It defines the basic methods for all the static classes (OFX and BI)
     */
	class SuperClass: public Super{
	private:
		/**
		 * @brief The object that use as a cache for the methods of an instance. 
		 */
		ofxMap* instanceInfo;
		std::string ofxName;
	protected:
		
		
		/**
		 * @brief Constructor
    	 */
		SuperClass(int type);
		~SuperClass();
		
		void setName(std::string name);
	public:
		
		/**
		 * @brief get the Cache instance
		 * @return return the instance of the cache.
    	 */
		ofxMap* getCache();
		
		/**
		 * @brief get a list of methods with this name, is used in the BIClass, for register their methods
		 * @return return the instance of the cache.
    	 */
		virtual std::map<std::string, Method*> getRegisteredMethods();
		
		/**
		 * @brief add a Method to the datacache property
		 * @param name the name of the method
		 * @param uid the Identifier of the method
		 * @param method the instance of the method you need to call.
    	 */
		virtual void addInstanceMethod(std::string name, int uid, Method* method);
		
		/**
		 * @brief add a property to the datacache
		 * @param name the name for identify the property
		 * @param uid the UID for identify the property
    	 */
		virtual void addInstanceProperty(std::string name, int uid);
		
		std::string getOfxName();
	};
};


#endif
