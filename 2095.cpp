
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
    ListNode* deleteMiddle(ListNode* head)
    {
        int count{2};
        std::vector<int> vec{head->val};
        ListNode* curr_ls = head->next;
        if (!curr_ls) return nullptr;
        if (!curr_ls->next)
        {
            head->next = nullptr;
            return head;
        }
        while (curr_ls->next != nullptr)
        {
            count++;
            vec.push_back(curr_ls->val);
            curr_ls = curr_ls->next;
        }

        vec.push_back(curr_ls->val);

        ListNode* ln = new ListNode(vec[count - 1]);
        for (int i{count - 2}; i >= 0; --i)
        {
            if (i != static_cast<int>(std::ceil(count / 2)))
            {
                ListNode* ls = new ListNode(vec[i], ln);
                ln           = ls;
            }
        }
        return ln;
    }
};

int main()
{
    // ListNode* ln = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(7, new
    // ListNode(1, new ListNode(2, new ListNode(6)))))));
    ListNode* ln = new ListNode(1);
    Solution sol;
    auto out = sol.deleteMiddle(ln);

    while (out->next != nullptr)
    {
        std::cout << out->val << std::endl;
        out = out->next;
    }
}