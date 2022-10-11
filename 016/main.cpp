#include "potd.h"
#include <iostream>
using namespace std;

int main()
{
    // Test 1: An empty list
    Node *head = NULL;
    cout << stringList(head) << endl;

    // Test 2: A list with exactly one node
    head = new Node();
    head->data_ = 100;

    Node *second = new Node();
    second->data_ = 200;
    head->next_ = second;

    cout << stringList(head) << endl;

    // delete head, second;

    // Test 3: A list with more than one node

    return 0;
}
