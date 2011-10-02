//
//  SuperGlue.h
//  vm
//
//  Created by Dracks on 19/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Adapter_h
#define vm_Adapter_h

namespace ofxtools{
	class Adapter;
};

#include <map>
#include <vector>
#include "../classes/Library.h"
//#include "../SDK/SuperClass.h"
#include "Cache.h"


namespace ofxtools {
	/**
	 * @class Adapter
	 * @brief This class joins the bytecode with the builtIn Classes and objects and charge Library with All the data.
         */
	class Adapter {
	private:
		std::map<std::string, SDK::SuperClass*> ofxDataCache;
		std::vector<CacheClass*> biDataCache;
		
	public:
		//static Library* getData();
		Adapter();
		~Adapter();

                /**
                 * @brief Apply the properties to a class, assign it as the bytecode say it
                 * @param c The superClass (VM object) to assign the properties
                 * @param cache The class description from bytecode
                 */
		void applyProperties(SDK::SuperClass* c, CacheClass* cache);

                /**
                 * @brief Apply the cacheClass To a native object.
                 * @param cache The tlass description from bytecode
                 */
		void applyNative(NativeCacheClass* cache);

                /**
                 * @brief Apply the cacheClass To an ofx object.
                 * @param cache The class description from bytecode
                 */
		void applyOfx(OfxCacheClass* cache);

                /**
                 * @brief Register a BuiltIn class in the adapter for a posterior load of this.
                 * @param C the class to register
                 */
		void addClass(SDK::SuperClass* C);

                /**
                 * @brief Assign a new cacheClass descriptor from bytecode.
                 * @param cache the object descriptor
                 */
		void assignClass(CacheClass* cache);

		/**
                 * @brief Apply all class and cache class to the library. 
                 */
		void apply();
		
	};
};


#endif
