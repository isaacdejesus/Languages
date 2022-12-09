#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template<class data_type>
class node  
{
    public: 
        data_type info;
        node<data_type> *link;
        node();
};
template<class data_type>
class linked_list
{
    public: 
        linked_list();
        bool isEmpty() const;
        void destroyList();
        //bool search(const data_type& item);
        void insert_first(const data_type& item);
        int get_length();
        //void insert_last(const data_type& item);
        void display();
        //void delete_item(const data_type& item);
    protected:
        int count;
        node<data_type> *head;
        node<data_type> *tail;
};
#endif