#include "Node.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

// the set of elements which are in either of the sets,
// but not in their intersection
Node *listSymmetricDifference(Node *first, Node *second)
{
    Node *out = NULL, *out_head = NULL;
    std::vector<int> first_list, second_list, union_set;

    // traverse the first linked list
    while (first != NULL)
    {
        first_list.push_back(first->data_);
        union_set.push_back(first->data_);
        first = first->next_;
    }

    // traverse the second linked list
    while (second != NULL)
    {
        second_list.push_back(second->data_);
        union_set.push_back(second->data_);
        second = second->next_;
    }

    // sort first, second, and the union lsit
    std::sort(first_list.begin(), first_list.end());
    std::sort(second_list.begin(), second_list.end());
    std::sort(union_set.begin(), union_set.end());

    // remove any duplicate elements
    first_list.erase(unique(first_list.begin(), first_list.end()), first_list.end());
    second_list.erase(unique(second_list.begin(), second_list.end()), second_list.end());
    union_set.erase(unique(union_set.begin(), union_set.end()), union_set.end());

    // setup a symmetric difference list
    std::vector<int> symdiff = union_set;
    for (auto const data : union_set)
    {
        if (std::binary_search(first_list.begin(), first_list.end(), data) &&
            std::binary_search(second_list.begin(), second_list.end(), data))
            symdiff.erase(std::remove(symdiff.begin(), symdiff.end(), data), symdiff.end());
    }

    // create node according to the symmetric difference list
    for (auto const data : symdiff)
    {
        if (out == NULL)
        {
            Node *new_node = new Node();
            new_node->data_ = data, new_node->next_ = NULL;
            out = new_node, out_head = out;
        }
        else if (out != NULL)
        {
            Node *new_node = new Node();
            new_node->data_ = data, new_node->next_ = NULL;
            out->next_ = new_node, out = out->next_;
        }
    }

    return out_head;
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
