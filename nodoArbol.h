//
// Created by Ignacio Achaval on 25/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOL_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOL_H


#include <iostream>
#include "Lista.h"
#include <vector>
using namespace std;

class nodoArbol
{
private:
    string dato;
    int contador;
    nodoArbol *izq, *der;

public:
    // Constructores.
    nodoArbol(string d, int c)
    {
        izq = NULL;
        der = NULL;
        dato.insert(0,d);
        contador = c;
    }

    // Access methods


    void setDato(string d)
    {
        dato.insert(0,d);
    }

    void setContador(int contador)
    {
        nodoArbol::contador = contador;
    }

    string getDato(int pos)
    {
        return dato;
    }

    int getContador()
    {
        return contador;
    }


    nodoArbol *getIzq()
    {
        return izq;
    }

    void setIzq(nodoArbol *izq)
    {
        nodoArbol::izq = izq;
    }

    nodoArbol *getDer() const
    {
        return der;
    }

    void setDer(nodoArbol *der)
    {
        nodoArbol::der = der;
    }


    void insertar(string d,int c)
    {

        if (contador < c)
        {
            if (der != NULL)
                der->insertar(d,c);
            else
                der=new nodoArbol(d,c);



        } else if(contador>c)
        {
            if (izq != NULL)
                izq->insertar(d,c);
            else
                izq=new nodoArbol(d,c);
        }
        else if(contador==c)
        {
            dato.insert(0,d);
        }
    }

    void insertar(nodoArbol *n)
    {
        if (n != NULL)
            if (contador < n->getContador())
            {
                if (der != NULL)
                    der->insertar(n);
                else
                    der = n;
            } else
            {
                if (izq != NULL)
                    izq->insertar(n);
                else
                    izq = n;
            }
    }

    void mostrarOrden()
    {
        if (der != NULL)
            der->mostrarOrden();
        cout << ' ' << dato << ' ' << contador<<endl;
        if (izq != NULL)
            izq->mostrarOrden();
    }

    /*void mostrarPreOrden()
    {
        cout << ' ' << dato << ' ' << dato;
        if (izq != NULL)
            izq->mostrarPreOrden();
        if (der != NULL)
            der->mostrarPreOrden();
    }

    void mostrarPosOrden()
    {
        if (izq != NULL)
            izq->mostrarPosOrden();
        if (der != NULL)
            der->mostrarPosOrden();
        cout << ' ' << dato << ' ' << dato;
    }*/


    int borrar(string d, int c, nodoArbol *padre, int lado)
    {
        nodoArbol *derAux = der;
        nodoArbol *izqAux = izq;

        if (d != dato)
        {
            if (d > dato)
            {
                if (der == NULL)
                    return -1;
                if (der->borrar(d, c, this, 0) == 1)
                {
                    c--;
                    delete derAux;
                }

            } else
            {
                if (izq == NULL)
                    return -1;
                if (izq->borrar(d, c, this, 1))
                {
                    c--;
                    delete izqAux;

                }

            }
        } else
        {
            if (lado)
            {
                padre->setIzq(der);
            } else
            {
                padre->setDer(der);
            }
            der->insertar(izq);
            return 1;
        }
        return 0;
    }


};


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOL_H
