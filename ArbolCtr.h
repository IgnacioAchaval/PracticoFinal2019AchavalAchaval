//
// Created by Ignacio Achaval on 05/11/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLCTR_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLCTR_H



#include <stdexcept>
#include <iostream>
#include "NodoArbolCtr.h"
//#include "Arbol.h"

using namespace std;

template<class T>
class ArbolCtr {
private:
    NodoArbolCtr<T> *raiz;
public:
    ArbolCtr();

    /**
     * Agrega un dato al árbol
     * @param clave Clave para agregar el dato
     * @param dato Dato a agregar
     */
    void put(T dato, int contador) {
        raiz = put(dato, contador, raiz);
    };

    /**
     * Busca un dato en el árbol. Si no esta el dato en el árbol
     * tira una excepción
     * @param clave Valor a buscar
     * @return el valor buscado
     */
    T search(T dato) {
        return search(dato, raiz);
    }

    void remove(T dato);

    void preorder();

    void inorder();

    void mostrarOcu(T arg);

    void postorder();

    ~ArbolCtr();

    bool esVacio();

    void vaciar();


    void print();

private:
    NodoArbolCtr<T> *put(T dato,int contador, NodoArbolCtr<T> *r);

    T search(T dato, NodoArbolCtr<T> *r);

    void preorder(NodoArbolCtr<T> *r);

    void inorder(NodoArbolCtr<T> *r);

    void mostrarOcu(NodoArbolCtr<T> *r, T arg);

    void posorder(NodoArbolCtr<T> *r);

    NodoArbolCtr<T> *remove(T dato, NodoArbolCtr<T> *r);

    NodoArbolCtr<T> *buscarMax(NodoArbolCtr<T> *r, bool *encontre);


    int altura(NodoArbolCtr<T> *r) {
        if (r == nullptr)
            return -1;
        else
            return r->altura;
    }

    NodoArbolCtr<T> *rotarIzq(NodoArbolCtr<T> *k2) {
        NodoArbolCtr<T> *k1 = k2->izq;
        k2->izq =k1->der;
        k1->der =k2;
        k2->altura = max(altura(k2->izq), altura(k2->der)) + 1;
        k1->altura = max(altura(k1->izq), k2->altura) + 1;
        return k1;
    }


    NodoArbolCtr<T> *rotarDer(NodoArbolCtr<T> *k1) {
        NodoArbolCtr<T> *k2 = k1->der;
        k1->der =k2->izq;
        k2->izq =k1;
        k1->altura = max(altura(k1->izq), altura(k1->der)) + 1;
        k2->altura = max(altura(k2->der), k1->altura) + 1;
        return k2;
    }

    NodoArbolCtr<T> *rotarDobleIzq(NodoArbolCtr<T> *k3) {
        k3->izq =rotarDer(k3->izq);
        return rotarIzq(k3);
    }

    NodoArbolCtr<T> *rotarDobleDer(NodoArbolCtr<T> *k1) {
        k1->der =rotarIzq(k1->der);
        return rotarDer(k1);
    }

    int max(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }

    void print(bool esDerecho, const std::string& identacion, NodoArbolCtr<T> *r);
};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolCtr<T>::ArbolCtr() {
    raiz = nullptr;
}


/**
 * Destructor del Arbol
 */
template<class T>
ArbolCtr<T>::~ArbolCtr() {
    //TODO: hacer destructor
}


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */


/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */



