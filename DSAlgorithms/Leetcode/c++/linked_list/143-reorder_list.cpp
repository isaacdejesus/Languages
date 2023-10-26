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
    void reorderList(ListNode* head) {
       if(head == nullptr || head->next == nullptr) 
            return;
        ListNode* mid = middle_node(head);
        ListNode* hs = reverse_list(mid);
        ListNode* hf = head;
        while(hf != nullptr && hs != nullptr)
        {
            ListNode* temp = hf->next;
            hf->next = hs;
            hf = temp;

            temp = hs->next;
            hs->next = hf;
            hs = temp;
        }
        if(hf != nullptr)
            hf->next = nullptr;
    }
    ListNode* reverse_list(ListNode * head)
    {
        if(head == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = current->next;
        while(current != nullptr)
        {
            current->next = prev;
            prev = current;
            current = next;
            if(next != nullptr)
                next = next->next;
        }
        return prev;
    }
    ListNode* middle_node(ListNode* head)
    {
        ListNode* s = head;
        ListNode* f = head;
        while(f != nullptr && f->next != nullptr)
        {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};