// STL
#include <iostream>
#include <fstream>
// TPL
#include <fmt/format.h>

struct ListNode
{
    int val;
    ListNode *next;                         // Pointer to another struct ListNode
    ListNode(int x) : val(x), next(NULL){}; // constructor of struct ListNode
};

int main(void)
{
    std::fstream file;
    ListNode l1(8);

    // Making a Linked List of values
    ListNode *maker = &l1;

    for (int i = 0; i < 3; ++i)
    {
        ListNode *node = new ListNode(i);
        maker->next = node;
        maker = node;
    }

    file.open("LinkedListTraversal.txt", std::ios::out);

    // Traversing the linked list
    ListNode *traverser = &l1;
    for (int i = 0; i < 4; ++i)
    {
        // (*traverser).val returns the value stored in the address of l1
        file << fmt::format("Value at position {}: {}", i, (*traverser).val) << "\n";
        // Moving the traverser pointer to point to the next ListNode
        traverser = (*traverser).next;
    }
}