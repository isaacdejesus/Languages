#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

template <class data_type>
class binary_search_tree_node
{
    public:

        data_type info;
        binary_search_tree_node<data_type> *left_link;
        binary_search_tree_node<data_type> *right_link;
        binary_search_tree_node();
};
template <class data_type>
class binary_search_tree
{
    public: 
        const binary_search_tree<data_type>& operator=(const binary_search_tree<data_type>&);
        bool is_empty() const;
        void inorder_traversal() const;
        void preorder_traversal() const;
        void postorder_traveral() const;
        void iterative_preorder_traversal() const;
        //void iterative_postorder_traversal() const;
        void iterative_inorder_traversal() const;
        //void level_order_traversal() ;
        void insert(const data_type& item);  //bst function
        bool search(const data_type& item) const;  //bst function
        void delete_node(const data_type& item);   //bst function
        int tree_height() ;
        int tree_node_count() const;
        int tree_leaves_count() const;
        void destroy_tree();
        binary_search_tree_node<data_type> get_root();
        binary_search_tree(const binary_search_tree<data_type>& other_tree);
        binary_search_tree();
        ~binary_search_tree();
    protected:
        binary_search_tree_node<data_type> *root;
    private:
        void copy_tree(binary_search_tree_node<data_type>* &copied_tree_root, binary_search_tree_node<data_type>* other_tree_root);
        void destroy(binary_search_tree_node<data_type> *p) const;
        void inorder(binary_search_tree_node<data_type> *p) const;
        void preorder(binary_search_tree_node<data_type> *p) const;
        void postorder(binary_search_tree_node<data_type> *p) const;
        void iterative_preorder(binary_search_tree_node<data_type> *p) const;
        //void iterative_postorder(binary_search_tree_node<data_type> *p) const;
        void iterative_inorder(binary_search_tree_node<data_type> *p) const;
        //void level_order(binary_search_tree_node<data_type> *p) ;
        void delete_from_tree(binary_search_tree_node<data_type>* &p);
        int height(binary_search_tree_node<data_type> *p) ;
        int max(int x, int y);
        int node_count(binary_search_tree_node<data_type> *p) const;
        int leaves_count(binary_search_tree_node<data_type> *p) const;

};

#endif