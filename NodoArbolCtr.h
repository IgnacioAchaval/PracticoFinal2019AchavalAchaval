//
// Created by Ignacio Achaval on 05/11/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLCTR_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLCTR_H

#include "Lista.h"

template<class T>
class NodoArbolCtr {
public:
    Lista<T> dato;
    NodoArbolCtr<T> *izq, *der;
    int altura;
    int contador;

    NodoArbolCtr(T d, int c)  {
        der = izq = nullptr;
        altura = 0;
        contador = c;
        dato.insertarPrimero(d);
    }

    void setContador(int c) {
        NodoArbolCtr::contador = c;
    }

    int getContador() {
        return contador;
    }
    void setDato(T d) {
        NodoArbolCtr::dato.insertarPrimero(d);
    }

    T getDato() {
        return dato;
    };
};


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLCTR_H
