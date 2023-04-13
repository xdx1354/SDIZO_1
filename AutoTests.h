//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_AUTOTESTS_H
#define PROJECT_AUTOTESTS_H
#include <fstream> //import biblioteki fstream
#include "DynamicArray.h"
#include "List.h"
#include "Heap.h"
#include "BST.h"

using namespace std;

class AutoTests {
public:


    AutoTests();
    void generateInput(int amountOfData);
    void testArray(int );
    void testList(int);
    void testHeap(int);
    void testBST(int);
    long average(long[]);
    fstream avgf;
};


#endif //PROJECT_AUTOTESTS_H
