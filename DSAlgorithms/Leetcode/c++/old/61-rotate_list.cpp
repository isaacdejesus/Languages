 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k <= 0 || head == nullptr || head->next == nullptr)    
            return head;
        ListNode* last = head;
        int length = 1;
        while(last->next != nullptr)
        {
            last = last->next;
            length++;
        }
        last->next = head;
        int rotations = k % length;
        int skip = length - rotations;
        ListNode* new_last = head;
        for(int i = 0; i < skip -1; i++)
            new_last = new_last->next;
        head = new_last->next;
        new_last->next = nullptr;
        return head;
    }
};