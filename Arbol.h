//
// Created by Ignacio Achaval on 25/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_ARBOL_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_ARBOL_H

#include "nodoArbol.h"


class Arbol
{
private:
    nodoArbol *raiz; //Puntero a la raiz

public:

    //Constructores
    Arbol()
    {
        raiz = NULL;
    }

    Arbol(string d, int c)
    {
        raiz = new nodoArbol(d, c);
    }

    void vaciarArbol()
    {
        raiz=NULL;
    }


    void insertar(string d,int c)
    {
        if (raiz != NULL)
        {
            raiz->insertar(d,c);
            c++;
        }
        else
            raiz = new nodoArbol(d, c);
    }

    // Muestras
    void mostrarOrden()
    {
        if (raiz != NULL)
            raiz->mostrarOrden();
    }

};


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_ARBOL_H
