#include <iostream>
#include "Node.h"

// #include <algorithm>
// #include <vector>

using namespace std;

void printList(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        cout << "Node " << count << ": " << temp->data_ << endl;
        count++;
        temp = temp->next_;
    }
}

int main()
{
    // Example #1
    Node n_0, n_1, n_2, n_22, n_3, n_4;
    n_0.data_ = 0;
    n_1.data_ = 1;
    n_2.data_ = 2;
    n_22.data_ = 1;
    n_3.data_ = 2;
    n_4.data_ = 3;

    n_0.next_ = &n_1;
    n_1.next_ = &n_2;
    n_2.next_ = NULL;

    n_22.next_ = &n_3;
    n_3.next_ = &n_4;
    n_4.next_ = NULL;

    cout << "First List:" << endl;
    printList(&n_0);
    cout << n_0.getNumNodes() << endl;
    cout << "Second List:" << endl;
    printList(&n_22);
    cout << n_22.getNumNodes() << endl;

    Node *r1 = listSymmetricDifference(&n_0, &n_22);
    cout << "Symmetric Difference" << endl;
    printList(r1);
    cout << r1->getNumNodes() << endl;
    cout << endl;

    // Example #2
    Node p00, p01, p02, p03, p10, p11, p12, p13, p14, p15, p16;

    // List 1: 0 2 2 2
    p00.data_ = 0;
    p00.next_ = &p01;
    p01.data_ = 2;
    p01.next_ = &p02;
    p02.data_ = 2;
    p02.next_ = &p03;
    p03.data_ = 2;
    p03.next_ = NULL;

    // List 2: 0 0 0 4
    p10.data_ = 0;
    p10.next_ = &p11;
    p11.data_ = 0;
    p11.next_ = &p12;
    p12.data_ = 0;
    p12.next_ = &p13;
    p13.data_ = 2;
    p13.next_ = &p14;
    p14.data_ = 2;
    p14.next_ = &p15;
    p15.data_ = 2;
    p15.next_ = &p16;
    p16.data_ = 4;
    p16.next_ = NULL;

    cout << "First List:" << endl;
    printList(&p00);
    cout << "Second List:" << endl;
    printList(&p10);

    Node *r2 = listSymmetricDifference(&p00, &p10);
    cout << "Symmetric Difference" << endl;
    printList(r2);
    cout << r2->getNumNodes() << endl;
    cout << endl;

    // Example: same lists
    Node n10, n11, n12, n13, n20, n21, n22, n23;

    n10.data_ = 2, n10.next_ = &n11;
    n11.data_ = 3, n11.next_ = &n12;
    n12.data_ = 4, n12.next_ = &n13;
    n13.data_ = 5, n13.next_ = NULL;

    n20.data_ = 2, n20.next_ = &n21;
    n21.data_ = 3, n21.next_ = &n22;
    n22.data_ = 4, n22.next_ = &n23;
    n23.data_ = 5, n23.next_ = NULL;

    cout << "List 1:" << endl;
    printList(&n10);
    cout << "List 2:" << endl;
    printList(&n20);

    Node *r3 = listSymmetricDifference(&n10, &n20);
    cout << "Symmetric Difference" << endl;
    printList(r3);
    cout << r3->getNumNodes() << endl;
    cout << endl;

    // Example 4
    Node n30, n31, n32, n33, n34, n35, n36, n37, n38, n39;
    Node n40, n41, n42, n43, n44, n45, n46, n47, n48, n49;

    n30.data_ = 0;
    n30.next_ = &n31;
    n31.data_ = 2;
    n31.next_ = &n32;
    n32.data_ = 2;
    n32.next_ = &n33;
    n33.data_ = 2;
    n33.next_ = &n34;
    n34.data_ = 8;
    n34.next_ = &n35;
    n35.data_ = 5;
    n35.next_ = &n36;
    n36.data_ = 6;
    n36.next_ = &n37;
    n37.data_ = 7;
    n37.next_ = &n38;
    n38.data_ = 8;
    n38.next_ = &n39;
    n39.data_ = 9;
    n39.next_ = NULL;

    n40.data_ = 10;
    n40.next_ = &n41;
    n41.data_ = 4;
    n41.next_ = &n42;
    n42.data_ = 2;
    n42.next_ = &n43;
    n43.data_ = 5;
    n43.next_ = &n44;
    n44.data_ = 4;
    n44.next_ = &n45;
    n45.data_ = 5;
    n45.next_ = &n46;
    n46.data_ = 7;
    n46.next_ = &n47;
    n47.data_ = 5;
    n47.next_ = &n48;
    n48.data_ = 9;
    n48.next_ = &n49;
    n49.data_ = 0;
    n49.next_ = NULL;

    cout << "List 1:" << endl;
    printList(&n30);
    cout << "List 2:" << endl;
    printList(&n40);

    Node *r4 = listSymmetricDifference(&n30, &n40);
    cout << "Symmetric Difference" << endl;
    printList(r4);
    cout << r4->getNumNodes() << endl;
    cout << endl;

    //

    // cout << "+--------------------------+" << endl;
    // cout << "| set_symmetric_difference |" << endl;
    // cout << "+--------------------------+" << endl;

    // std::vector<int> v1{0, 2, 2, 2, 8, 5, 6, 7, 8, 9};
    // std::vector<int> v2{10, 4, 2, 5, 4, 5, 7, 5, 9, 0};
    // std::sort(v1.begin(), v1.end());
    // std::sort(v2.begin(), v2.end());

    // std::vector<int> v_symDifference;

    // std::set_symmetric_difference(
    //     v1.begin(), v1.end(),
    //     v2.begin(), v2.end(),
    //     std::inserter(v_symDifference, v_symDifference.end()));

    // for(int n : v_symDifference)
    //     std::cout << n << ' ';

    return 0;
}
