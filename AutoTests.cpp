//
// Created by stani on 05.04.2023.
//

#include "AutoTests.h"
#include "DynamicArray.h"
#include "Time.h"
#include "List.h"
#include "Heap.h"
#include "BST.h"
#include <iostream>
#include <fstream>
#include <stdio.h>


#include <stdlib.h>
#include <conio.h>


using namespace std;


AutoTests::AutoTests() {
    //result data is separeted by newline
    avgf.open("D:\\PWR\\4 sem\\SDIZO\\Projekt\\avg.txt", fstream::out);

}

long AutoTests::average(long tab[]) {
    long sum;
    for(int i = 0; i<50; i++){
        sum+=tab[i];
    }
    return  sum/50;
}

void AutoTests::generateInput(int amountOfData) {
    //ofstream dataFile(R"(D:\PWR\4 sem\SDIZO\Projekt\PROJECT\dataFile.txt)");
    ofstream  dataFile("dataFile.txt");
    srand((time(NULL)));

    //generating random numbers. They won't be unique. Range = <1, 2*amountOfData>
    //Each number will be in new line in dataFile.txt
    for(int i=0; i<amountOfData; i++){

        int randomNumber = (rand()%(2*amountOfData))+1;
        dataFile<<randomNumber << "\n";
    }

    dataFile.close();
}

