#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template<class data_type>
class node  
{
    public: 
        data_type info;
        node<data_type> *next;
        node<data_type> *prev;
        node();
};
template<class data_type>
class linked_list
{
    public: 
        linked_list();
        bool isEmpty() const;
        //void destroyList();
        node<data_type>* search(const data_type& item);
        void insert_first(const data_type& item);
        int get_length();
        void insert_last(const data_type& item);
        //void insert_at_index(const data_type& item, int index);
        //node<data_type>* insert_rec(int index, const data_type& item, node<data_type>* next);
        void display();
        void display_reverse();
        //node<data_type>* get_node(int index);
        //void delete_item(const data_type& item);
        node<data_type>* delete_head();
        node<data_type>* delete_tail();
        //node<data_type>* delete_node(node<data_type>* item);
        void delete_node(node<data_type>* item);
        //node<data_type>* delete_at_index(int index);
        //void remove_duplicates();
    protected:
        int size;
        node<data_type> *head;
        node<data_type> *tail;
};
#endif
