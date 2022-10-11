#ifndef POTD_H
#define POTD_H

#include <string>

using namespace std;

struct Node
{
    int data_;
    Node *next_;
    ~Node(){
        // delete this;
    };
};

string stringList(Node *n);

#endif
