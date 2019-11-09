//
// Created by Ignacio Achaval on 05/11/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLCTR_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLCTR_H


template<class T>
class NodoArbolCtr {
public:
    T dato;
    NodoArbolCtr<T> *izq, *der;
    int altura;
    int contador;

    NodoArbolCtr(T d, int c)  {
        der = izq = nullptr;
        altura = 0;
        contador = c;
        dato = d;
    }

    void setContador(int contador) {
        NodoArbolCtr::contador = contador;
    }

    int getContador() {
        return contador;
    }

    void setDato(int dato) {
        NodoArbolCtr::dato = dato;
    }

    int getDato() {
        return dato;
    };
};


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLCTR_H
