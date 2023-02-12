 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
       ListNode* mid = middle_node(head);
       ListNode* head_second = reverse_list(mid);
       ListNode* re_reverse_head = head_second;
       //compare
       while(head != nullptr && head_second != nullptr)
       {
           if(head->val != head_second->val)
                break;
            head = head->next;
            head_second = head_second->next;
       }
       reverse_list(re_reverse_head);
       return head == nullptr || head_second == nullptr;
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