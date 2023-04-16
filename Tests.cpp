//
// Created by stani on 07.04.2023.
//

#include "Tests.h"
#include <iostream>
#include <fstream>
#include "DynamicArray.h"
#include "List.h"
#include "Heap.h"
#include "BST.h"
#include "AutoTests.h"
using namespace std;

void Tests::BST_tests() {



    BST bst;
    //ifstream fin("dataFile.txt");
    srand(time(NULL));
    AutoTests autoTests;
    int task = -1;

    while(task != 0){

        cout<<"Binary search tree data structure. Choose what do you want to do: \n";

        cout<<"1. Generate new tree (random elements, predefined size) \n";
        cout<<"2. Generate new tree (elements form file, predefined size)\n";
        cout<<"3. Add new element \n";
        cout<<"4. Delete root \n";
        cout<<"5. Find element \n";
        cout<<"6. Print BST \n";
        cout<<"7. Measure time of: adding, removing, finding.\n";
        cout<<"8. Balance the tree (DSW algorithm).\n";
        cout<<"0. Exit \n";
        cout<<"Type number of chosen task: ";
        cin>>task;

        switch (task) {

            case 0:{
                return;
            }
            case 1:{
                int tempSize=0;
                cout<<"\n\nSize of new tree: ";
                cin>>tempSize;
                cout<<"\nGenerating new tree of size "<<tempSize<<endl;

                for(int i = 0 ;i < tempSize; i++){
                    bst.insert(rand());             //inserting random number
                }
                cout<<endl;
                bst.print();
                break;
            }
            case 2:{
                ifstream fin("dataFile.txt");
                string line;
//                if(bst.size!=0){
//                    bst.deleteBST(bst.root);
//                }
                while(getline (fin, line)){
                    bst.insert(stoi(line));       //casting string to int
                }
                cout<<"\nGenerating new tree from file (\"dataFile.txt\").\n";

                cout<<endl;
                bst.print();
                break;
            }
            case 3:{
                int tempValue;
                cout<<"\nType value of element to add: ";
                cin>>tempValue;
                cout<<"\nAdding "<<tempValue<<" to bst tree.\n";
                bst.insert(tempValue);
                cout<<"Printing in order\n";
                bst.printInOrder();

                cout<<endl;
                bst.print();
                break;
            }
            case 4:{
                cout<<"\n Deleting root... Done.\n";
                bst.deleteRoot();

                break;
            }
            case 5:{
                int tempFind;
                cout<<"What element do you want to find? Type its value: ";
                cin>>tempFind;
                if(bst.find(tempFind)!= NULL){
                    cout<<"\nElement has been found.\n";
                }
                else{
                    cout<<"\nNo such element.\n";
                }

                break;
            }
            case 6:{
                if(bst.size<20){
                    bst.print();
                }
                else{
                    int t;
                    cout<<"\nTree is too big to print it graphically.\n1. Print preorder traversing. \n2. Print inorder traversing.\n3. Print postorder traversing.\nChoose other type of printing:";
                    cin>>t;
                    switch (t) {
                        default:{
                            cout<<"\nWrong number.\n";
                            break;
                        }
                        case 1:{
                            cout<<"Printing pre order...\n";
                            bst.printPreOrder();
                            break;
                        }
                        case 2:{
                            cout<<"Printing in order...\n";
                            bst.printInOrder();
                            break;
                        }
                        case 3:{
                            cout<<"Printing post order...\n";
                            bst.printPostOrder();
                            break;
                        }
                    }
                }

                break;
            }
            case 7:{
                autoTests.testBST(1000);
                autoTests.testBST(10000);
                autoTests.testBST(100000);
                autoTests.testBST(250000);
                autoTests.testBST(500000);
                autoTests.testBST(1000000);
                break;
            }
            case 8:{
                cout<<"Balancing the tree.\n";
                bst.balanceTree();
                if(bst.size<20){
                    bst.print();
                }
                else{
                    cout<<"Tree to big to print graphically.\n";
                }
                break;
            }
            default:{
                cout<<"There is no such task. \n";
                break;
            };
        }

    }
}

