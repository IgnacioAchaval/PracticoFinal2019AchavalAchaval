//
// Created by Ignacio Achaval on 25/10/2019.
//

#ifndef PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLSTR_H
#define PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLSTR_H


#include "nodoArbolstr.h"
#include"Arbol.h"

class AVLsearchTree {
private:
    AVLtreeNode *root;
public:
    /* Constructor */
    AVLsearchTree() {
        root = NULL;
    }

    /* Function to check if tree is empty */
    bool isEmpty() {
        return root == NULL;
    }

    /* Make the tree logically empty */
    void makeEmpty() {
        root = NULL;
    }


    /* Function to insert dato */
    void insert(string data) {
        root = insert(data, root);
    }

    /* Function to get height of node */
    int height(AVLtreeNode *t) {
        return t == NULL ? -1 : t->height;
    }

    /* Function to max of left/right node */
    int max(int lhs, int rhs) {
        return lhs > rhs ? lhs : rhs;
    }

    /* Function to insert dato recursively */
    AVLtreeNode *insert(string x, AVLtreeNode *t) {
        if (t == NULL) {
            t = new AVLtreeNode(x, 1);
        } else if (x < t->dato) {
            t->left = insert(x, t->left);
            //c++;
            if (height(t->left) - height(t->right) == 2)
                if (x < t->left->dato)
                    t = rotateWithLeftChild(t);
                else
                    t = doubleWithLeftChild(t);
        } else if (x > t->dato) {
            t->right = insert(x, t->right);
            //c++;
            if (height(t->right) - height(t->left) == 2)
                if (x > t->right->dato)
                    t = rotateWithRightChild(t);
                else
                    t = doubleWithRightChild(t);
        } else if (x == t->dato) {
            t->contador++;
        }
        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }

    /* Rotate binary tree node with left child */
    AVLtreeNode *rotateWithLeftChild(AVLtreeNode *k2) {
        AVLtreeNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        return k1;
    }

    /* Rotate binary tree node with right child */
    AVLtreeNode *rotateWithRightChild(AVLtreeNode *k1) {
        AVLtreeNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        return k2;
    }

    /*
     * Double rotate binary tree node: first left child
     * with its right child; then node k3 with new left child
     */
    AVLtreeNode *doubleWithLeftChild(AVLtreeNode *k3) {
        k3->left = rotateWithRightChild(k3->left);
        return rotateWithLeftChild(k3);
    }

    /*
     * Double rotate binary tree node: first right child
     * with its left child; then node k1 with new right child
     */
    AVLtreeNode *doubleWithRightChild(AVLtreeNode *k1) {
        k1->right = rotateWithLeftChild(k1->right);
        return rotateWithRightChild(k1);
    }

    /* Functions to count number of nodes */
    int countNodes() {
        return countNodes(root);
    }

    int countNodes(AVLtreeNode *r) {
        if (r == NULL)
            return 0;
        else {
            int l = 1;
            l += countNodes(r->left);
            l += countNodes(r->right);
            return l;
        }
    }

    /* Functions to search for an element */
    bool search(string val) {
        return search(root, val);
    }

    bool search(AVLtreeNode *r, string val) {
        bool found = false;
        while ((r != NULL) && !found) {
            string rval = r->dato;
            if (val < rval)
                r = r->left;
            else if (val > rval)
                r = r->right;
            else {
                found = true;
                break;
            }

            found = search(r, val);
        }
        return found;
    }

    int searchCont(string val) {
        return searchCont(root, val);
    }

    int searchCont(AVLtreeNode *r, string val) {
        bool found = false;
        while ((r != NULL) && !found) {
            string rval = r->dato;
            if (val < rval)
                r = r->left;
            else if (val > rval)
                r = r->right;
            else {
                found = true;
                break;
            }
        }

        if (found)
            return r->getContador();
    }

    /* Function for inorder traversal */
    void inorder() {
        inorder(root);
    }

    void inorder(AVLtreeNode *r) {
        if (r != NULL) {
            inorder(r->left);
            cout << r->dato << "  " << endl;
            inorder(r->right);
        }
    }

    void insertarOrden(Arbol *a) {
        insertarOrden(a, root);
    }


    void insertarOrden(Arbol *a, AVLtreeNode *r) {
        if (r != NULL) {
            insertarOrden(a, r->left);
            a->insertar(r->dato, r->contador);
            insertarOrden(a, r->right);
        }
        //a->insertar(dato,contador);
    }

    /* Function for preorder traversal */
    void preorder() {
        preorder(root);
    }

    void preorder(AVLtreeNode *r) {
        if (r != NULL) {
            cout << r->dato << "  ";
            preorder(r->left);
            preorder(r->right);
        }
    }

    /* Function for postorder traversal */
    void postorder() {
        postorder(root);
    }

    void postorder(AVLtreeNode *r) {
        if (r != NULL) {
            postorder(r->left);
            postorder(r->right);
            cout << r->dato << "  ";
        }
    }
};

#endif //PRACTICOFINAL2019ACHAVALACHAVAL_ARBOLSTR_H