void AutoTests::testArray(int amountOfData) {

    srand((time(NULL)));
    string size = to_string(amountOfData);
    string location = R"(D:\PWR\4 sem\SDIZO\Projekt\POMIARY\)";
    DynamicArray *array;                                        // pointer to array structure
    Time time;
    cout<<"\nBeginning automatic Array test for " <<amountOfData<<endl;
    long long avg = 0;
    avgf<<"\nBeginning automatic Array test for " <<amountOfData<<endl;

    //TESTING ADDING AT BEGINNING
    string name = location + "ARRAY_add_at_the_BEGINNING_" + size + ".txt";
    ofstream fout(name);

    for(int j = 0; j<10; j++){

        array = new DynamicArray;                                  // creating new structure
        array -> headPointer = new int[amountOfData];
        array->size = amountOfData;
        for(int i=0; i<amountOfData; i++){

            array->headPointer[i] =rand();
        }

        for(int i=0; i<5; i++){
            time.start();
            array->addAtTheBeginning(rand());
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete array;
    }

    fout.close();
    avgf<<"add at beginning: "<<avg*0.02<<endl;
    avg = 0;

    //TESTING ADDING AT THE END
    string name2 = location + "ARRAY_add_at_the_END_" + size + ".txt";
    fout.open(name2);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów dodawanych

        array = new DynamicArray;                                  // creating new structure
        array -> headPointer = new int[amountOfData];
        array->size = amountOfData;
        for(int i=0; i<amountOfData; i++){

            array->headPointer[i] =rand();
        }

        for(int i=0; i<5; i++){
            time.start();
            array->addAtTheEnd(rand());
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        fout<<"\n";
        delete array;
    }
    fout.close();
    avgf<<"add at end: "<<avg*0.02<<endl;
    avg = 0;

    //TESTING ADDING AT RANDOM POS
    string name3 = location + "ARRAY_add_at_RANDOM_" + size + ".txt";
    fout.open(name3);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów dodawanych

        array = new DynamicArray;                                  // creating new structure
        array -> headPointer = new int[amountOfData];
        array->size = amountOfData;
        for(int i=0; i<amountOfData; i++){

            array->headPointer[i] =rand();
        }

        for(int i=0; i<5; i++){
            time.start();
            array->addAtPos(rand(), (rand()%(array->size-2)) +1);
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }

        delete array;
    }
    fout.close();
    avgf<<"add random: "<<avg*0.02<<endl;
    avg = 0;


//TESTING DELETING FIRST
    string name4 = location + "ARRAY_delete_FIRST_" + size + ".txt";
    fout.open(name4);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów usunietych

        array = new DynamicArray;                                  // creating new structure
        array -> headPointer = new int[amountOfData];
        array->size = amountOfData;
        for(int i=0; i<amountOfData; i++){

            array->headPointer[i] =rand();
        }

        for(int i=0; i<5; i++){
            time.start();
            array->deleteFirst();
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete array;
    }
    fout.close();
    avgf<<"delete first: "<<avg*0.02<<endl;
    avg = 0;

    //TESTING DELETING LAST
    string name5 = location + "ARRAY_delete_LAST_" + size + ".txt";
    fout.open(name5);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów usunietych

        array = new DynamicArray;                                  // creating new structure
        array -> headPointer = new int[amountOfData];
        array->size = amountOfData;
        for(int i=0; i<amountOfData; i++){

            array->headPointer[i] =rand();
        }

        for(int i=0; i<5; i++){
            time.start();
            array->deleteLast();
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete array;
    }
    fout.close();
    avgf<<"delete last: "<<avg*0.02<<endl;
    avg = 0;


    //TESTING DELETING RANDOM
    string name6 = location + "ARRAY_delete_RANDOM_" + size + ".txt";
    fout.open(name6);

    for(int j = 0; j<10; j++){             // 10 testów po 10 elementów usunietych

        array = new DynamicArray;                                  // creating new structure
        array -> headPointer = new int[amountOfData];
        array->size = amountOfData;
        for(int i=0; i<amountOfData; i++){

            array->headPointer[i] =rand();
        }

        for(int i=0; i<5; i++){
            time.start();
            array->deletePos((rand()%(array->size-2)) +1);
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete array;
    }
    fout.close();
    avgf<<"delete ranodm: "<<avg*0.02<<endl;
    avg = 0;


    //TESTING FIND()

    string name7 = location + "ARRAY_FIND_" + size + ".txt";
    fout.open(name7);

    for(int j = 0; j < 10; j++){             // 10 testów po 10 elementów usunietych

        array = new DynamicArray;                                  // creating new structure
        array -> headPointer = new int[amountOfData];
        array->size = amountOfData;
        for(int i=0; i<amountOfData; i++){

            array->headPointer[i] =rand();
        }

        for(int i = 0; i < 5; i++){
            time.start();
            array->find(rand());
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete array;
    }
    fout.close();
    avgf<<"find: "<<avg*0.02<<endl;
    avg = 0;

}


void AutoTests::testList(int amountOfData) {

    srand((time(NULL)));
    string size = to_string(amountOfData);
    string location = R"(D:\PWR\4 sem\SDIZO\Projekt\POMIARY\)";
    List *list;                                       // pointer to array structure
    Time time;
    cout<<"\nBeginning automatic list for " <<amountOfData<<endl;
    long long avg = 0;
    avgf<<"\nBeginning automatic list test for " <<amountOfData<<endl;

    //TESTING ADDING AT THE BEGINNING
    string name = location + "LIST_add_at_the_BEGINNING_" + size + ".txt";
    ofstream fout(name);

    for(int j = 0; j<10; j++){

        list = new List;                                  // creating new structure

        for(int i=0; i<amountOfData; i++){
            list->addAtTheBeginning(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            list->addAtTheBeginning(rand());
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete list;
    }
    fout.close();
    avgf<<"add at beginning: "<<avg*0.02<<endl;
    avg = 0;

    //TESTING ADDING AT THE END
    string name2 = location + "LIST_add_at_the_END_" + size + ".txt";
    fout.open(name2);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów dodawanych

        list = new List;
        for(int i=0; i<amountOfData; i++){
            list->addAtTheEnd(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            list->addAtTheEnd(rand());
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete list;
    }
    fout.close();
    avgf<<"add end: "<<avg*0.02<<endl;
    avg = 0;


    //TESTING ADDING AT RANDOM POS
    string name3 = location + "LIST_add_at_RANDOM_" + size + ".txt";
    fout.open(name3);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów dodawanych

        list = new List;

        for(int i=0; i<amountOfData; i++){
            list->addAtTheEnd(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            list->addAtPos(rand(), (rand()%(list->size-2)) +1);
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }

        delete list;
    }
    fout.close();
    avgf<<"add random: "<<avg*0.02<<endl;
    avg = 0;


    //TESTING DELETING FIRST
    string name4 = location + "LIST_delete_FIRST_" + size + ".txt";
    fout.open(name4);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów usunietych

        list = new List;

        for(int i=0; i<amountOfData; i++){
            list->addAtTheEnd(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            list->removeFromBeginning();
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete list;
    }
    fout.close();
    avgf<<"delete first: "<<avg*0.02<<endl;
    avg = 0;


    //TESTING DELETING LAST
    string name5 = location + "LIST_delete_LAST_" + size + ".txt";
    fout.open(name5);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów usunietych

        list = new List;

        for(int i=0; i<amountOfData; i++){
            list->addAtTheEnd(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            list->removeFromEnd();
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete list;
    }
    fout.close();
    avgf<<"delete last "<<avg*0.02<<endl;
    avg = 0;


    //TESTING DELETING RANDOM
    string name6 = location + "LIST_delete_RANDOM_" + size + ".txt";
    fout.open(name6);

    for(int j = 0; j<10; j++){             // 100 testów po 100 elementów usunietych

        list = new List;

        for(int i=0; i<amountOfData; i++){
            list->addAtTheEnd(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            list->removeFromPos((rand()%(list->size-2)) +1);
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete list;
    }
    fout.close();
    avgf<<"remove random: "<<avg*0.02<<endl;
    avg = 0;

    //TESTING FIND()
    string name7 = location + "LIST_FIND_" + size + ".txt";
    fout.open(name7);

    for(int j = 0; j < 10; j++){             // 100 testów po 100 elementów usunietych

        list = new List;

        for(int i=0; i<amountOfData; i++){
            list->addAtTheEnd(rand());
        }

        for(int i = 0; i < 5; i++){
            time.start();
            list->find(-1);             // wyszukuję -1 by otrzymać liniowość
            time.stop();
            fout<<time.returnTime()<<"\n";
            avg += time.returnTime();
        }
        delete list;
    }
    fout.close();
    avgf<<"find: "<<avg*0.02<<endl;
    avg = 0;

}


void AutoTests::testHeap(int amountOfData) {

    srand((time(NULL)));
    string sizeData = to_string(amountOfData);
    string location = R"(D:\PWR\4 sem\SDIZO\Projekt\POMIARY\)";
    Heap* heap;                                       // pointer to array structure
    Time time;
    cout<<"\nBeginning automatic heap test for " <<amountOfData<<endl;
    long tempResults[50];
    long sum;


    //TESTING ADDING
    string name = location + "HEAP_ADDING_" + sizeData + ".txt";
    ofstream fout(name);


    for(int j = 0; j<10; j++){

        heap = new Heap;                                  // creating new structure

        for(int i=0; i<amountOfData; i++){
            heap->add(rand());
        }
        cout<<"Heap sizeData after: " << heap->size<<endl;

        for(int i=0; i<5; i++){
            cout<<"Heap sizeData before: " << heap->size<<endl;
            time.start();
            heap->add(1);
            cout<<"Adding new element at pos: " << heap->size<<endl;
            time.stop();
            fout<<time.returnTime()<<"\n";


        }
        delete heap;
    }

    fout.close();


    //TESTING DELETING ROOT
    string name2 = location + "HEAP_deleting_ROOT_" + sizeData + ".txt";
    fout.open(name2);

    for(int j = 0; j<10; j++){

        heap = new Heap;                                  // creating new structure

        for(int i=0; i<amountOfData; i++){
            heap->add(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            heap->removeRoot();
            time.stop();
            fout<<time.returnTime()<<"\n";
        }
        fout<<"\n";
        //cout<<"Heap sizeData after: " << heap->sizeData<<endl;
        delete heap;
    }
    fout.close();


    //TESTING FIND()
    string name4 = location + "HEAP_FIND_" + sizeData + ".txt";
    fout.open(name4);

    for(int j = 0; j<10; j++){

        heap = new Heap;                                  // creating new structure

        for(int i=0; i<amountOfData; i++){
            heap->add(rand());
        }

        for(int i=0; i<5; i++){
            time.start();
            heap->find(rand());
            time.stop();
            fout<<time.returnTime()<<"\n";
        }
        fout<<"\n";
        //cout<<"Heap sizeData after: " << heap->sizeData<<endl;
        delete heap;
    }
    fout.close();

}

//Drzewo BST bedzie zawsze zbalansowane
void AutoTests::testBST(int amountOfData) {

    srand((time(NULL)));
    string location = R"(D:\PWR\4 sem\SDIZO\Projekt\POMIARY\)";
    string size = to_string(amountOfData);
    BST* bst;                                      // pointer to array structure
    Time time;
    cout<<"\nBeginning automatic BST test for " <<amountOfData<<endl;


    //TESTING ADDING
    string name = location + "BST_ADDING_" + size + ".txt";
    ofstream fout(name);

    for(int j = 0; j<10; j++){

        bst = new BST;                             // creating new structure

        for(int i=0; i<amountOfData; i++){
            bst->insert(rand());
        }
        bst->balanceTree();         //balansowanie drzewa

        for(int i=0; i<5; i++){
            time.start();
            bst->insert(rand());
            time.stop();
            bst->balanceTree();         //balansowanie drzewa
            fout<<time.returnTime()<<"\n";
        }
        delete bst;
    }
    fout.close();


    //TESTING DELETING ROOT

    string name2 = location + "BST_deleting_ROOT_" + size + ".txt";
    fout.open(name2);

    for(int j = 0; j<10; j++){

        bst = new BST;                             // creating new structure

        for(int i=0; i<amountOfData; i++){
            bst->insert(rand());
        }

        bst->balanceTree();

        for(int i=0; i<5; i++){
            time.start();
            bst->deleteRoot();
            time.stop();
            bst->balanceTree();         //balansowanie drzewa
            fout<<time.returnTime()<<"\n";
        }
        delete bst;
    }
    fout.close();



    //TESTING FIND()
    string name3 = location + "BST_FIND_" + size + ".txt";
    fout.open(name3);

    for(int j = 0; j<10; j++){

        bst = new BST;                             // creating new structure

        for(int i=0; i<amountOfData; i++){
            bst->insert(rand());
        }

        bst->balanceTree();

        for(int i=0; i<10; i++){
            time.start();
            bst->find(rand());
            time.stop();
            fout<<time.returnTime()<<"\n";
        }
        delete bst;
    }
    fout.close();

}