void Tests::array_tests() {
    DynamicArray array;
    AutoTests autoTests;
    int task = -1;
    srand(time(NULL));

    while(task != 0){

        cout<<"\n\n Dynamic Array  data structure. Choose what do you want to do: \n";

        cout<<"1. Generate new array (random elements, predefined size) \n";
        cout<<"2. Generate new array (elements form file, predefined size)\n";
        cout<<"3. Add new element (specific place)\n";
        cout<<"4. Delete element (specific value) \n";
        cout<<"5. Find element \n";
        cout<<"6. Print array \n";
        cout<<"7. Measure time of: adding, removing, finding.\n";
        cout<<"0. Exit \n";
        cout<<"Type number of chosen task: ";
        cin>>task;

        switch (task) {

            case 0:{
                return;
            }
            case 1:{
                int tempSize=0;
                cout<<"\n\nSize of new array: ";
                cin>>tempSize;
                cout<<"\nGenerating new array of size "<<tempSize<<endl;

                while(array.size!=0){                                   //usuwanie poprzednich elementów
                    array.deleteFirst();
                }

                for(int i = 0 ;i < tempSize; i++){
                    array.addAtTheBeginning(rand());             //inserting random number
                }
                break;
            }
            case 2:{
                ifstream fin("dataFile.txt");
                string line;

                while(array.size!=0){                                   //usuwanie poprzednich elementów
                    array.deleteFirst();
                }

                while(getline (fin, line)){
                    array.addAtTheBeginning(stoi(line));       //casting string to int
                }
                cout<<"\nGenerating new array from file.\n";
                break;
            }
            case 3:{
                int tempTask;
                cout<<"\nWhere do you want to insert new element\n";
                cout<<"1. At the beginning. \n";
                cout<<"2. At specific position. \n";
                cout<<"3. At the end.\n";
                cin>>tempTask;
                switch(tempTask){
                    default:{
                        cout<<"Wrong number\n";
                        break;
                    }
                    case 1:{
                        int newVal;
                        cout<<"Type value: ";
                        cin>>newVal;
                        cout<<"Inserting "<<newVal<<" at the beginning.";
                        array.addAtTheBeginning(newVal);
                        break;
                    }
                    case 2:{
                        int pos;
                        cout<<"Type the position: ";
                        cin>>pos;
                        if(pos<array.size && pos>=0){
                            int newVal;
                            cout<<"Type value: ";
                            cin>>newVal;
                            cout<<"Inserting "<<newVal<<" at pos "<<pos;
                            array.addAtPos(newVal,pos);

                        }
                        else{
                            cout<<"Wrong position selected.";
                        }
                        break;
                    }
                    case 3:{
                        int newVal;
                        cout<<"Type value: ";
                        cin>>newVal;
                        cout<<"Inserting "<<newVal<<" at the end..";
                        array.addAtTheEnd(newVal);
                        break;
                    }
                }
                array.printArray();
                break;
            }
            case 4:{
                int tempTask;
                cout<<"\nWhich element do you want to delete?\n";
                cout<<"1. From beginning. \n";
                cout<<"2. From specific position. \n";
                cout<<"3. From end.\n";
                cin>>tempTask;
                switch(tempTask){
                    default:{
                        cout<<"Wrong number\n";
                        break;
                    }
                    case 1:{
                        cout<<"Deleting from the beginning.";
                        array.deleteFirst();
                        break;
                    }
                    case 2:{
                        int pos;
                        cout<<"Type the position: ";
                        cin>>pos;
                        if(pos<array.size && pos>=0){
                            array.deletePos(pos);
                            cout<<"Deleting from pos: "<<pos;
                        }
                        else{
                            cout<<"Wrong position selected.";
                        }
                        break;
                    }
                    case 3:{
                        cout<<"Deleting from the end.";
                        array.deleteLast();
                        break;
                    }
                }
                array.printArray();
                break;
            }
            case 5:{
                int tempFind;
                cout<<"Type element value: ";
                cin>>tempFind;

                if(array.find(tempFind)){
                    cout<<"Element has been found.\n";
                }
                else{
                    cout<<"Element not found. \n";
                }
                break;
            }
            case 6:{
                cout<<"Printing array:\n";
                array.printArray();
                break;
            }
            case 7:{

                autoTests.testArray(1000);      //testing for 1000 elements
                autoTests.testArray(10000);
                autoTests.testArray(100000);
                autoTests.testArray(250000);
                autoTests.testArray(500000);
                autoTests.testArray(1000000);

                break;
            }
            default:{
                cout<<"There is no such task. \n";
                break;
            };
        }
    }
}

