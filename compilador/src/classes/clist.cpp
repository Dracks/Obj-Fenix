/*
 *  clist.cpp
 *  compilerTest
 *
 *  Created by Jaume Singla Valls on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "clist.h"
#include <iostream>

clist::clist(){
	num=0;
	first=NULL;
	last=NULL;
}

clist::~clist(){
	cnode* next;
	cnode* next2;
	next=first;
	while (next!=NULL){
		next2=next->getNext();
		delete next;
		next=next2;
	}
}
void clist::add(void* _contents){
	/* printf("HOLA MUNDO?"); */
	cnode* aux=new cnode(_contents);
	if (this->num){
		cnode* aux2=last;
		aux2->setNext(aux);
		aux->setPrev(last);
	} else { /* O sigui tenim 0 */
		first= aux;
	}
	last= aux;
	num++;
}
void clist::addFirst(void* _contents){
	/* printf("HOLA MUNDO?"); */
	cnode* aux=new cnode(_contents);
	/*aux->contents=contents;
	aux->next=NULL;
	aux->prev=NULL;*/
	if (this->num){
		cnode* aux2=first;
		aux2->setPrev(aux);
		aux->setNext(first);
	} else { /* O sigui tenim 0 */
		last= aux;
	}
	first= aux;
	num++;
}
cnode* clist::getFirst(){
	return first;
}

cnode* clist::getLast(){
	return last;
}

cnode* clist::pop(){
	/* return this->first; */
	cnode* aux=last;
	cnode* aux2=aux->getPrev();
	last=aux2;
	aux2->setNext(NULL);
	num--;
	return aux;
}

int clist::count(){
	return num;
}

void clist::clear(){
	cnode* next,*next2;
	next=first;
	while (next!=NULL){
		next2=next->getNext();
		delete next;
		next=next2;
	}
	first=last=NULL;
	num=0;
};

cnode::cnode(void* _contents){
	contents=_contents;
	next=NULL;
	prev=NULL;
}

cnode::~cnode(){};

cnode*	cnode::getNext(){
	return next;
}

cnode*	cnode::getPrev(){
	return prev;
}

void	cnode::setNext(cnode* _next){
	next=_next;
}
void	cnode::setPrev(cnode* _prev){
	prev=_prev;
}

void* cnode::getContents(){
	return contents;
}
