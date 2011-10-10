//
//  SuperObject.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_SuperObject_h
#define vm_SuperObject_h


namespace SDK{
	class SuperObject;
	template <class T>
	class Primitive;
};

#include "Super.h"

namespace SDK{
	class SuperClass;
	/**
	 * @class SuperObject
	 * @brief The class base of all Instances in the objective Fenix.
     */
	class SuperObject: public Super{
		friend class SuperClass;
	private:
		/**
		 * @brief Constructor for the DataCache property in the class
		 * @param the name of this object
    	 */
		SuperObject(int type );
	public:
		/**
		 * @brief Constructor
		 * @param name the Name of the object
		 * @param obj the base for build the new instance
    	 */
		SuperObject(int type, Super* obj);
		~SuperObject();
	};
	
	/**
	 * @class Primitive
	 * @brief Is a template class for the base of all primitive BuiltIn Instances in the OFX
     */
	template<class Template>
	class Primitive: public SuperObject{
	protected: 
		Template value;
		/**
		 * @brief Primitive
		 * @param v the value primitive of the object
		 * @param base the Base for call and construct SuperObject
    	 */
		Primitive(Template v, SuperObject* base): SuperObject(base->getType(), base){
			value=v;
			//this->setName(base->getName());
		}
	public:
		/**
		 * @brief get the primitive value that it save
		 * @return the value
    	 */
		inline Template getValue(){
			return value;
		}
	};
};

#endif
