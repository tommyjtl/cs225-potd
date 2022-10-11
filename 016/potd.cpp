#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head)
{
    string output = "";
    int idx = 0;
    while (head != nullptr)
    {
        // cout << "traverse!" << endl;
        output = output + "Node " + to_string(idx) + ": " + to_string(head->data_);
        if (head->next_ != nullptr)
        {
            output = output + " -> ";
        }
        head = head->next_;
        idx++;
    }
    if (output == "")
        return "Empty list";

    return output;
}
