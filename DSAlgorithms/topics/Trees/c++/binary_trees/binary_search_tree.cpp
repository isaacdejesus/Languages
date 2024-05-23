#include "binary_search_tree.h"
#include <iostream>
#include <stack>
#include <queue>

template <class data_type>
bool binary_search_tree<data_type>::is_empty() const 
{
    return root == nullptr;
}
template <class data_type>
int binary_search_tree<data_type>::tree_height() {
    return height(root);
}
template <class data_type>
int binary_search_tree<data_type>::height(binary_search_tree_node<data_type> *p) 
{
    if(p == nullptr)
        return 0;
    else return 1 + max(height(p->left_link), height(p->right_link));
}
template <class data_type>
void binary_search_tree<data_type>::inorder_traversal() const 
{
    inorder(root);
}
template <class data_type>
void binary_search_tree<data_type>::inorder(binary_search_tree_node<data_type> *p) const 
{
    if(p != nullptr)
    {
        inorder(p->left_link);
        std::cout<<p->info<<" ";
        inorder(p->right_link);
    }
}
template <class data_type>
void binary_search_tree<data_type>::preorder_traversal() const 
{
    preorder(root);
}
template <class data_type>
void binary_search_tree<data_type>::preorder(binary_search_tree_node<data_type> *p) const
{
    if(p != nullptr)
    {
        std::cout<<p->info<<" ";
        preorder(p->left_link);
        preorder(p->right_link);
    }
}
template <class data_type>
void binary_search_tree<data_type>::postorder_traveral() const 
{
    postorder(root);
}
template <class data_type>
void binary_search_tree<data_type>::postorder(binary_search_tree_node<data_type> *p) const{
    if(p != nullptr)
    {
        postorder(p->left_link);
        postorder(p->right_link);
        std::cout<< p->info << " ";
    }
}
template <class data_type>
void binary_search_tree<data_type>::iterative_preorder_traversal() const
{
    iterative_preorder(root);
}
template <class data_type>
void binary_search_tree<data_type>::iterative_preorder(binary_search_tree_node<data_type> *p) const 
{
    std::stack<binary_search_tree_node<data_type>> st;
    while( p != nullptr || !st.empty())
    {
       if(p != nullptr) 
        {
            std::cout<<p->info<<'\n';
            st.push(*p);
            p = p->left_link;
        }
        else
        {
            binary_search_tree_node<data_type> temp = st.top();
            st.pop();
            p = temp.right_link;
        }
    }
}
template <class data_type>
void binary_search_tree<data_type>::iterative_inorder_traversal() const
{
    iterative_inorder(root);
}
template <class data_type>
void binary_search_tree<data_type>::iterative_inorder(binary_search_tree_node<data_type> *p) const 
{
    std::stack<binary_search_tree_node<data_type>> st;
    while( p != nullptr || !st.empty())
    {
       if(p != nullptr) 
        {
            st.push(*p);
            p = p->left_link;
        }
        else
        {
            binary_search_tree_node<data_type> temp = st.top();
            st.pop();
            std::cout<<temp.info<<'\n';
            p = temp.right_link;
        }
    }
}
template <class data_type>
void binary_search_tree<data_type>::depth_first_traversal_iterative()
{
    dfs_iterative(root);
}
template <class data_type>
void binary_search_tree<data_type>::dfs_iterative(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return;
    std::stack<binary_search_tree_node<data_type>> a_stack;
    a_stack.push(*p);
    while(!a_stack.empty())
    {
        binary_search_tree_node<data_type> current = a_stack.top();
        a_stack.pop();
        std::cout<<current.info;
        if(current.right_link != nullptr)
            a_stack.push(*current.right_link);
        if(current.left_link != nullptr)
            a_stack.push(*current.left_link);
        
    }
}
template <class data_type>
void binary_search_tree<data_type>::depth_first_traversal_recursive()
{
    dfs_recursive(root);
}
template <class data_type>
void binary_search_tree<data_type>::dfs_recursive(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return;
    std::cout<<p->info;
    dfs_recursive(p->left_link);
    dfs_recursive(p->right_link);
}
template <class data_type>
void binary_search_tree<data_type>::breadth_first_search_iterative()
{
    bfs_iterative(root);
}
template <class data_type>
void binary_search_tree<data_type>::bfs_iterative(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return;
    std::queue<binary_search_tree_node<data_type>> q;
    q.push(*p);
    while(!q.empty())
    {
        binary_search_tree_node<data_type> current = q.front();
        q.pop();
        std::cout<<current.info;
        if(current.left_link != nullptr)
            q.push(*current.left_link);
        if(current.right_link != nullptr)
            q.push(*current.right_link);
    }
}
template <class data_type>
void binary_search_tree<data_type>::level_order_traversal()
{
    level_order(root);
}
template <class data_type>
void binary_search_tree<data_type>::level_order(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return;
    std::cout<<p->info;
    std::queue<binary_search_tree_node<data_type>> q;
    q.push(*p);
    while(!q.empty())
    {
        binary_search_tree_node<data_type> current = q.front();
        q.pop();
        if(current.left_link != nullptr)
        {
            std::cout<<current.left_link->info;
            q.push(*current.left_link);
        }
        if(current.right_link != nullptr)
        {
            std::cout<<current.right_link->info;
            q.push(*current.right_link);
        }
    }
}
template <class data_type>
bool binary_search_tree<data_type>::breadth_first_search_item_search(int target)
{
    bfs_item_search(root, target);
}
template <class data_type>
bool binary_search_tree<data_type>::bfs_item_search(binary_search_tree_node<data_type> *p, int target)
{
    if(p == nullptr)
        return false;
    std::queue<binary_search_tree_node<data_type>> q;
    q.push(*p);
    while(!q.empty())
    {
        binary_search_tree_node<data_type> current = q.front();
        q.pop();
        if(current.info == target)
            return true;
        if(current.left_link != nullptr)
            q.push(*current.left_link);
        if(current.right_link != nullptr)
            q.push(*current.right_link);
    }
    return false;
}
template <class data_type>
bool binary_search_tree<data_type>::depth_first_search_item_search(int target)
{
    dfs_item_search(root, target);
}
template <class data_type>
bool binary_search_tree<data_type>::dfs_item_search(binary_search_tree_node<data_type> *p, int target)
{
    if(p == nullptr)
        return false;
    if(p->info == target)
        return true;
    return dfs_item_search(p->left_link, target) || dfs_item_search(p->right_link, target);
}
template <class data_type>
int binary_search_tree<data_type>::depth_first_search_sum_of_nodes()
{
    dfs_sum_nodes(root);
}
template <class data_type>
int binary_search_tree<data_type>::dfs_sum_nodes(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return 0;
    return p->info + dfs_sum_nodes(p->left_link) + dfs_sum_nodes(p->right_link);
}
template <class data_type>
int binary_search_tree<data_type>::breath_first_search_sum_of_nodes()
{
    bfs_sum_nodes(root);
}
template <class data_type>
int binary_search_tree<data_type>::bfs_sum_nodes(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return 0;
    int sum = 0;
    std::queue<binary_search_tree_node<data_type>> q;
    q.push(*p);
    while(!q.empty())
    {
        binary_search_tree_node<data_type> current = q.front();
        q.pop();
        sum += current.info;
        if(current.left_link != nullptr)
            q.push(*current.left_link);
        if(current.right_link != nullptr)
            q.push(*current.right_link);
    }
    return sum;
}
template <class data_type>
int binary_search_tree<data_type>::breath_first_search_min_node()
{
    bfs_min_node(root);
}
template <class data_type>
int binary_search_tree<data_type>::bfs_min_node(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return 0;
    int long smallest = 9999999;
    std::queue<binary_search_tree_node<data_type>> q;
    q.push(*p);
    while(!q.empty())
    {
        binary_search_tree_node<data_type> current = q.front();
        q.pop();
        if(current.info < smallest)
            smallest = current.info;
        if(current.left_link != nullptr)
            q.push(*current.left_link);
        if(current.right_link != nullptr)
            q.push(*current.right_link);
    }
    return smallest;
}
template <class data_type>
int binary_search_tree<data_type>::depth_first_search_min_node()
{
    dfs_min_node(root);
}
template <class data_type>
int binary_search_tree<data_type>::dfs_min_node(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return 99999;
    int leftMin = dfs_min_node(p->left_link);
    int rightMin = dfs_min_node(p->right_link);
    return std::min(p->info, std::min(leftMin, rightMin));
}
template <class data_type>
int binary_search_tree<data_type>::depth_first_search_max_sum_from_root_to_leaf()
{
    dfs_max_sum_from_root_to_leaf(root);
}
template <class data_type>
int binary_search_tree<data_type>::dfs_max_sum_from_root_to_leaf(binary_search_tree_node<data_type> *p)
{
    if(p == nullptr)
        return -9999;
    if(p->left_link == nullptr && p->right_link == nullptr)
        return p->info;
    int max_child_sum = std::max(dfs_max_sum_from_root_to_leaf(p->left_link), dfs_max_sum_from_root_to_leaf(p->right_link));
    return p->info + max_child_sum;

}
template <class data_type>
void binary_search_tree<data_type>::insert(const data_type& item)
{
    binary_search_tree_node<data_type> *current;
    binary_search_tree_node<data_type> *trail_current;
    binary_search_tree_node<data_type> *new_node;

    new_node =  new binary_search_tree_node<data_type>;
    if(new_node != nullptr)
    new_node->info = item;
    new_node->left_link = nullptr;
    new_node->right_link = nullptr;
    if(root == nullptr)
        root = new_node;
    else{
        current = root;
        while(current != nullptr)
        {
            trail_current = current;
            if(current->info == item)
            {
                std::cout<<"item already in tree"   ;
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
bool binary_search_tree<data_type>::search(const data_type& item) const
{
    binary_search_tree_node<data_type>* current;
    bool found = false;
    if(root == nullptr)
        std::cout<<"Can't search an empty tree"<<'\n';
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
void binary_search_tree<data_type>::delete_from_tree(binary_search_tree_node<data_type>* &p)
{
    binary_search_tree_node<data_type> *current;
    binary_search_tree_node<data_type> *trail_current;
    binary_search_tree_node<data_type> *temp;
    if(p == nullptr)
        std::cout<< "node to be deleted is null"<<'\n';
    else if(p->left_link == nullptr && p->right_link == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if(p->left_link == nullptr)
    {
        temp = p;
        p = temp->right_link;
        delete temp;
    }
    else if(p->right_link == nullptr)
    {
        temp = p;
        p = temp->left_link;
        delete temp;
    }
    else
    {
        current = p->left_link;
        trail_current = nullptr;
        while(current->right_link != nullptr)
        {
            trail_current = current;
            current =  current->right_link;
        }
        p->info = current->info;
        if(trail_current == nullptr)
            p->left_link = current->left_link;
        else
            trail_current->right_link = current->left_link;
        delete current;
    }
}
template <class data_type>
void binary_search_tree<data_type>::delete_node(const data_type& item)
{
    binary_search_tree_node<data_type> *current;
    binary_search_tree_node<data_type> *trail_current;
    bool found = false;
    if(root == nullptr)
        std::cout<<"can't delete from empty tree"<<'\n';
    else
    {
       current = root;
       trail_current = root;
       while(current != nullptr && !found) 
       {
        if(current->info == item)
            found = true;
        else
        {
            trail_current = current;
            if(current->info > item)
                current - current->left_link;
            else
                current - current->right_link;
        }
       }
       if(current == nullptr)
        std::cout<<"item is not in tree"<<'\n';
        else if (found)
        {
            if(current == root)
                delete_from_tree(root);
            else if(trail_current->info > item)
                delete_from_tree(trail_current->left_link);
            else
                delete_from_tree(trail_current->right_link);
        }
    }
}
template <class data_type>
void binary_search_tree<data_type>::destroy(binary_search_tree_node<data_type>* p) const
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
void binary_search_tree<data_type>::destroy_tree()
{
    destroy(root);
}

template <class data_type>
int binary_search_tree<data_type>::tree_leaves_count() const
{
    return leaves_count(root);
}
template <class data_type>
int binary_search_tree<data_type>::leaves_count(binary_search_tree_node<data_type> *p) const
{
    if(p == nullptr)
        return 0;
    if(p->left_link == nullptr && p->right_link == nullptr)
        return 1;
    else
        return leaves_count(p->left_link) + leaves_count(p->right_link);
}

template <class data_type>
int binary_search_tree<data_type>::tree_node_count() const{
    return node_count(root);
}

template <class data_type>
int binary_search_tree<data_type>::node_count(binary_search_tree_node<data_type>* p) const
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
const binary_search_tree<data_type>& binary_search_tree<data_type>::operator=(const binary_search_tree<data_type>& other_tree)
{
    if(this != &other_tree)
    {
        destroy(root);
        if(other_tree.root == nullptr)
            root = nullptr;
        else 
            copy_tree(root, other_tree.root);
    }
    return *this;
}

template <class data_type>
int binary_search_tree<data_type>::max(int x, int y) 
{
    if( x > y )
        return x;
    else 
        return y;
}
template <class data_type>
binary_search_tree_node<data_type>::binary_search_tree_node()
{
    left_link = nullptr;
    right_link = nullptr;
}

template <class data_type>
binary_search_tree<data_type>::binary_search_tree()
{
    root = nullptr;
}
template <class data_type>
binary_search_tree<data_type>::~binary_search_tree()
{
    destroy(root);
}

template <class data_type>
binary_search_tree<data_type>::binary_search_tree(const binary_search_tree<data_type>& other_tree)
{
    if(other_tree.root == nullptr)
        root = nullptr;
    else
        copy_tree(root, other_tree.root);
}
template <class data_type>
void binary_search_tree<data_type>::copy_tree(binary_search_tree_node<data_type>* &copied_tree_root, binary_search_tree_node<data_type>* other_tree_root)
{
    if(other_tree_root == nullptr)
        copied_tree_root = nullptr;
    else{
        copied_tree_root = new binary_search_tree_node<data_type>;
        copied_tree_root->info = other_tree_root->info;
        copy_tree(copied_tree_root->left_link, other_tree_root->left_link);
        copy_tree(copied_tree_root->right_link, other_tree_root->right_link);
    }
}

template class binary_search_tree <int>;
template class binary_search_tree_node <int>;