void Tests::list_tests() {
    List list;
    int task = -1;
    srand(time(NULL));
    AutoTests autoTests;

    while(task != 0){

        cout<<"\n\n List data structure. Choose what do you want to do: \n";

        cout<<"1. Generate new list (random elements, predefined size) \n";
        cout<<"2. Generate new list (elements form file, predefined size)\n";
        cout<<"3. Add new element (specific place)\n";
        cout<<"4. Delete element (specific value) \n";
        cout<<"5. Find element \n";
        cout<<"6. Print list \n";
        cout<<"7. Measure time of: adding, removing, finding.\n";
        cout<<"0. Exit \n";
        cout<<"Type number of chosen task: ";
        cin>>task;

        switch (task) {

            case 0:{
                return;
            }
            case 1:{
                int tempSize=0;
                cout<<"\n\nSize of new array: ";
                cin>>tempSize;
                cout<<"\nGenerating new array of size "<<tempSize<<endl;

                if(list.size!=0){
                    list.deleteList();
                }

                for(int i = 0 ;i < tempSize; i++){
                    list.addAtTheBeginning(rand());             //inserting random number
                }
                list.print();
                break;
            }
            case 2:{
                ifstream fin("dataFile.txt");
                string line;


                if(list.size!=0){
                    list.deleteList();
                }

                while(getline (fin, line)){
                    list.addAtTheBeginning(stoi(line));       //casting string to int
                }
                cout<<"\nGenerating new array from file.\n";
                list.print();
                break;
            }
            case 3:{
                int tempTask;
                cout<<"\nWhere do you want to insert new element\n";
                cout<<"1. At the beginning. \n";
                cout<<"2. At specific position. \n";
                cout<<"3. At the end.\n";
                cin>>tempTask;
                switch(tempTask){
                    default:{
                        cout<<"Wrong number\n";
                        break;
                    }
                    case 1:{
                        int newVal;
                        cout<<"Type value: ";
                        cin>>newVal;
                        cout<<"Inserting "<<newVal<<" at the beginning.";
                        list.addAtTheBeginning(newVal);
                        break;
                    }
                    case 2:{
                        int pos;
                        cout<<"Type the position: ";
                        cin>>pos;
                        if(pos<list.size && pos>=0){
                            int newVal;
                            cout<<"Type value: ";
                            cin>>newVal;
                            cout<<"Inserting "<<newVal<<" at pos "<<pos;
                            list.addAtPos(newVal,pos);

                        }
                        else{
                            cout<<"Wrong position selected.";
                        }
                        break;
                    }
                    case 3:{
                        int newVal;
                        cout<<"Type value: ";
                        cin>>newVal;
                        cout<<"Inserting "<<newVal<<" at the end..";
                        list.addAtTheEnd(newVal);
                        break;
                    }
                }
                list.print();
                break;
            }
            case 4:{
                int tempTask;
                cout<<"\nWhich element do you want to delete?\n";
                cout<<"1. From beginning. \n";
                cout<<"2. From specific position. \n";
                cout<<"3. From end.\n";
                cin>>tempTask;
                switch(tempTask){
                    default:{
                        cout<<"Wrong number\n";
                        break;
                    }
                    case 1:{
                        cout<<"Deleting from the beginning.";
                        list.removeFromBeginning();
                        break;
                    }
                    case 2:{
                        int pos;
                        cout<<"Type the position: ";
                        cin>>pos;
                        if(pos<list.size && pos>=0){
                            list.removeFromPos(pos);
                            cout<<"Deleting from pos: "<<pos;
                        }
                        else{
                            cout<<"Wrong position selected.";
                        }
                        break;
                    }
                    case 3:{
                        cout<<"Deleting from the end.";
                        list.removeFromEnd();
                        break;
                    }
                }
                list.print();
                break;
            }
            case 5:{
                int tempFind;
                cout<<"Type element value: ";
                cin>>tempFind;

                if(list.find(tempFind)){
                    cout<<"Element has been found.\n";
                }
                else{
                    cout<<"Element not found. \n";
                }
                break;
            }
            case 6:{
                cout<<"Printing array:\n";
                list.print();
                break;
            }
            case 7:{
                autoTests.testList(1000);
                autoTests.testList(10000);
                autoTests.testList(100000);
                autoTests.testList(250000);
                autoTests.testList(500000);
                autoTests.testList(1000000);
                break;
            }
            default:{
                cout<<"There is no such task. \n";
                break;
            };
        }

    }
}

