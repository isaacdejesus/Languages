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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* dummy = new ListNode();
       dummy->next = head;
       ListNode* prev = dummy;
       ListNode* current = dummy->next;
       ListNode* temp = nullptr;
       int count = k;
       while(current != nullptr)
       {
           if(count > 1)
           {
               temp = prev->next;
               prev->next = current->next;
               current->next = current->next->next;
               prev->next->next = temp;
               count--;
           }
           else
           {
               prev = current;
               current = current->next;
               count = k;
               ListNode* end = current;
               for(int i = 0; i < k; i++)
               {
                   if(end == nullptr)
                        return dummy->next;
                    end = end->next;
               }
           }
       }
       return dummy->next;
    }
};