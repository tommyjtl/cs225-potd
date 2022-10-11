#include "Node.h"

#include <iostream>

using namespace std;

void sortList(Node **head)
{
    // your code here!
    if (*head != nullptr)
    {
        Node *current = *head;
        while (current->next_ != nullptr)
        {
            // brute force
            if (current->data_ > current->next_->data_)
            {
                std::cout << std::endl;
                Node *next = current->next_;

                std::cout << "current:\t" << current << " [" << current->data_ << "]" << std::endl;
                ;
                std::cout << "next:\t\t" << next << " [" << next->data_ << "]" << std::endl;
                ;
                current->next_ = next->next_;
                next->next_ = current;

                // making previous node's next_ points to exchanged current
                Node *start = *head;
                while (start != nullptr)
                {
                    if (start->next_ == current)
                    {
                        start->next_ = next;
                        break;
                    }
                    start = start->next_;
                }

                // if the previoud current is a head,
                // change the head for the corresponding linked list
                std::cout << "*head:\t\t" << *head << std::endl;
                ;
                if (current == *head)
                {
                    // changing head
                    *head = next;
                }

                // Set current to head_, start from beginning
                current = *head;
            }
            else
            {
                current = current->next_;
            }
        }
    }
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
