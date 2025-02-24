/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
       ListNode*  slow = head;
       ListNode*  fast = head;
       ListNode*  prev = nullptr;
       while(fast != nullptr && fast->next != nullptr)
       {
           fast = fast->next->next;
           ListNode* temp = slow->next;
           slow->next = prev;
           prev = slow;
           slow = temp;
       }
       int result = 0;
       while(slow != nullptr)
       {
           result = std::max(result, prev->val + slow->val);
           prev = prev->next;
           slow = slow->next;
       }
       return result;
    }
};