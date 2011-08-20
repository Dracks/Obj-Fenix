/*
 *  clist.h
 *  compilerTest
 *
 *  Created by Jaume Singla Valls on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef clisth
#define clisth 1
class cnode{
private:
	struct cnode* next;
	struct cnode* prev;
	void* contents;
	
public:
	cnode(void* _contents);
	~cnode();
	cnode*	getNext();
	cnode*	getPrev();
	void	setNext(cnode* _next);
	void	setPrev(cnode* _prev);

	void*	getContents();
};

class clist{
private:
	int num;
	cnode* first;
	cnode* last;
	
public:
	clist();
	~clist();
	void add(void* _contents);
	void addFirst(void* _contents);
	cnode* getFirst();
	cnode* getLast();
	cnode* pop();
	int count();
	void clear();
};
#endif