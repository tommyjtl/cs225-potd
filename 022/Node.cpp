#include "Node.h"
#include <iostream>

using namespace std;

Node *listIntersection(Node *first, Node *second)
{
    // your code here
    Node *out = NULL, *out_head = NULL;
    Node *second_head = second;

    while (first != NULL)
    {
        while (second != NULL)
        {
            //   std::cout << second->data_ << " : " << first->data_ << std::endl;
            if (second->data_ == first->data_)
            {
                Node *new_node = new Node();
                new_node->data_ = second->data_;
                new_node->next_ = NULL;

                if (out == NULL)
                {
                    out = new_node;
                    out_head = out;
                }
                else
                {
                    bool is_duplicate = false;

                    Node *traverse = out_head;
                    while (traverse != NULL)
                    {
                        if (traverse->data_ == new_node->data_)
                        {
                            is_duplicate = true;
                            break;
                        }
                        traverse = traverse->next_;
                    }

                    if (is_duplicate == false)
                        out->next_ = new_node;
                }
            }
            second = second->next_;
        }
        second = second_head;
        first = first->next_;
    }

    return out;
}

Node::Node()
{
    numNodes++;
}

Node::Node(Node &other)
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
