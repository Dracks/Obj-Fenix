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
	class Adapter {
	private:
		//static Library* data;
		
		map<string, SuperClass*> ofxDataCache;
		vector<CacheClass*> biDataCache;
		
		
		
	public:
		//static Library* getData();
		
		void applyNative(NativeCacheClass*);
		void applyOfx(OfxCacheClass*);
		
		Adapter();
		~Adapter();
		
		void registerClass(SuperClass*);
		void assignClass(CacheClass*);
		
		void apply();
		
	}
}


#endif
