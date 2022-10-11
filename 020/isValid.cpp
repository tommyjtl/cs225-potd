#include <string>
#include <stack>

#include <iostream>
using namespace std;

bool isValid(string input)
{
    stack<char> all;

    for (size_t idx = 0; idx < input.size(); ++idx)
    {
        if (input[idx] == '(')
        {
            all.push(')');
        }
        else if (input[idx] == '{')
        {
            all.push('}');
        }
        else if (input[idx] == '[')
        {
            all.push(']');
        }

        if (input[idx] == ')')
        {
            if (!all.empty())
            {
                if (all.top() != ')')
                    // checking unmatched
                    return false;
                all.pop();
            }
            else
            {
                // checking extra
                return false;
            }
        }
        else if (input[idx] == '}')
        {
            if (!all.empty())
            {
                if (all.top() != '}')
                    // checking unmatched
                    return false;
                all.pop();
            }
            else
            {
                // checking extra
                return false;
            }
        }
        else if (input[idx] == ']')
        {
            if (!all.empty())
            {
                if (all.top() != ']')
                    // checking unmatched
                    return false;
                all.pop();
            }
            else
            {
                // checking extra
                return false;
            }
        }
    }

    // checking hanging
    if (!all.empty())
        return false;

    return true;
}