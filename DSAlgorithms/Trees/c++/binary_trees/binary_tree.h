#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <class data_type>
class binary_tree_node
{
    data_type info;
    binary_tree_node<data_type> *left_link;
    binary_tree_node<data_type> *right_link;
    binary_tree_node();
};
template <class data_type>
class binary_tree
{
    public: 
        const binary_tree<data_type>& operator=(const binary_tree<data_type>&);
        bool is_empty() const;
        void inorder_traversal() const;
        void preorder_traversal() const;
        void postorder_traveral() const;
        void insert(const data_type& item);
        bool search(const data_type& item) const;
        int tree_height() const;
        int tree_node_count() const;
        int tree_leaves_count() const;
        void destroy_tree();
        binary_tree_node<data_type> get_root();
        binary_tree(const binary_tree<data_type>& other_tree);
        binary_tree();
        ~binary_tree();
    protected:
        binary_tree_node<data_type> *root;
    private:
        void copy_tree(binary_tree_node<data_type>* &copied_tree_root, binary_tree_node<data_type>* other_tree_root);
        void destroy(binary_tree_node<data_type> *p) const;
        void inorder(binary_tree_node<data_type> *p) const;
        void preorder(binary_tree_node<data_type> *p) const;
        void postorder(binary_tree_node<data_type> *p) const;
        int height(binary_tree_node<data_type> *p) const;
        int max(int x, int y);
        int node_count(binary_tree_node<data_type> *p) const;
        int leaves_count(binary_tree_node<data_type> *p) const;

};

#endif 