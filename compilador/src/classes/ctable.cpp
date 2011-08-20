/*
 *  ctable.cpp
 *  Compiladors
 *
 *  Created by dracks on 09/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ctable.h"

/* Crea una tabla reservando sitio para "n" elementos iniciales
 * habrá que hacer que crezca automáticamente cuando se llene o
 * cuando haya colisión de claves
 */
ctable::ctable(long n) {
    *tabla = new (Objeto) [n];
    final = n;
    for(long j=0; j<final; j++)
        tabla[j] = NULL;
    numElementos = 0;
    factorCarga = 0.0;
}

/*
 * Calcula la dirección que tendrá una determinada clave en la tabla. Si el sitio
 * está ocupada busca el primer sitio sin ocupar de forma secuencial y lo sitúa allí.
 */
long ctable::direccion(char *key) {
    int i = 0;
    long p, d;

    d = transformaCadena(key);
    //aplica aritmética modular para obtener dirección base
    p = d % final;
    //bucle de exploración
    while (tabla[p] != NULL && strcmp(tabla[p]->getClave(), key) != 0)
    {
        i++;
        p = p + i * i;
        p = p % final;      // considera el array como circular
    }
    return p;
}

/*
 * Convierte una cadena en un número que servirá para calcular la dirección en
 * un array
 */
long ctable::transformaCadena(char *c){
    long d = 0;
    for(int j = 0; j < strlen(c); j++)
    {
        d = d * 27 + (int)c[j];
    }
    if (d < 0) d = -d;
    return d;
}

/*
 * Crea un elemento con el par clave-valor y lo pone en la tabla.
 * Comprueba si el factor de carga recomienda sobredimensionar la tabla.
 */
void ctable::addElemento(char* key, Objeto* obj) {
    Elemento* elem = new Elemento(key, obj);
    long posicion = direccion(key);

    tabla[posicion] = elem;
    numElementos++;
    factorCarga = (double)numElementos/final;
    // Comprobar el factor de carga.
    if (factorCarga > 0.5) redimensionarTabla();
}

/*
 * Recupera el elemento con la clave dada
 */
Objeto* ctable::getElemento(char* key) {
    Objeto* obj;
    long posicion = direccion(key);

    obj = tabla[posicion]; // Devolverá NULL si no existe la clave en la tabla
    if (obj != NULL)
        // Si el objeto está desreferenciado no debería "resucitarlo"
        if (obj->getNumReferencias() == 0) obj = NULL;
    return obj;
}

void ctable::borrar(char* key) {
    long posicion = direccion(key);
    if (tabla[posicion] != NULL){
        tabla[posicion]->decCount(); // Decrementa el contador del objeto
        tabla[posicion] = NULL; //pone el espacio de la tabla en disponible
    }
}

/*
 * Hay que hacer la función que redimensione la tabla
 */
void ctable::redimensionarTabla() {
    cout << "\n El factor de carga supera el 50 por 100. "
        << "Conviene aumentar el tamaño." << endl;
}
