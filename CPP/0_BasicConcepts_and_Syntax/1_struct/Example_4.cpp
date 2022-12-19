// STL
#include <fstream>
// TPL
#define FMT_HEADER_ONLY
#include <fmt/format.h>

struct ListNode
{
    int val;
    ListNode *next;                         // Self reference
    ListNode(int x) : val(x), next(NULL){}; // constructor of struct ListNode
};

int main(void)
{
    std::fstream file;

    // This uses the constructor of ListNode and
    // performs operations l1.val = 8; l1.next = NULL
    ListNode l1(8);

    // Making a Linked List of values
    ListNode *maker = &l1;

    for (int i = 0; i < 3; ++i)
    {
        ListNode *node = new ListNode(i);
        maker->next = node;
        maker = node;
    }

    file.open("Example_4.txt", std::ios::out);
    file << "Linked List Traversal:\n";
    // Traversing the linked list
    ListNode *traverser = &l1;
    for (int i = 0; i < 4; ++i)
    {
        // (*traverser).val returns the value stored in the address of l1
        file << fmt::format("Value at position {}: {}", i, (*traverser).val) << "\n";
        // Moving the traverser pointer to point to the next ListNode
        traverser = (*traverser).next;
    }

    file.close();
}