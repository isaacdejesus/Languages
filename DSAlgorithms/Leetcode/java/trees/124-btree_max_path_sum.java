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
    int ans = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
       helper(root);
       return ans;
    }
    int helper(TreeNode node)
    {
        if(node == null)
            return 0;
        int left = helper(node.left);
        int right = helper(node.right);
        left = Math.max(0, left);  //set to 0 if neg
        right = Math.max(0, right);  //set to 0 if neg
        int current_path_sum  = left + right + node.val;
        ans = Math.max(ans, current_path_sum);
        return Math.max(left, right) + node.val;
    }
}
