#include "Queue.h"

Queue::Queue()
{
    array_ = new int[1000];
    capacity_ = 1000;
    front_ = 0;
    back_ = -1;
    count_ = 0;
}

Queue::~Queue()
{
    delete[] array_;
}

// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const
{
    return count_;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const
{
    return size() == 0;
}

bool Queue::isFull() const
{
    return size() == capacity_;
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value)
{
    if (isFull())
        return;

    back_ = (back_ + 1) % capacity_;
    array_[back_] = value;
    count_++;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue()
{
    if (isEmpty())
        return -1;

    int x = array_[front_];
    front_ = (front_ + 1) % capacity_;
    count_--;

    return x;
}
