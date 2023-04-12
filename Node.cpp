//
// Created by stani on 05.04.2023.
//

#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int val){
    value = val;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
};