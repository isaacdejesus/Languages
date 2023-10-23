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
    size = 0;
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
    size = 0;
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
        size++;
    }
    else //new_node points to head and head now points to new_link
    {
       new_node->link = current;
       head = new_node;
       size++;
    }
}
template <class data_type>
void linked_list<data_type>::insert_last(const data_type& item)
{
    node<data_type> *new_node = new node<data_type>;
    new_node->info = item;
    new_node->link =  nullptr;

    if(isEmpty())
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->link = new_node;
        tail = new_node;
    }
    size++;
}
template <class data_type>
void linked_list<data_type>::insert_at_index(const data_type& item, int index)
{
    if(index > size)
        return;
    if(index == 0)
    {
        insert_first(item);
        return;
    }
    if(index == size)
    {
        insert_last(item);
        return;
    }
    node<data_type> *temp = head;
    for(int i = 1; i < index; i++)
    {
        temp = temp->link;
    }
    node<data_type> *new_node = new node<data_type>;
    new_node->info = item;
    new_node->link = temp->link;
    temp->link = new_node;
    size++;
}
template <class data_type>
node<data_type>* linked_list<data_type>::insert_rec(int index, const data_type& item, node<data_type>* next)
{
    if(index == 0) //base case. Reached insertion loc. Return newnode
    {
        node<data_type> *temp = new node<data_type>;
        temp->link = nullptr;
        temp->info = item;
        size++;
        return temp;
    }
        next->link = insert_rec(index--, item, next->link);
        return next;
}
template <class data_type>
node<data_type>* linked_list<data_type>::delete_head()
{
    node<data_type> *temp;
    head =  head->link; 
    if(head == nullptr)
        tail = nullptr;
    size--;
    return temp;
}
template <class data_type>
node<data_type>* linked_list<data_type>::get_node(int index)
{
    node<data_type>* temp = head;
    for(int i = 0; i < index ; i++)
        temp = temp->link;
    return temp;
}
template <class data_type>
node<data_type>* linked_list<data_type>::delete_tail()
{
   if(size <=1) 
       return delete_head();
   node<data_type>* secondLast = get_node(size - 2);
   node<data_type>* temp  = tail;
   tail = secondLast;
   tail->link = nullptr;
   return temp;
}
template <class data_type>
node<data_type>* linked_list<data_type>::delete_at_index(int index)
{
    if(index == 0)
        return delete_head();
    if(index == size - 1)
        return delete_tail();
    node<data_type>* prev = get_node(index - 1);
    node<data_type>* temp = prev->link;
    prev->link = prev->link->link;
    return temp;
}
template <class data_type>
void linked_list<data_type>::remove_duplicates()
{
    node<data_type> *temp = head;
    while(temp->link != nullptr)
    {
        if(temp->info == temp->link->info)
        {
            temp->link = temp->link->link;
            size--;
        }
        else 
            temp = temp->link;
    }
    tail = temp;
    tail->link = nullptr;
}
template <class data_type>
node<data_type>* linked_list<data_type>::search(const data_type& item)
{
    node<data_type>* temp = head;
    while(temp != nullptr)
    {
        if(temp->info == item)
            return temp;
        temp = temp ->link;
    }
    return nullptr;
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
    std::cout<<'\n';
}
template <class data_type>
int linked_list<data_type>::get_length()
{
    return size;
}

template class node <int>;
template class linked_list <int>;
