// STL
#include <iostream>
#include <fstream>
// TPL
#define FMT_HEADER_ONLY
#include <fmt/format.h>

struct ListNode
{
    int val;
    ListNode *next;                         // Pointer to another struct ListNode
    ListNode(int x) : val(x), next(NULL){}; // constructor of struct ListNode
};
