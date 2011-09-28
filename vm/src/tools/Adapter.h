//
//  SuperGlue.h
//  vm
//
//  Created by Dracks on 19/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Adapter_h
#define vm_Adapter_h

namespace tools{
	class Adapter;
}

#include "../classes/Library.h"

namespace tools {
	/**
	 * @class Adapter
	 * @brief This class joins the bytecode with the builtIn Classes and objects and charge Library with All the data.
     */
	class Adapter {
	private:
		
		map<string, SuperClass*> ofxDataCache;
		vector<CacheClass*> biDataCache;
		
		
	public:
		//static Library* getData();
		Adapter();
		~Adapter();
		
		void applyNative(NativeCacheClass*);
		void applyOfx(OfxCacheClass*);
		
		void registerClass(SuperClass*);
		void assignClass(CacheClass*);
		
		void apply();
		
	}
}


#endif
