//
// Created by Ignacio Achaval on 25/10/2019.
//

/*Estos nodos arbol en vez de ser nodos convencionales (como los que vimos en clase), guardan un dato extra. O sea
 * tienen la palabra misma que se quiere guardar y un contador que se inicia en uno cuando se crea el nodo.
 * si queremos ingresar una palabra al arbol y ya existe, en vez de ingresarla abajo, no lo hace y suma en uno el contador.
 */

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOL_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOL_H

#include <iostream>
#include "Lista.h"

using namespace std;

class nodoArbol {
private:
    string dato;
    int contador;
    nodoArbol *izq, *der;

public:
    // Constructores.
    nodoArbol(string d, int c) {
        izq = nullptr;
        der = nullptr;
        dato = d;
        contador = c;
    }

    // Access methods

    void setDato(string d) {
        dato = d;
    }

    void setContador(int contador) {
        nodoArbol::contador = contador;
    }

    string getDato(int pos) {
        return dato;
    }

    int getContador() {
        return contador;
    }


    nodoArbol *getIzq() {
        return izq;
    }

    void setIzq(nodoArbol *izq) {
        nodoArbol::izq = izq;
    }

    nodoArbol *getDer() const {
        return der;
    }

    void setDer(nodoArbol *der) {
        nodoArbol::der = der;
    }


    void insertar(string d, int c) {

        if (contador < c) {
            if (der != nullptr)
                der->insertar(d, c);
            else
                der = new nodoArbol(d, c);


        } else if (contador > c) {
            if (izq != nullptr)
                izq->insertar(d, c);
            else
                izq = new nodoArbol(d, c);
        } else if (contador == c) {
            if(der!=nullptr)
                der->insertar(d,c);
            else
                der = new nodoArbol(d,c);
        }
    }

    void insertar(nodoArbol *n) {
        if (n != nullptr)
            if (contador < n->getContador()) {
                if (der != nullptr)
                    der->insertar(n);
                else{
                    der = n;
                }
            } else {
                if (izq != nullptr)
                    izq->insertar(n);
                else{
                    izq = n;

                }
            }
    }

    void mostrarOrden() {
        if (der != nullptr)
            der->mostrarOrden();
        cout << ' ' << dato << ' ' << contador << endl;
        if (izq != nullptr)
            izq->mostrarOrden();
    }


    int borrar(string d, int c, nodoArbol *padre, int lado) {
        nodoArbol *derAux = der;
        nodoArbol *izqAux = izq;

        if (d != dato) {
            if (d > dato) {
                if (der == nullptr)
                    return -1;
                if (der->borrar(d, c, this, 0) == 1) {
                    c--;
                    delete derAux;
                }

            } else {
                if (izq == nullptr)
                    return -1;
                if (izq->borrar(d, c, this, 1)) {
                    c--;
                    delete izqAux;

                }

            }
        } else {
            if (lado) {
                padre->setIzq(der);
            } else {
                padre->setDer(der);
            }
            der->insertar(izq);
            return 1;
        }
        return 0;
    }


};

#endif //PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOL_H
