//
// Created by stani on 05.04.2023.
//


#include "ListNode.h"
#include <iostream>

using namespace std;


ListNode::ListNode(int value, ListNode *prev, ListNode *next) {
    ListNode::value = value;
    ListNode::next = next;
    ListNode::prev = prev;
}
