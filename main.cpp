#include "iostream"
#include "Heap.h"
#include "List.h"
#include "DynamicArray.h"
#include "BST.h"
#include "Time.h"
#include "AutoTests.h"
#include "Tests.h"

using namespace std;


int main(){

    AutoTests autoTests;
    autoTests.generateInput(40);

    Tests tests;

    cout<<"Stanislaw Kurzyp 264477\n SDiZO, Pn T? 9:15\n";              //TODO: tydzień jaki?


    int x = -1;
    while(x!=0){

        cout<<"1. Dynamic Array. \n";
        cout<<"2. Doubly Linked List.\n";
        cout<<"3. Heap.\n";
        cout<<"4. Binary Search Tree.\n";
        cout<<"0. Exit\n";
        cout<<"\nChoose task: \n";
        cin>>x;
        switch(x){
            default:{
                cout<<"Wrong number.\n";
                break;
            }
            case 0:{

                break;
            }

            case 1:{
                tests.array_tests();
                break;
            }
            case 2:{
                tests.list_tests();
                break;
            }
            case 3:{
                tests.heap_tests();
                break;
            }
            case 4:{
                tests.BST_tests();
                break;
            }
        }
    }

//    autoTests.testArray(1000);
//    autoTests.testArray(10000);
//    autoTests.testArray(20000);
//    autoTests.testArray(50000);
//    autoTests.testArray(100000);
//    autoTests.testArray(250000);
//    autoTests.testArray(500000);
////
////
//    autoTests.testList(1000);
//    autoTests.testList(10000);
//    autoTests.testList(20000);
//    autoTests.testList(50000);
//    autoTests.testList(100000);
//    autoTests.testList(250000);
//    autoTests.testList(500000);
//
//
//    autoTests.testHeap(1000);
//    autoTests.testHeap(10000);
//    autoTests.testHeap(20000);
//    autoTests.testHeap(50000);
//    autoTests.testHeap(100000);
//    autoTests.testHeap(250000);
//    autoTests.testHeap(500000);
//
//
//    autoTests.testBST(1000);
//    autoTests.testBST(10000);
//    autoTests.testBST(20000);
//    autoTests.testBST(50000);
//    autoTests.testBST(100000);
//    autoTests.testBST(250000);
//    autoTests.testBST(500000);

}