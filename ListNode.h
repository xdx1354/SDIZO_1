//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_LISTNODE_H
#define PROJECT_LISTNODE_H


class ListNode {
public:
    int value;
    ListNode* next;         //wskaznik na poprzedni i nastepny element
    ListNode* prev;

    ListNode(int value, ListNode * , ListNode * );    //konstruktor
};


#endif //PROJECT_LISTNODE_H
