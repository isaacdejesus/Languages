/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int A_size = 0;
        int B_size = 0;
        while(l1 != nullptr)
        {
            A_size++;
            l1 = l1->next;            
        }
        while(l2 != nullptr)
        {
            B_size++;
            l2 = l2->next;            
        }
        l1 = headA;
        l2 = headB;
        if(A_size > B_size)
        {
            int dif = A_size - B_size;
            while(l1 != nullptr && dif > 0)
            {
                dif--;
                l1 = l1->next;
            }
            while(l1 != nullptr && l2 != nullptr)
            {
                if(l1 == l2)
                    return l1;
                //else they don't match, continue advancing    
                l1 = l1->next;
                l2 = l2->next;
            }
            return nullptr;
        }
        else if(A_size < B_size)
        {
            int dif = B_size - A_size;
            while(l2 != nullptr && dif > 0)
            {
                dif--;
                l2 = l2->next;
            }
            while(l1 != nullptr && l2 != nullptr)
            {
                if(l1 == l2)
                    return l1;
                //else they don't match, continue advancing    
                l1 = l1->next;
                l2 = l2->next;
            }
            return nullptr;

        }
        else //same size
        {
            while(l1 != nullptr && l2 != nullptr)
            {
                if(l1 == l2)
                    return l1;
                //else they don't match, continue advancing    
                l1 = l1->next;
                l2 = l2->next;
            }
            return nullptr;

        }
        return nullptr;
    }
};