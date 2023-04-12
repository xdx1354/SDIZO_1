//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_HEAP_H
#define PROJECT_HEAP_H


class Heap {
public:
    int arr[1000000];
    int size;

    Heap();
    //~Heap();

    int parent(int id);
    int left(int id);
    int right(int id);
    void add(int value);
    void removeRoot();
//    void removeValue(int val);
//    void removePos(int pos);
    bool find(int);
    void print();
    void fix_up(int);
    void fix_down(int);

};


#endif //PROJECT_HEAP_H
