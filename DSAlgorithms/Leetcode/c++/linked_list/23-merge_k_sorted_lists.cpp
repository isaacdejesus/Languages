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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size(); 
        if(n == 0)
            return nullptr;
        while(n > 1)
        {
            for(int i = 0; i < n / 2; i++)
            {
                lists[i] = merge_two_lists(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }
        return lists[0];
    }
    ListNode* merge_two_lists(ListNode* list1, ListNode* list2)
    {
        ListNode* new_list = new ListNode();
        ListNode* current = new_list;
        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                current->next = list2;
                list2 = list2->next;
            }
            else
            {
                current->next = list1;
                list1 = list1->next;
            }
            current = current->next;
        }
        if(list1)
            current->next = list1;
        else 
            current->next = list2;
        return new_list->next;
    }
};