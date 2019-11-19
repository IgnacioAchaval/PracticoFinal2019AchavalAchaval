//
// Created by Ignacio Achaval on 31/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLBINARIO_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLBINARIO_H


#include <stdexcept>
#include <iostream>
#include "NodoArbolBinario.h"
#include "ArbolCtr.h"
//#include "Arbol.h"

template<class T>
class ArbolBinario {
private:
    NodoArbolBinario<T> *raiz;
public:
    ArbolBinario();

    /**
     * Agrega un dato al árbol
     * @param clave Clave para agregar el dato
     * @param dato Dato a agregar
     */
    void put(T dato) {
        raiz = put(dato, raiz);
    };

    void insertarOrden(ArbolCtr<T> *a);/* {
        insertarOrden(a, raiz);
    };*/


    /**
     * Busca un dato en el árbol. Si no esta el dato en el árbol
     * tira una excepción
     * @param clave Valor a buscar
     * @return el valor buscado
     */
    T search(T dato) {
        return search(dato, raiz);
    }

    int searchCont(T dato) {
        return searchCont(raiz,dato);
    }

    void remove(T dato);

    int countNodes();

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void vaciar();

    void print();

private:
    NodoArbolBinario<T> *put(T dato, NodoArbolBinario<T> *r);

    //int searchCont(NodoArbolBinario<T> *r,T dato);
    int searchCont(NodoArbolBinario<T> *r, T dato);

    int countNodes(NodoArbolBinario<T> *r);

    void insertarOrden(ArbolCtr<T> *a, NodoArbolBinario<T> *r);

    T search(T dato, NodoArbolBinario<T> *r);

    void preorder(NodoArbolBinario<T> *r);

    void inorder(NodoArbolBinario<T> *r);

    void posorder(NodoArbolBinario<T> *r);

    NodoArbolBinario<T> *remove(T dato, NodoArbolBinario<T> *r);

    NodoArbolBinario<T> *buscarMax(NodoArbolBinario<T> *r, bool *encontre);


    int altura(NodoArbolBinario<T> *r) {
        if (r == nullptr)
            return -1;
        else
            return r->altura;
    }

    NodoArbolBinario<T> *rotarIzq(NodoArbolBinario<T> *k2) {
        NodoArbolBinario<T> *k1 = k2->izq;
        k2->izq =k1->der;
        k1->der =k2;
        k2->altura = max(altura(k2->izq), altura(k2->der)) + 1;
        k1->altura = max(altura(k1->izq), k2->altura) + 1;
        return k1;
    }


    NodoArbolBinario<T> *rotarDer(NodoArbolBinario<T> *k1) {
        NodoArbolBinario<T> *k2 = k1->der;
        k1->der =k2->izq;
        k2->izq =k1;
        k1->altura = max(altura(k1->izq), altura(k1->der)) + 1;
        k2->altura = max(altura(k2->der), k1->altura) + 1;
        return k2;
    }

    NodoArbolBinario<T> *rotarDobleIzq(NodoArbolBinario<T> *k3) {
        k3->izq =rotarDer(k3->izq);
        return rotarIzq(k3);
    }

    NodoArbolBinario<T> *rotarDobleDer(NodoArbolBinario<T> *k1) {
        k1->der =rotarIzq(k1->der);
        return rotarDer(k1);
    }

    int max(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }

    void print(bool esDerecho, const std::string& identacion, NodoArbolBinario<T> *r);
};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolBinario<T>::ArbolBinario() {
    raiz = nullptr;
}


/**
 * Destructor del Arbol
 */
