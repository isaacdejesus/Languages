/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        TreeNode xx = find_node(root, x);
        TreeNode yy = find_node(root, y);
        return ((level(root, xx, 0) == level(root, yy, 0)) && (!is_sibling(root, xx, yy)));
    }
    TreeNode find_node(TreeNode node, int x) //dfs search/preorder traversal search
    {//looks for node with value x and returns said node
        if(node == null)
            return null;
        if(node.val == x)
            return node;
        TreeNode n = find_node(node.left, x); //seach left side
        if(n != null)  //if found on left side return
            return n;
        return find_node(node.right, x); //search right side
    }
    boolean is_sibling(TreeNode node, TreeNode x, TreeNode y)
    {
        if(node == null)
            return false;
        //check if x and y are children of current node
        //if not recurse checking left and right
        return ((node.left == x && node.right == y) || (node.left == y && node.right == x) ||
        is_sibling(node.left, x, y) || is_sibling(node.right, x, y));
    }
    int level(TreeNode node, TreeNode x, int lev)
    {
        if(node == null)
            return 0;
        if(node == x)
            return lev; 
        int l = level(node.left, x, lev+1);
        if(l != 0)
            return l;
        return level(node.right, x, lev+1);
    }

}
