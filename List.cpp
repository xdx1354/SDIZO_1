//
// Created by stani on 28.03.2023.
//
#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    List::head = NULL;
    List::tail = NULL;
    List::current = NULL;
    List::size = 0;
}

void List::deleteList() {
    ListNode *curr;

        while(head!=NULL){
            curr = head;
            head=head->next;
            free(curr);
        }

    size = 0;
}

void List::addAtTheBeginning(int value) {
    if(head == NULL){
        head = new ListNode(value, NULL, NULL);
        tail = head;
    }
    else{
        current = head;
        head = new ListNode(value, NULL, current);
        current->prev = head;
    }
    size++;
    //cout<<size<<endl;
}

void List::addAtPos(int value, int pos) {

    if(pos > size || pos<0){
        cout<<"There is no such element. \n";
    }
    else if(pos == 0){
        addAtTheBeginning(value);
    }
    else if(pos == size - 1){           //konwencja z numeracją elemntów od 0
        addAtTheEnd(value);
    }
    else if(size/2>pos){
        current = head;
        for(int i=0; i<pos; i++){       //po tej petli w current powinien byc element na ktorego
            current = current -> next;  //miejsce zostanie wstawiony nowy
        }

        ListNode *tempNode = new ListNode(value, current->prev, current);
        current ->prev ->next = tempNode;
        current ->prev = tempNode;
        size++;
    }
    else{
        current = tail;
        for(int i=size-1; i>pos; i--){       //po tej petli w current powinien byc element na ktorego
            current = current -> prev;  //miejsce zostanie wstawiony nowy
        }

        ListNode *tempNode = new ListNode(value, current->prev, current);
        current -> prev -> next = tempNode;
        current ->prev = tempNode;
        size++;
    }
    //cout<<size<<endl;
}

void List::addAtTheEnd(int value) {
    if(head == NULL){
        head = new ListNode(value, NULL, NULL);
        tail = head;
    }
    else{
        current = tail;
        tail = new ListNode(value, current, NULL);
        current->next = tail;
    }
    size++;
    //cout<<size<<endl;
}

void List::removeFromBeginning() {
    if(head == NULL){
        cout<<"List is empty \n";
    }
    else{
        current = head->next;
        delete head;
        head = current;
        head -> prev = NULL;
        size--;
        if(size == 0){
            head = NULL;
            current = NULL;
            tail = NULL;
        }
        if(size == 1){
            tail = head;
        }
    }
}

void List::removeFromEnd() {

    if(head == NULL){
        cout<<"The list is empty";
    }
    else{
        current = tail ->prev;
        delete[] tail;
        tail = current;
        tail -> next = NULL;
        size--;
        if(size == 0){
            head = NULL;
            tail = NULL;
            current = NULL;
        }
        if(size == 1){
            head = tail;
            current = tail;
        }
    }
}

void List::removeFromPos(int pos) {

    if(pos > size || pos<0){
        cout<<"There is no such element. \n";
    }
    else if(pos == 0){
        removeFromBeginning();
    }
    else if(pos == size - 1){           //konwencja z numeracją elemntów od 0
        removeFromEnd();
    }
    else if(pos<size/2){                //iterujemy od przodu
        current = head;
        for(int i=0; i<pos; i++){       //po tej petli w current powinien byc element do usuniecia
            current = current -> next;  //
        }

        current->prev->next = current -> next;
        current->next->prev = current->prev;
        delete[] current;
        size--;
    }
    else{
        current = tail;
        for(int i=size-1; i>pos; i--){       //po tej petli w current powinien byc element na ktorego
            current = current -> prev;  //miejsce zostanie wstawiony nowy
        }
        current->prev->next = current -> next;
        current->next->prev = current->prev;
        delete[] current;
        size--;
    }
}

bool List::find(int value) {

    if(size == 0){
        return false;
    }
    current = head;
    for(int i=0; i<size; i++){
        if(current -> value == value){
            return true;
        }
        current = current -> next;
    }
    return false;
}

void List::print() {
    if(head != nullptr){
        cout<<head->value <<" ";
        current = head -> next;
        while(current != nullptr){      //pętla iteruje od indeksu 1
            cout<<current->value<<" ";
            current = current->next;
        }
        cout<<endl;
    }
    else{
        cout<<"There is nothing to print. \n";
    }
}