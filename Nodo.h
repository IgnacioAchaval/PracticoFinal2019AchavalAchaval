//
// Created by Ignacio Achaval on 25/10/2019.
//
/*
#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODO_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODO_H

#include <iostream>
#include<string>
using namespace std;



class Nodo
{
private:
    string dato;
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
*/