/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T>
void ArbolCtr<T>::remove(T dato) {
    raiz = remove(dato, raiz);
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolCtr<T>::esVacio() {
    return raiz == nullptr;
}

template<class T>
void ArbolCtr<T>::vaciar() {
    raiz = nullptr;
}


/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolCtr<T>::preorder() {
    preorder(raiz);
}


/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolCtr<T>::inorder() {
    inorder(raiz);
}

template<class T>
void ArbolCtr<T>::mostrarOcu(T arg) {
    mostrarOcu(raiz,arg);
}


/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolCtr<T>::postorder() {
    postorder(raiz);
}


/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolCtr<T>::print() {
    print(true, "", raiz);
}

template<class T>
NodoArbolCtr<T> *ArbolCtr<T>::put(T dato, int contador, NodoArbolCtr<T> *r) {

    if (r == nullptr) {
        return new NodoArbolCtr<T>(dato, contador);
    }


    if (contador < r->contador) {
        r->izq =put(dato,contador, r->izq);
        if (altura(r->izq) - altura(r->der) == 2) {
            if (contador < r->izq->contador)
                r = rotarIzq(r);
            else
                r = rotarDobleIzq(r);
        }
    } else if (contador > r->contador) {
        r->der =put(dato,contador, r->der);
        if (altura(r->der) - altura(r->izq) == 2) {
            if (contador > r->der->contador)
                r = rotarDer(r);
            else
                r = rotarDobleDer(r);
        }
    } else if (contador == r->contador) { // Son iguales
        r->setDato(dato);
        }


    if (altura(r->izq) > altura(r->der))
        r->altura = altura(r->izq) + 1;
    else
        r->altura = altura(r->der) + 1;

    return r;
}


template<class T>
T ArbolCtr<T>::search(T dato, NodoArbolCtr<T> *r) {
    if (r == nullptr) {
        throw std::out_of_range("Elemento no encontrado");
    }
    if (r->dato == dato)
        return r->dato;
    if (r->dato > dato)
        return search(dato, r->izq);
    else
        return search(dato, r->der);
}

template<class T>
void ArbolCtr<T>::preorder(NodoArbolCtr<T> *r) {
    if (r == nullptr)
        return;

    std::cout << r->dato << " ";
    preorder(r->izq);
    preorder(r->der);
}

template<class T>
void ArbolCtr<T>::inorder(NodoArbolCtr<T> *r) {
    if (r == nullptr)
        return;
    inorder(r->der);
    cout <<"\n\n\n------------------"<< r->contador<<"------------------\n\n";
    r->dato.print();
    //cout << r->dato << r->contador << '\n';
    inorder(r->izq);
}


template<class T>
void ArbolCtr<T>::posorder(NodoArbolCtr<T> *r) {
    if (r == nullptr)
        return;

    posorder(r->izq);
    posorder(r->der);
    std::cout << r->dato << " ";
}

template<class T>
NodoArbolCtr<T> *ArbolCtr<T>::remove(T dato, NodoArbolCtr<T> *r) {
    NodoArbolCtr<T> *aux;
    if (r == nullptr) {
        throw 404;
    }
    if (r->dato == dato) {
        // Borrar nodo
        if (r->izq == nullptr && r->der == nullptr) {
            delete r;
            return nullptr;
        } else if (r->izq == nullptr && r->der != nullptr) {
            aux = r->der;
            delete r;
            return aux;
        } else if (r->izq != nullptr && r->der == nullptr) {
            aux = r->izq;
            delete r;
            return aux;
        } else if (r->izq != nullptr && r->der != nullptr) {
            bool enc;
            if (r->izq->der != nullptr) {
                aux = buscarMax(r->izq, &enc);
                aux->der =r->der;
                aux->izq =r->izq;
            } else {
                aux = r->izq;
                r->izq->der =r->der;
            }
            delete r;
            return aux;
        }
    } else if (r->dato > dato) {
        r->izq =remove(dato, r->izq);
    } else {
        r->der =remove(dato, r->der);
    }
    return r;
}


template<class T>
NodoArbolCtr<T> *ArbolCtr<T>::buscarMax(NodoArbolCtr<T> *r, bool *encontre) {
    NodoArbolCtr<T> *ret;
    *encontre = false;

    if (r->der == nullptr) {
        *encontre = true;
        return r;
    }

    ret = buscarMax(r->der, encontre);
    if (*encontre) {
        r->der =nullptr;
        *encontre = false;
    }

    return ret;

}

template<class T>
void ArbolCtr<T>::print(bool esDerecho, const std::string& identacion, NodoArbolCtr<T> *r) {
    if (r->der != nullptr) {
        print(true, identacion + (esDerecho ? "     " : "|    "), r->der);
    }
    std::cout << identacion;
    if (esDerecho) {
        std::cout << " /";
    } else {
        std::cout << " \\";
    }
    std::cout << "-- ";
    std::cout << r->dato << std::endl;
    if (r->izq != nullptr) {
        print(false, identacion + (esDerecho ? "|    " : "     "), r->izq);
    }
}

template<class T>
void ArbolCtr<T>::mostrarOcu(NodoArbolCtr<T> *r, T arg) {
    if (r == nullptr)
        return;
    mostrarOcu(r->der,arg);
    for(int i=0; i<r->dato.getTamanio();++i){
        T pal = r->dato.getDato(i);
        if (pal==arg)
            std::cout<< pal<<' '<<r->contador<<endl;
    }
    mostrarOcu(r->izq,arg);
}


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLCTR_H
