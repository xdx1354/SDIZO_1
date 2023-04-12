//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_DYNAMICARRAY_H
#define PROJECT_DYNAMICARRAY_H


class DynamicArray {

public:
    //pola klasy
    int *headPointer;
    int size;

    //metody
    DynamicArray();     //konstruktor
    ~DynamicArray();    //destruktor

    void addAtTheBeginning(int value);
    void addAtTheEnd(int value);
    void addAtPos(int value, int pos);
    void deleteLast();
    void deleteFirst();
    void deletePos(int pos);
    void printArray();
    bool find(int value);



};


#endif //PROJECT_DYNAMICARRAY_H
