#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "BTreeNode.h"

int main()
{
    std::vector<int> v1{30, 60};

    std::vector<int> v2{10, 20};
    std::vector<int> v2a{5, 6};
    std::vector<int> v2b{13, 15};

    std::vector<int> v3{40, 50};
    std::vector<int> v3a{34, 38};

    std::vector<int> v4{70, 80};
    BTreeNode n_0(v1), n_2(v2), n_3(v3), n_4(v4),
        n_2a(v2a), n_2b(v2b),
        n_3a(v3a);

    n_0.children_.push_back(&n_2);
    n_0.children_.push_back(&n_3);
    n_0.children_.push_back(&n_4);

    n_2.children_.push_back(&n_2a);
    n_2.children_.push_back(&n_2b);
    n_3.children_.push_back(&n_3a);

    n_0.is_leaf_ = false;
    n_2.is_leaf_ = false;
    n_3.is_leaf_ = false;

    std::vector<int> tr = traverse(&n_0);
    for (std::vector<int>::const_iterator i = tr.begin(); i != tr.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl;

    return 0;
}
