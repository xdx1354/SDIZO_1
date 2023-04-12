//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_BST_H
#define PROJECT_BST_H

#include "Node.h"

class BST {
public:
    int size;


    BST();                  //konstruktor
    void deleteBST(Node*);  //destruktor

    void insert(int value);
    void deleteRoot();
    void leftRotation(Node *);
    void rightRotation(Node *);
    void balanceTree();
    Node* find(int value);
    Node* findRecursive(int value, Node* current);
    Node* findMin(Node*);
    Node* insertRecursive(Node*, int, Node*);

    //PRINTING
    void printInOrder();
    void inOrder(Node*);
    void printPostOrder();
    void postOrder(Node*);
    void printPreOrder();
    void preOrder(Node*);
    void print();
    void printRecursive(Node*, int);

    Node* deleteNodeRecursive(Node *current, int value);


    Node *root;



};

#endif //PROJECT_BST_H
