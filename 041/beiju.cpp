#include <list>

string beiju(string input)
{
    string read, output;
    list<char> processed;
    list<char>::iterator it;

    for (char c : input)
    {
        output.clear();
        read.push_back(c);
        processed.clear();
        it = processed.begin();

        for (size_t i = 0; i < read.size(); ++i)
        {
            if (read[i] == '[')
                it = processed.begin();
            if (read[i] == ']')
                it = processed.end();
            if (read[i] != '[' && read[i] != ']')
                processed.insert(it, read[i]);
        }

        for (it = processed.begin(); it != processed.end(); it++)
            output.push_back(*it);
    }

    return output;
}