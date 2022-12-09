#include <iostream>
#include "linked_list.h"

template <class data_type>
node<data_type>::node()
{
    link = nullptr;
}
template <class data_type>
bool linked_list<data_type>::isEmpty() const
{
    return (head == nullptr);
}

template <class data_type>
linked_list<data_type>::linked_list()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class data_type>
void linked_list<data_type>::destroyList()
{
    node<data_type> *temp;
    while(head != nullptr)
    {
        temp = head;
        head = head -> link;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}

template <class data_type>
void linked_list<data_type>::insert_first(const data_type& item)
{
    node<data_type> *current = head;
    node<data_type> *new_node = new node<data_type>;
    new_node->info = item;
    new_node->link = nullptr;
    //list is empty. both head and tail point to new_node
    if(isEmpty())
    {
        head = new_node;
        tail = new_node;
        count++;
    }
    else //new_node points to head and head now points to new_link
    {
       new_node->link = current;
       head = new_node;
       count++;
    }
}
template <class data_type>
void linked_list<data_type>::display()
{
    node<data_type> *current = head;
    while(current != nullptr)
    {
        std::cout<<current->info<<'\n';
        current = current->link;
    }
    std::cout<<"tail is:"<<tail->info;
    std::cout<<'\n';
}
template <class data_type>
int linked_list<data_type>::get_length()
{
    return count;
}

template class node <int>;
template class linked_list <int>;