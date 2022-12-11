#include "binary_tree.h"


template <class data_type>
bool binary_tree<data_type>::is_empty() const 
{
    return root == nullptr;
}
template <class data_type>
int binary_tree<data_type>::tree_height() const{
    return height(root);
}
template <class data_type>
int binary_tree<data_type>::height(binary_tree_node<data_type> *p) const
{
    if(p == nullptr)
        return 0;
    else return 1 + max(height(p->left_link), height(p->right_link));
}
template <class data_type>
void binary_tree<data_type>::inorder_traversal() const 
{
    inorder(root);
}
template <class data_type>
void binary_tree<data_type>::inorder(binary_tree_node<data_type> *p) const 
{
    if(p != nullptr)
    {
        inorder(p->left_link);
        std::cout<<p->info<<" ";
        inorder(p->right_link);
    }
}
template <class data_type>
void binary_tree<data_type>::preorder_traversal() const 
{
    preorder(root);
}
template <class data_type>
void binary_tree<data_type>::preorder(binary_tree_node<data_type> *p) const
{
    if(p != null)
    {
        std::cout<<p->info<<" ";
        preorder(p->left_link);
        preorder(p->right_link);
    }
}
template <class data_type>
void binary_tree<data_type>::postorder_traveral() const 
{
    postorder(root);
}
template <class data_type>
void binary_tree<data_type>::postorder(binary_tree_node<data_type> *p) const{
    if(p != null)
    {
        postorder(p->left_link);
        postorder(p->right_link);
        std::cout<< p->info << " ";
    }
}
template <class data_type>
void binary_tree<data_type>::insert(const data_type& item)
{
    binary_tree_node<data_type> *current;
    binary_tree_node<data_type> *trail_current;
    binary_tree_node<data_type> *new_node;

    new_node =  new binary_tree_node<data_type>;
    if(new_node != nullptr)
    {
        new_node->info = item;
        new_node->left_link = nullptr;
        new_node->right_link = nullptr;
    }
    if(root == nullptr)
        root = new_node;
    else{
        current = root;
        while(current != nullptr)
        {
            trail_current = current;
            if(current->info == item)
            {
                cerr<<"item already in tree"   ;
                return;
            }
            else if(current->info > item)
                current = current->left_link;
            else
                current = current->right_link;
        }
        if(trail_current->info > item)
            trail_current->left_link =  new_node;
        else
            trail_current->right_link =  new_node;
    }
}
template <class data_type>
bool binary_tree<data_type>::search(const data_type& item) const
{
    binary_tree<data_type>* current;
    bool found = false;
    if(root == nullptr)
        cerr<<"Can't search an empty tree"<<'\n';
    else{
        current = root;
        while(current != nullptr  && !found)
        {
            if(current->info == item)
                found = true;
            else if(current->info > item)
                current = current->left_link;
            else 
                current = current->right_link;
        }
    }
    return found;
}
template <class data_type>
void binary_tree<data_type>::destroy(binary_tree_node<data_type>* p) const
{
    if(p != nullptr)
    {
        destroy(p->left_link);
        destroy(p->right_link);
        delete p;
        p = nullptr;
    }
}
template <class data_type>
void binary_tree<data_type>::destroy_tree()
{
    destroy(root);
}

template <class data_type>
int binary_tree<data_type>::tree_leaves_count() const
{
    return leaves_count(root);
}
template <class data_type>
int binary_tree<data_type>::leaves_count(binary_tree_node<data_type> *p) const
{
    if(p == nullptr)
        return 0;
    if(p->left == nullptr && p->right == nullptr)
        return 1;
    else
        return leaves_count(p->left_link) + leaves_count(p->right_link);
}

template <class data_type>
int binary_tree<data_type>::tree_node_count() const{
    return node_count(root);
}

template <class data_type>
int binary_tree<data_type>::node_count(binary_tree_node<data_type>* p) const
{
    int count = 0;
    if(p == nullptr)
        return 0;
    if(p->left_link != nullptr)
    {
        count++;
        count+= node_count(p->left_link);
    }
    if(p->right_link != nullptr)
    {
        count++;
        count+= node_count(p->right_link);
    }
    return count;
}

template <class data_type>
const binary_tree<data_type>& binary_tree<data_type>::operator=(const binary_tree<data_type>& other_tree)
{
    if(this != &other_tree)
    {
        destroy(root);
        if(other_tree.root == nullptr)
            root = nullptr;
        else 
            copy_tree(root, other_tree.root)
    }
    return *this;
}

template <class data_type>
int binary_tree<data_type>::max(int x, int y) 
{
    if( x > y )
        return x;
    else 
        return y;
}
template <class data_type>
binary_tree_node<data_type>::binary_tree_node()
{
    left_link = nullptr;
    right_link = nullptr;
}

template <class data_type>
binary_tree<data_type>::binary_tree()
{
    root = nullptr;
}
template <class data_type>
binary_tree<data_type>::~binary_tree()
{
    destroy(root);
}

template <class data_type>
binary_tree<data_type>::binary_tree(const binary_tree<data_type>& other_tree)
{
    if(other_tree.root == null)
        root = null;
    else
        copy_tree(root, other_tree.root);
}
template <class data_type>
void binary_tree<data_type>::copy_tree(binary_tree_node<data_type>* &copied_tree_root, binary_tree_node<data_type>* other_tree_root)
{
    if(other_tree_root == nullptr)
        copied_tree_root = nullptr;
    else{
        copied_tree_root = new binary_tree_node<data_type>
        copied_tree_root->info = other_tree_root->info;
        copy_tree(copied_tree_root->left_link, other_tree_root->left_link);
        copy_tree(copied_tree_root->right_link, other_tree_root->right_link);
    }
}