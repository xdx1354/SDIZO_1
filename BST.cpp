//
// Created by stani on 28.03.2023.
//

#include "BST.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


BST::BST(){             //konstruktor
    BST::root = nullptr;
    BST::size = 0;
}

void BST::deleteBST(Node *root) {       //destruktor drzewa
//    if (root == nullptr) {
//        return;
//    }
//    deleteBST(root->left);
//    deleteBST(root->right);
//    free(root);
//    size = 0;

}


Node* BST::insertRecursive(Node* current, int value, Node* parent) {

    if (current == nullptr) {               //gdy drzewo puste
        current = new Node(value);
        //cout<<"wstawiono "<<value<<" pod adress "<<current<<endl;

    }
    else if (value <= current->value) {           //
        //cout<<"<";
        current->left = insertRecursive(current->left, value, current);
        current->left->parent = current;
    } else {
        //cout<<">";
        current->right = insertRecursive(current->right, value, current);
        current->right->parent = current;
    }
    return current;
}

void BST::insert(int value) {
    root = insertRecursive(root, value, nullptr);                                //wywołanie funkcji rekurencyjnej
    size++;
}

void BST::printInOrder() {
    if(root != nullptr) {
        inOrder(root);                  //wywoluje rekurencujną funkcję inOrder zaczynając od korzenia
    }
    else{
        cout<<"Drzewo jest puste \n";
    }
}

void BST::inOrder(Node* ptr){       //drukowanie w kolejnosci
    if(ptr == NULL) return;
    inOrder(ptr->left);         //dopóki sie da idziemy w lewo, gdy sie nie da printujemy skrajnie lewy, wracam jedno w góre i skrecamy w prawo. Znowu tak samo
    cout << (ptr -> value) << ", ";
    inOrder(ptr->right);
}

void BST::printPostOrder() {
    if(root != nullptr) {
        postOrder(root);                  //wywoluje rekurencujną funkcję postOrder zaczynając od korzenia
    }
    else{
        cout<<"Drzewo jest puste \n";
    }
}

void BST::postOrder(Node* ptr){       //drukowanie w kolejnosci
    if(ptr == NULL) return;
    postOrder(ptr->left);         //dopóki sie da idziemy w lewo, gdy sie nie da printujemy skrajnie lewy, wracam jedno w góre i skrecamy w prawo. Znowu tak samo
    postOrder(ptr->right);
    cout << (ptr -> value) << ", ";
}

void BST::printPreOrder() {
    if(root != nullptr) {
        preOrder(root);                  //wywoluje rekurencujną funkcję preOrder zaczynając od korzenia
    }
    else{
        cout<<"Drzewo jest puste \n";
    }
}

void BST::preOrder(Node* ptr){       //drukowanie w kolejnosci
    if(ptr == NULL) return;
    preOrder(ptr->left);         //Dopóki się da, idziemy w lewo, gdy sie nie da printujemy skrajnie lewy, wracam jedno w góre i skrecamy w prawo. Znowu tak samo
    preOrder(ptr->right);
    cout << (ptr -> value) << ", ";
}

void BST::deleteRoot() {
    if(root!= nullptr){
        root = deleteNodeRecursive(root, root->value);
        size--;

        balanceTree();                                              // wliczam czas balansowania drzewa
    }
    else{
        cout<<"Drzewo jest puste \n";
    }
}

Node* BST::deleteNodeRecursive(Node* current, int value) {

    if(current == NULL) return NULL;

    else if(value < current->value)
        current->left = deleteNodeRecursive(current -> left, value);
    else if(value > current->value)
        current->right = deleteNodeRecursive(current->right, value);

    else{           //gdy już znajdziemy wartość
        // 1) węzeł jest liściem
        if( current->left == NULL && current->right == NULL){

            delete current;
            current = nullptr;

        }

            // 2) węzeł ma dokładnie jednego syna
        else if(current->left == NULL){

            Node *temp = current;
            current = current->right;
            current->parent = temp->parent;
            delete temp;


        }
        else if(current->right == NULL){

            Node *temp = current;
            current = current->left;
            current->parent = temp->parent;
            delete temp;

        }

            // 3) węzeł ma 2 synów
        else{
            Node* temp = findMin(current->right);
            current->value = temp->value;
            current->right = deleteNodeRecursive(current->right, temp->value);

        }
    }
    return current;

}

Node* BST::findMin(Node* current) {
//    if(current->left == nullptr){
//        return current;
//    }
//    else{
//        findMin(current->left);
//    }

    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}


void BST::leftRotation(Node* x) {

    Node* y = x->right;
    if(y != nullptr){
        x->right = y->left;
        if(y -> left != nullptr){
            y->left->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr){
            root = y;
        }
        else if(x->parent->left == x){
            x->parent->left = y;
        }
        else{
            x->parent->right = y;

        }
        y->left = x;
        x->parent = y;
    }

}

void BST::rightRotation(Node* x){           //x jest teraz y z rotacji w lewo
    Node* y = x->left;
    if(y != nullptr){
        x->left = y->right;
        if(y->right != nullptr){
            y->right->parent = x;
        }
        y->parent = x->parent;
        if(x->parent == nullptr){
            root = y;
        }
        else if(x->parent->left == x){
            x->parent->left = y;
        }
        else{
            x->parent->right = y;
        }
        y->right = x;
        x->parent = y;
    }

}


//Drukowanie struktury drzew w 2D w celach poglądowych. Działa przy małych drzewach.
void BST::print(){
    printRecursive(root,0);
}

void BST::printRecursive(Node * root, int space) {
    if(root == NULL){
        //cout<<"Drzewo jest puste \n";
        return;
    };
    space += 10;
    printRecursive(root->right, space);

    cout<<endl;
    for(int i = 10; i<space; i++){
        cout<<" ";
    }
    cout<< root->value<<endl;

    printRecursive(root->left, space);

}

Node* BST::find(int value){

    try {
        Node *adres = findRecursive(value, root);
        return adres;
    }
    catch(...){
        return NULL;
    }
//    Node* current = root;
//    while(current->value != value){
//        if(current->value>value){
//            current = current->left;
//        }
//        else{
//            current = current->right;
//        }
//        if(current == NULL){
//            return NULL;
//        }
//    }
//    return current;
}

Node *BST::findRecursive(int value, Node *current) {

    if(current == NULL || value == current ->value  ){
        //adres = current;
        //cout<<"ZNALEZIONO";
        return current;
    }
    else if(value < current->value){
        //cout<<"<";
        return findRecursive(value, current->left);

    }
    else {
        //cout<<">";
        return findRecursive(value, current->right);

    }
}

void BST::balanceTree() {
    //1) zmieniam drzew o w skrajnie prawe

    //2) balansowanie drzewa

    Node* prev = root->parent;
    Node* curr = root;

    while (curr != NULL) {              //tworzenie drzewa z tylko prawymi synami
        if (curr->left != NULL) {
                                        // rotate right to reduce left spine
            rightRotation(curr);
            curr = curr->parent;
        } else {
            prev = curr;        //jesli nie to idziemy w prawa sciezke i sprawdzamy lewe poddrzewa
            curr = curr->right;
        }
    }
        curr = root;
    int m = pow(2, floor(log2(size + 1))) - 1; // find largest power of 2 less than size


    for (int i = 0; i < (size - m); i++) {
        // rotate left to balance the tree
        leftRotation(curr);
        curr = curr->parent->right;
    }

    while(m>1){
        m/=2;
        curr = root;

        for (int i = 0; i < m; i++) {
            // rotate left to balance the tree
            leftRotation(curr);
            curr = curr->parent->right;
        }
    }

}
