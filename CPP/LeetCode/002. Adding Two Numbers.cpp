// Should be commented out when submitting
// Leetcode automatically adds these lines of code during submission
// -------------------------------------------

#define NULL 0

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// ------------------------------------------

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *cur = &head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            ListNode *node = new ListNode((x + y + carry) % 10);
            cur->next = node;
            cur = node;

            carry = (x + y + carry) / 10;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return head.next;
    }
};

// Runtime
// 24 ms
// Beats
// 98.87%
// Memory
// 71.4 MB
// Beats
// 82.36%