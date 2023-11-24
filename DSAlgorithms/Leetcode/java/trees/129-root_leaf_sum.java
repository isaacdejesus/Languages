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
    public int sumNumbers(TreeNode root) {
        return helper(root, 0);
    }
    int helper(TreeNode node, int sum)
    {
        if(node == null)
            return 0;
        sum = sum * 10 + node.val;
        if(node.left == null && node.right == null)
            return sum;  //if leaf return root -> left sum
        //else check left/right passing this node's sum'
        //also sum this node's left and right sums
        return helper(node.left, sum) + helper(node.right, sum);
    }
}
