/*
 *  Stacks.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 10/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef STACK_H
#define STACK_H

namespace ofxbytecode{
	template <class T>
	class Stack;
}


namespace ofxbytecode{
	
	template <class T>
	class Stack{
	private:
		int size ;  // number of elements on Stack.
		int top ;  
		T* stackPtr ;
		//T* p_top;
	public:
		Stack(int s= 512){
			size = s;  
			top = 0 ;  // initialize stack
			stackPtr = new T[size] ; 
			//stackPtr=(T*) malloc(sizeof(void*)*s);
			//p_top=stackPtr;
		};
		
		~Stack(){
			delete [] stackPtr;
			//free(stackPtr);
		};
		
		inline void push(const T item){
			top++;
			//p_top++;
			//*p_top=item;
			if (top==size){
				//realloc
			}
			stackPtr[top] = item ;
			//return 1 ;  // push successful
		}
 
		inline T pop() {
			T aux;
			//aux=*p_top;
			aux=stackPtr[top];
			--top;
			//--p_top;
			return aux;//stackPtr[top] ;
			//	return 1 ;  // pop successful
		};
		
		inline void set(int n, T obj){
			stackPtr[n]=obj;
			//return 1;
		};
		
		inline T get(){
			//return *p_top;
			return stackPtr[top];
		};
		
		//template <class Z>
		inline T get(int n){
			/*T ret;
			ret=stackPtr[n];
			return ret;
			*/
			return stackPtr[n];
		};
		inline int getTop() {
			return top;
		};
		
		inline void reseTop(int p) {
			top=p;
			//p_top=&(stackPtr[top]);
		};
		//int isEmpty()const { return top == -1 ; } 
		//int isFull() const { return top == size - 1 ; } 
	} ;
	
}

#endif
