//
// Created by Ignacio Achaval on 25/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODO_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODO_H

#include <iostream>
#include<string>
using namespace std;


struct info
{
    string dato;
    int contador;
};

class Nodo
{
private:
    string dato;
    int contador;
    Nodo *next;
public:
    Nodo()
    {
        next = NULL;
    };

    Nodo(string d)
    {
        dato = d;
        next = NULL;
    };

    Nodo(string d, Nodo *n)
    {
        dato = d;
        next = n;
    }

    void setDato(string d)
    {
        dato = d;
    }

    void setNext(Nodo *n)
    {
        next = n;
    }

    string getDato()
    {
        return dato;
    }

    Nodo *getNext()
    {
        return next;
    }
};


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_NODO_H
