/*
 *  ctable.h
 *  Compiladors
 *
 *  Created by dracks on 09/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

class Elemento {
protected:
    char *clave;
    Objeto *obj;
public:
    Elemento(char* c, Objeto* valor) {clave = c; obj = valor};
    Elemento(){};
    void setObjeto(Objeto *o) {obj = o};
    char* getClave() {return clave};
 }

class ctable  {
protected:
	long final;
	long numElementos;
	double factorCarga;
	Elemento **tabla;
	long direccion(char *key);
	long transformaCadena(char *c);
public:
    ctable(long n);
    ~ctable();
	void addElemento(char* key, Objeto* object);
	Objeto* getElemento(char* key);
	void borrar(char* key);
	void redimensionarTabla();
};
