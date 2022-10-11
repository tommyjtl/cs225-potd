#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert)
{
    Node *current = *head;
    if (current == NULL ||
        current->data_ >= insert->data_)
    {
        insert->next_ = *head;
        *head = insert;
        return;
    }
    while (current->next_ != nullptr &&
           current->next_->data_ < insert->data_)
    {
        cout << "traversing: " << current << endl;
        current = current->next_;
    }
    insert->next_ = current->next_;
    current->next_ = insert;
}