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

class palindromic_list{
    public:
        static bool is_palindrome(list_node *head)
        {
            if(head == nullptr || head->next == nullptr)
                return true;
            list_node *slow = head;
            list_node *fast = head;
            while(fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            list_node *head_second_half = reverse(slow);
            list_node *cp_head_second_half = head_second_half;
            while(head != nullptr && head_second_half != nullptr)
            {
                if(head->value != head_second_half->value)
                    break;
                head = head->next;
                head_second_half = head_second_half->next;
            }
            reverse(cp_head_second_half);
            if(head == nullptr || head_second_half == nullptr)
                return true;
            return false;
        }
    private:
        static list_node *reverse(list_node *head)
        {
            list_node *prev = nullptr;
            while(head != nullptr)
            {
                list_node *next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            return prev;
        }
};

int main(int argc, char *argv[])
{
    list_node *head = new list_node(2);
    head->next = new list_node(4);
    head->next->next = new list_node(6);
    head->next->next->next = new list_node(4);
    head->next->next->next->next = new list_node(2);
    std::cout<<"is pal: " <<palindromic_list::is_palindrome(head)<<'\n';
    head->next->next->next->next->next = new list_node(2);
    std::cout<<"is pal: " <<palindromic_list::is_palindrome(head)<<'\n';
}
