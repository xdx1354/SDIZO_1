//
// Created by Stanislaw on 28.03.2023.
//

#include <iostream>
#include "DynamicArray.h"

using namespace std;

//Konstruktor
DynamicArray::DynamicArray(){
    DynamicArray::headPointer = NULL;
    DynamicArray::size = 0;
};

//Destruktor
DynamicArray::~DynamicArray() {
    if(headPointer != NULL)
        delete[]headPointer;
}

void DynamicArray::addAtTheBeginning(int value) {

    int *newPointer = new int[size+1];      //allocating memory for new bigger array
    newPointer[0] = value;                  //adding value to the beginning

    for(int i=0; i<size; i++){
        newPointer[1 + i] = headPointer[i]; //copping values from previous array
    }

    delete[] headPointer;                     //releasing memory of previous array
    headPointer = newPointer;
    size++;
}

void DynamicArray::addAtTheEnd(int value) {
    int *newPointer = new int[size+1];      //allocating memory for new bigger array

    for(int i=0; i<size; i++){
        newPointer[i] = headPointer[i]; //copping values from previous array
    }

    newPointer[size] = value;

    delete[] headPointer;                     //releasing memory of previous array
    headPointer = newPointer;
    size++;
}

void DynamicArray::addAtPos(int value, int pos) {

    if( pos < 0 || pos > size){
        cout<<"Error, no such position in array";
    }
    else{

        int *newPointer = new int[size+1];      //allocating memory for new bigger array

        for(int i=0; i<pos; i++){
            newPointer[i] = headPointer[i]; //copping values from previous array
        }

        newPointer[pos] = value;

        for(int i=0; i<size; i++){
            newPointer[i+1] = headPointer[i]; //copping values from previous array
        }

        delete[] headPointer;                     //releasing memory of previous array
        headPointer = newPointer;
        size++;

    }


}

void DynamicArray::deleteFirst() {

    int *tmpCopy = headPointer;
    size--;

    headPointer = new int[size];
    for(int i = 0; i < size; i++){
        headPointer[i] = tmpCopy[i+1];
    }
    delete [] tmpCopy;

}

void DynamicArray::deleteLast() {
    if(size>0){
        int *newPointer = new int[size-1];      //allocating memory for new smaller array

        for(int i=0; i<size-1; i++){
            newPointer[i] = headPointer[i];
        }

        delete[] headPointer;
        headPointer = newPointer;
        size--;
    }
    else{
        cout<<"Cant remove last element because the array is empty \n";
    }
}

void DynamicArray::deletePos(int pos) {
    if(pos == 0){
        deleteFirst();
    }
    else if(size>pos && pos>0){
        int *newPointer = new int[size-1];
        for(int i=0; i<pos; i++){
            newPointer[i] = headPointer[i];
        }
        for(int i=pos; i<size-1; i++){
            newPointer[i] = headPointer[i+1];
        }

        delete[] headPointer;
        headPointer = newPointer;
        size--;
    }
    else{
        cout<<"There is no such element in array \n";
    }

}

void DynamicArray::printArray() {
    if(size>0){
        for(int i=0; i<size; i++){
            cout<<headPointer[i]<<", ";
        }
        cout<<"\n";
    }
    else{
        cout<<"The array is empty.\n";
    }

}

bool DynamicArray::find(int value) {
    for(int i=0; i<size; i++){
        if(headPointer[i] == value){
            //cout<<"The value is on "<<i<<" position in array.\n";
            return true;
        }
    }
    //cout<<"There is no such value. \n";
    return false;
}
