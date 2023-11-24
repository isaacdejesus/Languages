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
    public TreeNode root;
    public void insert(int val)
    {
        root = insert(val, root);
    }
    public TreeNode insert(int val, TreeNode node)
    {
        if(node == null)
        {
            node = new TreeNode(val);
            return node;
        }
        if(val < node.val)
            node.left = insert(val, node.left);
        if(val > node.val)
            node.right = insert(val, node.right);
        return node;

    }
    public void insert_sorted(int[] nums, int start, int end)
    {
        if(start >= end)
            return;
        int mid = (start + end) /2;
        insert(nums[mid]);
        insert_sorted(nums, start, mid);
        insert_sorted(nums, mid + 1, end);
    }
    public TreeNode sortedArrayToBST(int[] nums) {
       insert_sorted(nums, 0, nums.length);
       return root;
    }
}