template<class T>
ArbolBinario<T>::~ArbolBinario() {
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
void ArbolBinario<T>::remove(T dato) {
    raiz = remove(dato, raiz);
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolBinario<T>::esVacio() {
    return raiz == nullptr;
}

template<class T>
void ArbolBinario<T>::vaciar() {
    raiz = nullptr;
}


/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolBinario<T>::preorder() {
    preorder(raiz);
}


/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolBinario<T>::inorder() {
    inorder(raiz);
}

template<class T>
void ArbolBinario<T>::insertarOrden(ArbolCtr<T> *a) {
        insertarOrden(a,raiz);
}


/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolBinario<T>::postorder() {
    postorder(raiz);
}


/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolBinario<T>::print() {
    print(true, "", raiz);
}

template<class T>
NodoArbolBinario<T> *ArbolBinario<T>::put(T dato, NodoArbolBinario<T> *r) {

    if (r == nullptr) {
        return new NodoArbolBinario<T>(dato);
    }


    if (dato < r->dato) {
        r->izq =put(dato, r->izq);
        r->contador=1;
        if (altura(r->izq) - altura(r->der) == 2) {
            if (dato < r->izq->dato)
                r = rotarIzq(r);
            else
                r = rotarDobleIzq(r);
        }
    } else if (dato > r->dato) {
        r->der =put(dato, r->der);
        r->contador=1;
        if (altura(r->der) - altura(r->izq) == 2) {
            if (dato > r->der->dato)
                r = rotarDer(r);
            else
                r = rotarDobleDer(r);
        }
    } else if (dato == r->dato) { // Son iguales

        r->contador++;
    }

    if (altura(r->izq) > altura(r->der))
        r->altura = altura(r->izq) + 1;
    else
        r->altura = altura(r->der) + 1;

    return r;
}





template<class T>
void ArbolBinario<T>::insertarOrden(ArbolCtr<T> *a, NodoArbolBinario<T> *r) {
    if (r == nullptr)
        return;
    insertarOrden(a, r->der);
    a->put(r->dato, r->contador);
    insertarOrden(a, r->izq);
}

/* Functions to count number of nodes */
template<class T>
int ArbolBinario<T>::countNodes() {
    return countNodes(raiz);
}
template<class T>
int ArbolBinario<T>::countNodes(NodoArbolBinario<T> *r) {
    if (r == nullptr)
        return 0;
    else {
        int l = 1;
        l += countNodes(r->izq);
        l += countNodes(r->der);
        return l;
    }
}


template<class T>
T ArbolBinario<T>::search(T dato, NodoArbolBinario<T> *r) {
    if (r == nullptr) {
        throw std::out_of_range("Elemento no encontrado");
    }
    if (r->dato == dato)
        return r->dato ;
    if (r->dato > dato)
        return search(dato, r->izq);
    else
        return search(dato, r->der);
}

template<class T>
int ArbolBinario<T>::searchCont(NodoArbolBinario<T> *r, T dato) {
    bool found = false;
    while ((r != nullptr) && !found) {
        T rdato = r->dato;
        if (dato < rdato)
            r = r->izq;
        else if (dato > rdato)
            r = r->der;
        else {
            found = true;
            break;
        }
    }
    if (found)
        return r->getContador();
}

//template<class T>
//int ArbolBinario<T>::searchContt(NodoArbolBinario<T> *r,T dato){
//    bool found = false;
//    while ((r != nullptr) && !found) {
//        T rdato = r->dato;
//        if (dato < rdato)
//            r = r->izq;
//        else if (dato > rdato)
//            r = r->der;
//        else {
//            found = true;
//            break;
//        }
//    }
//    if (found)
//        return r->getContador();
//}

template<class T>
void ArbolBinario<T>::preorder(NodoArbolBinario<T> *r) {
    if (r == nullptr)
        return;

    std::cout << r->dato << " ";
    preorder(r->izq);
    preorder(r->der);
}

template<class T>
void ArbolBinario<T>::inorder(NodoArbolBinario<T> *r) {
    if (r == nullptr)
        return;
        inorder(r->izq);
        cout << r->dato <<'\n';
        inorder(r->der);
}

template<class T>
void ArbolBinario<T>::posorder(NodoArbolBinario<T> *r) {
    if (r == nullptr)
        return;

    posorder(r->izq);
    posorder(r->der);
    cout << r->dato << " ";
}

template<class T>
NodoArbolBinario<T> *ArbolBinario<T>::remove(T dato, NodoArbolBinario<T> *r) {
    NodoArbolBinario<T> *aux;
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
NodoArbolBinario<T> *ArbolBinario<T>::buscarMax(NodoArbolBinario<T> *r, bool *encontre) {
    NodoArbolBinario<T> *ret;
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
void ArbolBinario<T>::print(bool esDerecho, const std::string& identacion, NodoArbolBinario<T> *r) {
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


#endif //PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLBINARIO_H
