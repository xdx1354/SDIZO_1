//
// Created by stani on 29.03.2023.
//

#include "Heap.h"
#include "iostream"

using namespace std;


Heap::Heap() {
    Heap::size = 0;
}

int Heap::parent(int id) {
    return (id-1)/2;
}

int Heap::left(int id) {
    return (2*id + 1);
}

int Heap::right(int id) {
    return (2*id + 2);
}

void Heap::add(int value) {
    int i, j;

    i = size;
    size++;
    j = ( i - 1 ) / 2;

    while( i > 0 && arr[ j ] < value )
    {
        arr[i] = arr[j];
        i = j;
        j = ( i - 1 ) / 2;
    }

    arr[i] = value;

}

void Heap::removeRoot() {                      //usuwanie korzenia
    if(size>0){                             //sprawdzam, czy korzeń istnieje
        arr[0] = arr[size -1];
        size--;
        fix_down(0);        //pos = 0, ponieważ powyższa funkcja usuwa tylko korzeń
    }
}

bool Heap::find(int value) {
    for(int i=0; i < size; i++){
        if(arr[i] == value){
            return true;
        }
    }
    return false;
}

void Heap::fix_up(int pos){

    //V2
    int i = size-1;
    while (i!=0 && arr[parent(i)] > arr[i]){
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }

}

//naprawa po usunięciu elementu i wstawieniu skrajnie prawego liścia
void Heap::fix_down(int pos) {

    while(arr[pos*2 + 1] > arr[pos] || arr[pos*2 + 2] > arr[pos]){
        if(arr[pos*2 + 1] > arr[pos]) {
            if(arr[pos*2 + 1] > arr[pos*2+2]){
                swap(arr[pos * 2 + 1], arr[pos]);                    //zamiana miejscem z wiekszym z synow
                pos = pos * 2 + 1;
            }
            else{
                swap(arr[pos*2 + 2], arr[pos]);
                pos = pos*2+2;
            }
        }
        else if(arr[pos*2 + 2] > arr[pos]){
            swap(arr[pos*2 + 2], arr[pos]);
            pos = pos*2+2;
        }
        if( (pos*2 + 2)>size) // to znaczy, że nie ma syna
            break;
    }
}

void Heap::print() {

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

//void Heap::removeValue(int val) {
//
//}
//
//void Heap::removePos(int pos) {
//
//}

