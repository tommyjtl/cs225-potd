#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->address == address)
        {
            current->inUse = false;
            Node *prev = current->previous;
            Node *next = current->next;

            if (prev != NULL && !prev->inUse)
            {
                size_t prev_address = prev->address;
                if (prev->previous != NULL)
                {
                    prev->previous->next = current;
                    current->previous = prev->previous;
                }
                else
                {
                    current->previous = NULL;
                    std::cout << "setting new head" << std::endl;
                    head = current;
                }
                current->address = prev_address;
                delete prev;
            }

            if (next != NULL && !next->inUse)
            {
                if (next->next != NULL)
                {
                    next->next->previous = current;
                    current->next = next->next;
                    delete next;
                }
                else
                {
                    current->next = NULL;
                    delete next;
                }
            }

            return true;
        }
        current = current->next;
    }

    return false;
}

/**
Reorganizes memory structure
so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
chunk of free memory above.

Note: We do not care about the order of the allocated memory chunks
*/
void Memory::defragment()
{
    Node *current = head;

    while (current != NULL)
    {
        std::cout << "traversing: " << current << std::endl;
        if (current->inUse)
        {
            // if current is in use, do nothing
        }
        else
        {
            Node *prev = current->previous;
            Node *next_allocated = findNextAllocatedMemoryChunk(current);

            std::cout << "current: " << current
                      << ", next_allocated: " << next_allocated << std::endl;

            free(current->address);

            if (next_allocated != NULL)
            {
                Node *next_allocated_next = next_allocated->next;

                size_t next_allocated_size = getSize(next_allocated);
                size_t current_address = current->address;

                next_allocated->address = current_address;
                current->address = current_address + next_allocated_size;

                next_allocated->previous = prev;
                if (prev != NULL)
                {
                    prev->next = next_allocated;
                }
                else if (prev == NULL)
                {
                    head = next_allocated;
                }

                current->previous = next_allocated;
                next_allocated->next = current;

                current->next = next_allocated_next;
                if (next_allocated_next != NULL)
                {
                    next_allocated_next->previous = current;
                }

                // head_unused = current;

                // std::cout << "current: " << current << std::endl;
                std::cout << "current relationship: " << std::setfill('0') << std::setw(9) << current->previous
                          << "<-" << current << "->"
                          << std::setfill('0') << std::setw(9) << current->next << '\n';

                current = next_allocated;
            }
            else if (next_allocated == NULL)
            {
                // head_unused = current;
                break;
            }
        }

        current = current->next;
    }
}
