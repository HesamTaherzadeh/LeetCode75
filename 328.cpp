
#include <cmath>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
   public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode* odd       = head;
        ListNode* even      = head->next;
        ListNode* firstEven = head->next;

        while (even && even->next)
        {
            odd->next  = odd->next->next;
            odd        = odd->next;
            even->next = even->next->next;
            even       = even->next;
        }

        odd->next = firstEven;
        return head;
    }
};

int main()
{
    ListNode* ln =
        new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(7, new ListNode(8)))));
    Solution sol;
    auto out = sol.oddEvenList(ln);

    while (out->next != nullptr)
    {
        std::cout << out->val << std::endl;
        out = out->next;
    }
}