void Tests::heap_tests() {
    AutoTests autoTests;
    Heap heap;
    int task = -1;
    srand(time(NULL));

    while(task != 0){

        cout<<"\n\n List data structure. Choose what do you want to do: \n";

        cout<<"1. Generate new heap (random elements, predefined size) \n";
        cout<<"2. Generate new heap (elements form file, predefined size)\n";
        cout<<"3. Add new element \n";
        cout<<"4. Delete root \n";
        cout<<"5. Find element \n";
        cout<<"6. Print heap \n";
        cout<<"7. Measure time of: adding, removing, finding.\n";
        cout<<"0. Exit \n";
        cout<<"Type number of chosen task: ";
        cin>>task;

        switch (task) {

            case 0:{
                return;
            }
            case 1:{
                int tempSize=0;
                cout<<"\n\nSize of new heap: ";
                cin>>tempSize;
                cout<<"\nGenerating new heap of size "<<tempSize<<endl;

                while(heap.size!=0){
                    heap.removeRoot();                  //usuwanie poprzednich danych
                }

                for(int i = 0 ;i < tempSize; i++){
                    heap.add(rand());             //inserting random number
                }

                heap.print();
                break;
            }
            case 2:{
                ifstream fin("dataFile.txt");
                string line;

                while(heap.size!=0){                    //usuwanie poprzednich danych
                    heap.removeRoot();
                }

                while(getline (fin, line)){
                    heap.add(stoi(line));       //casting string to int
                }
                cout<<"\nGenerating new heap from file.\n";
                heap.print();
                break;
            }
            case 3:{
                int tempValue;
                cout<<"\nType value of element to add: ";
                cin>>tempValue;
                cout<<"\nAdding "<<tempValue<<" to heap.\n";
                heap.add(tempValue);
                heap.print();
                break;
            }
            case 4:{
                cout<<"Deleting from the beginning.";
                heap.removeRoot();
                heap.print();
                break;
            }
            case 5:{
                int tempFind;
                cout<<"Type element value: ";
                cin>>tempFind;

                if(heap.find(tempFind)){
                    cout<<"Element has been found.\n";
                }
                else{
                    cout<<"Element not found. \n";
                }
                break;
            }
            case 6:{
                cout<<"Printing heap:\n";
                heap.print();
                break;
            }
            case 7:{
                autoTests.testHeap(1000);
                autoTests.testHeap(10000);
                autoTests.testHeap(100000);
                autoTests.testHeap(250000);
                autoTests.testHeap(500000);
                autoTests.testHeap(1000000);
                break;
            }
            default:{
                cout<<"There is no such task. \n";
                break;
            };
        }
    }
}