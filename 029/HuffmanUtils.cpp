#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using std::string;

bool debug = true;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode *huffmanTree)
{
    /* TODO: Your code here */
    if (debug)
        std::cout << "binaryToString" << std::endl;

    std::queue<char> my_queue;
    std::string out;

    if (debug)
        std::cout << "my_queue: ";
    for (const char &c : binaryString)
    {
        my_queue.push(c);
        if (debug)
            std::cout << c;
    }
    my_queue.push(0);
    if (debug)
        std::cout << std::endl;

    HuffmanNode *root = huffmanTree;

    while (!my_queue.empty())
    {
        if (root->left_ == NULL && root->right_ == NULL)
        {
            if (debug)
                std::cout << "\t" << root->char_ << std::endl;
            out = out + root->char_;
            root = huffmanTree;
        }

        char front = my_queue.front();
        if (debug)
            std::cout << front;
        my_queue.pop();

        if (front == '0')
        {
            if (root->left_ != NULL)
            {
                root = root->left_;
            }
        }
        else if (front == '1')
        {
            if (root->right_ != NULL)
            {
                root = root->right_;
            }
        }
    }
    if (debug)
        std::cout << std::endl;

    return out;
}

bool hasPath(HuffmanNode *root, std::vector<char> &arr, char x, int lr)
{
    if (!root)
        return false;

    if (lr == 0)
        arr.push_back('0');
    else if (lr == 1)
        arr.push_back('1');

    if (root->char_ == x)
        return true;

    if (hasPath(root->left_, arr, x, 0) ||
        hasPath(root->right_, arr, x, 1))
        return true;

    arr.pop_back();
    return false;
}

string getPath(HuffmanNode *root, char x)
{
    // vector to store the path
    std::vector<char> arr;
    std::string out = "";

    // if required node 'x' is present
    // then print the path
    if (hasPath(root, arr, x, 2))
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            // cout << arr[i] << "->";
            out = out + arr[i];
        }
        // cout << arr[arr.size() - 1];
        out = out + arr[arr.size() - 1];
    }
    return out;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode *huffmanTree)
{
    /* TODO: Your code here */
    if (debug)
        std::cout << "stringToBinary" << std::endl;

    std::queue<char> my_queue;
    std::string out;

    if (debug)
        std::cout << "my_queue: ";
    for (const char &c : charString)
    {
        my_queue.push(c);
        if (debug)
            std::cout << "[" << c << "]";
    }
    if (debug)
        std::cout << std::endl;

    HuffmanNode *root = huffmanTree;

    while (!my_queue.empty())
    {
        char front = my_queue.front();
        my_queue.pop();

        out = out + getPath(root, front);
        root = huffmanTree;
    }

    return out;
}