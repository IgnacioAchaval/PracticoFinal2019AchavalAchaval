//
// Created by Ignacio Achaval on 25/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_LISTA_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_LISTA_H


#include <iostream>
#include "Nodo.h"

using namespace std;

class Lista
{
private:
    Nodo *primero;

public:
    Lista()
    {
        primero = NULL;
    }

    int esVacio()
    {
        return (primero == NULL);
    }

    void insert(int pos, string dato)
    {
        Nodo *act, *ant, *tmp;
        int cont = 0;

        if (pos == 0)
        {
            primero = new Nodo(dato, primero);
        } else
        {
            act = primero;
            ant = primero;
            while (cont < pos && act != NULL)
            {
                ant = act;
                act = act->getNext();
                cont++;
            }

            if (cont == pos)
            {
                tmp = new Nodo(dato);
                ant->setNext(tmp);
                tmp->setNext(act);
                // ant->setNext(new Nodo(dato, act));
            } else
            {
                // Mostar Error
            }
        }
    }

    string getDato(int pos)
    {
        Nodo *act = primero;
        int cont = 0;
        if (!esVacio())
        {
            while (cont < pos && act->getNext() != nullptr)
            {
                cont++;
                act = act->getNext();
            }

            if (cont == pos)
            {
                return act->getDato();
            } else
            {
                // Error
                return "";
            }
        }
        // error
        return "";
    }

    string borrar(int pos)
    {
        Nodo *act = primero, *ant = primero;
        int cont = 0;
        string ret = 0;

        if (esVacio())
        {
            // Error
            ret = 1;
        } else if (pos == 0)
        {
            primero = primero->getNext();
            delete act;
        } else
        {
            while (cont < pos && act->getNext() != nullptr)
            {
                cont++;
                ant = act;
                act = act->getNext();
            }
            if (cont == pos)
            {
                ant->setNext(act->getNext());
                delete act;
            } else
            {
                ret = 1;
            }
        }
        return ret;
    }

    void print()
    {
        Nodo *act = primero;

        while (act != nullptr)
        {
            cout << act->getDato();
            act = act->getNext();
        }
        cout << endl;
    }

};


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_LISTA_H
