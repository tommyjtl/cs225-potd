#pragma once

#include <cstddef>

class Queue
{
public:
    Queue();
    ~Queue();

    int size() const;
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(int value);
    int dequeue();

private:
    int *array_;
    int capacity_;
    int front_;
    int back_;
    int count_;
};