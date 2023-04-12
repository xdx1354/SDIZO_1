//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H

class Node {
public:
    Node *right;
    Node *left;
    Node *parent;

    int value;
    Node(int);

};


#endif //PROJECT_NODE_H
