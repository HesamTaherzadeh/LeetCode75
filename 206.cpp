
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; 
            curr->next = prev;                
            prev = curr;                      
            curr = nextNode;                 
        }
        return prev; 
    }
};

int main()
{
    ListNode* ln =
        new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(7, new ListNode(8)))));
    Solution sol;
    auto out = sol.reverseList(ln);

    while (out->next != nullptr)
    {
        std::cout << out->val << std::endl;
        out = out->next;
    }
}