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
    ListNode* sortList(ListNode* head) {
       if(head == nullptr || head->next == nullptr) 
            return head;
        ListNode* mid = get_mid(head); //leftsorts from head to mid. right sorts from mid + 1 to end
        ListNode* left = sortList(head); //stops at mid -1 bc get_mid set mid -1 node to null
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* new_list = new ListNode();
        ListNode* current = new_list;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        current->next = (list1 != nullptr) ? list1 : list2;
        return new_list->next;
    }
    ListNode* get_mid(ListNode* head)
    {
        ListNode* mid_prev = nullptr;
        while(head != nullptr && head->next != nullptr)
        {
            mid_prev = (mid_prev == nullptr) ? head : mid_prev->next;
            head = head->next->next;
        }
        ListNode* mid = mid_prev->next;
        mid_prev->next = nullptr;// note get mid sets mid -1 node to null. Splits list in half at mid
        return mid;
    }
};