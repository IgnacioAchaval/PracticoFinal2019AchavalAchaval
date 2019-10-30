//
// Created by Ignacio Achaval on 25/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLSTR_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLSTR_H

#include <iostream>
using namespace std;

class AVLtreeNode
{
public:
    int height;
    string dato;
    int contador;
    AVLtreeNode *left, *right;
    /* Constructor */
    AVLtreeNode()
    {
        left = NULL;
        right = NULL;
        dato = "";
        contador=0;
        height = 0;
    }

    /* Constructor */
    AVLtreeNode(string n, int c)
    {
        left = NULL;
        right = NULL;
        dato = n;
        contador=c;
        height = 0;
    }

    void setContador(int contador)
    {
        AVLtreeNode::contador = contador;
    }
    int getContador()
    {
        return contador;
    }
};

#endif //PRACTICOFINAL2019ACHAVALACHAVAL_NODOARBOLSTR_H
