struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    while(current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current; 
        current = next;
    }
    return prev;
}

ListNode* reverseListRecursive(ListNode* head)
{
    if(head == nullptr)
        return nullptr;
    ListNode* newHead = head;
    if(head->next)
    {
        newHead = reverseListRecursive(head->next);
        head->next->next = head;
    }
    head->next = nullptr;
    return newHead;
}
