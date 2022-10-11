#include "Node.h"

#include <iostream>

/** Create a new node and add it to the list, while keeping the list sorted.
 */
Node *insertSorted(Node *first, int data)
{
    // previous solution

    if (first == NULL)
    {
        Node *new_node = new Node();
        new_node->data_ = data;
        new_node->next_ = NULL;
        return new_node;
    }

    Node *current = first;
    Node *tail = first;
    while (current != NULL)
    {
        if (data == current->data_)
        {
            return first;
        }
        if (current->next_ != NULL)
        {
            tail = current->next_;
        }
        current = current->next_;
    }

    Node *new_node = new Node();
    new_node->data_ = data;
    new_node->next_ = NULL;

    tail->next_ = new_node;
    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
    that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second)
{
    // previous solution
    Node *out = NULL;

    while (first != NULL)
    {
        // std::cout << "[first]\t\t" << first << " : " << first->data_ << std::endl;
        out = insertSorted(out, first->data_);
        first = first->next_;
    }

    while (second != NULL)
    {
        // std::cout << "[second]\t" << second << " : " << second->data_ << std::endl;
        out = insertSorted(out, second->data_);
        second = second->next_;
    }
    return out;
}

Node::Node()
{
    numNodes++;
}

Node::Node(const Node &other)
{
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node()
{
    numNodes--;
}

int Node::numNodes = 0;
