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
	public:
		Stack(int = 512) ; 
		~Stack(); 
		inline int push(const T); 
		inline T pop() ;
		inline int set(int, T);
		inline T get();
		inline T get(int);
		inline int getTop();
		inline int reseTop(int);
		//int isEmpty()const { return top == -1 ; } 
		//int isFull() const { return top == size - 1 ; } 
	private:
		int size ;  // number of elements on Stack.
		int top ;  
		T* stackPtr ;
		T* p_top;
	} ;
	
	//constructor with the default size 10
	template <class T>
	Stack<T>::Stack(int s){
		size = s;  
		top = 0 ;  // initialize stack
		stackPtr = new T[size] ; 
		//stackPtr=(T*) malloc(sizeof(void*)*s);
		p_top=stackPtr;
	}
	
	template <class T>
	Stack<T>::~Stack(){
		delete [] stackPtr;
		//free(stackPtr);
	}
	// push an element onto the Stack 
	template <class T>
	int Stack<T>::push(const T item){
		top++;
		p_top++;
		*p_top=item;
		if (top==size){
			//realloc
		}
		//stackPtr[top] = item ;
		return 1 ;  // push successful
	}
	
	// pop an element off the Stack
	template <class T> 
	T Stack<T>::pop() {
		T aux;
		aux=*p_top;
		--top;
		--p_top;
		return aux ;
		//	return 1 ;  // pop successful
	}
	
	template <class T>
	int Stack<T>::set(int n, T obj){
		stackPtr[n]=obj;
		return 1;
	}
	
	template <class T>
	T Stack<T>::get(int n){
		return stackPtr[n];
	}
	
	template <class T> 
	T Stack<T>::get() {
		return *p_top;
	}
	
	template <class T> 
	int Stack<T>::getTop() {
		return top;
	}
	
	template <class T> 
	int Stack<T>::reseTop(int p) {
		top=p;
		p_top=&(stackPtr[top]);
		return 1;
	}
}

#endif
