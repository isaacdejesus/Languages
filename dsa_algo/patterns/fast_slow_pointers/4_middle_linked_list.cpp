#include<bits/stdc++.h>
class list_node {
    public:
        int value = 0;
        list_node *next;
        list_node(int value)
        {
            this->value = value;
            next = nullptr;
        }
};

class middle_linked_list {
    public:
        static list_node *find_mid(list_node *head)
        {
            list_node *slow = head;
            list_node *fast = head;
            while(fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};
int main(int argc, char *argv[])
{
    list_node *head = new list_node(1);
    head->next = new list_node(2);
    head->next->next = new list_node(3);
    head->next->next->next = new list_node(4);
    head->next->next->next->next = new list_node(5);
    std::cout<<"middle node: "<<middle_linked_list::find_mid(head)->value<<'\n';

    head->next->next->next->next->next = new list_node(6);
    std::cout<<"middle node: "<<middle_linked_list::find_mid(head)->value<<'\n';

    head->next->next->next->next->next->next = new list_node(7);
    std::cout<<"middle node: "<<middle_linked_list::find_mid(head)->value<<'\n';
}
