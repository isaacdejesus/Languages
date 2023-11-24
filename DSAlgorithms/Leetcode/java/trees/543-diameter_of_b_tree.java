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
    int diameter = 0;
    public int diameterOfBinaryTree(TreeNode root) {
       height(root);
       return diameter - 1;
    }
    int height(TreeNode node)
    {
        if(node == null)
            return 0;
        int left_height = height(node.left); 
        int right_height = height(node.right);
        int current_diameter = left_height + right_height + 1;
        diameter = Math.max(current_diameter, diameter);
        return Math.max(left_height, right_height) + 1;
    }
}
