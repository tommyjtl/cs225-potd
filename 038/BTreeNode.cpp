#include "BTreeNode.h"
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <cmath>

/**
 * Check if the given number of elements in a BTree node underflows.
 * @param numElem Number of elements in this node.
 * @param order The order of the BTree.
 * @return True if it underflows, False otherwise.
 */
bool underflows(unsigned numElem, unsigned order)
{
    // TODO: Your code here!

    // Recall that we require the root to have at least 1 value in it and
    // all other nodes to have at least (M-1)/2 values in them.
    if (numElem < ceil((order - 1) / 2))
        return true;

    return false;
}

/**
 * Fix the underflow child node at idx by rotating right
 * (borrowing a node from left sibling).
 * @param idx The underflow child to be fixed is at children_[idx].
 * @return If the rotation can be done.
 */
bool BTreeNode::rotateRight(unsigned idx, unsigned order)
{
    /**
     * First check if there is a left sibling.
     * If there is not, simply return false because rotateRight cannot be done.
     */
    if (idx <= 0)
        return false;

    /**
     * Then check if the left sibling leaf contains enough elements after one being borrowed.
     */
    BTreeNode *prev = children_[idx - 1];
    if (underflows(prev->elements_.size() - 1, order))
    {
        /**
         * If it's not enough, this case cannot be handled by rotateRight.
         * Simply return false.
         */
        return false;
    }
    /**
     * Do the right rotation by stealing one element from left sibling
     * and fixing the parent key.
     *
     * Example: Assume we are doing rotateRight around (40) to fix right child
     * (we are in BTreeNode(40), idx = 1 (the second child)),
     *                | 40 |
     *              /         \
     * | 10 | 20 | 30 |     | 60 |
     *
     * after rotation, the tree should look like
     *           | 30 |
     *         /        \
     * | 10 | 20 |    | 40 | 60 |
     *
     */

    /*
                    | 40 | 50 | 60 |
                  /        |         \
    | 10 | 20 | 30 |  | 42 | 48 |   | 65 | 70 |

                    | 40 | 50 | 60 |
                  /        |         \
    | 10 | 20 | 30 |  | 42 | 48 |   | 70 |

                    | 40 | 48 | 60 |
                  /        |         \
    | 10 | 20 | 30 |     | 42 |   | 70 |


    */

    // TODO: do the right rotation here

    // retrive the key from the back of left, then pop that key from the left
    int element_stoled_key = prev->elements_.back();
    prev->elements_.pop_back();

    // retrive the key from parent
    std::cout << "idx: " << idx << std::endl;
    unsigned int parent_idx = idx - 1;
    // unsigned int parent_idx = elements_.size() - 1;
    // unsigned int parent_idx = 0;
    int parent_key = elements_[parent_idx];

    elements_[parent_idx] = element_stoled_key;

    children_[idx]->elements_.insert(
        children_[idx]->elements_.begin(),
        parent_key);

    return true;
}

bool removeFromLeaf(int item, BTreeNode *parent, unsigned leaf_idx, unsigned order)
{
    // sanity checks
    assert(!parent->is_leaf_);
    assert(leaf_idx < parent->children_.size());
    BTreeNode *leaf = parent->children_[leaf_idx];
    assert(leaf->is_leaf_);
    std::vector<int> &elems = leaf->elements_;
    std::vector<int>::iterator pos = std::find(elems.begin(), elems.end(), item);
    assert(pos != elems.end());

    std::cout << "removing " << item << "..." << std::endl;

    // delete item, shift other items, shrink the size
    elems.erase(pos);

    std::cout << "Does the node underflow? ";

    // call rotateRight if current leaf node underflows
    if (underflows(elems.size(), order))
    {
        std::cout << "Yes!" << std::endl;
        return parent->rotateRight(leaf_idx, order - 1);
    }
    std::cout << "No!" << std::endl;
    return true;
}
