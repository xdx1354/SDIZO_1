//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H


#include "ListNode.h"

class List {
public:
    ListNode *head;
    ListNode *tail;
    ListNode *current;
    int size;

    List();

    void deleteList();

    void addAtTheBeginning(int value);

    void addAtTheEnd(int value);

    void addAtPos(int value, int pos);

    void removeFromBeginning();

    void removeFromEnd();

    void removeFromPos(int pos);

    bool find(int value);
    void print();
};


#endif //PROJECT_LIST_H
