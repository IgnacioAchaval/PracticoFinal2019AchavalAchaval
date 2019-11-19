//
// Created by Ignacio Achaval on 31/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLBINARIO_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLBINARIO_H


template<class T>
class NodoArbolBinario {
public:
    T dato;
    NodoArbolBinario<T> *izq, *der;
    int altura;
    int contador;

    NodoArbolBinario(T d){
        der = izq = nullptr;
        altura = 0;
        contador = 1;
        dato = d;
    }

    void setContador(int contador)
    {
        NodoArbolBinario::contador = contador;
    }
    int getContador()
    {
        return contador;
    }

    void setDato(int dato)
    {
        NodoArbolBinario::dato = dato;
    }
    int getDato()
    {
        return dato;
    }
};


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLBINARIO_H
