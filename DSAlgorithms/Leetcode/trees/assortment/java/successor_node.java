/*
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
    public TreeNode find_successor(TreeNode root, int key)
    {
        if(root == null)
            return null;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty())
        {
            TreeNode current_node = queue.poll();
            if(current_node.left != null)
                queue.offer(current_node.left);
            if(current_node.right != null)
                queue.offer(current_node.right);
            if(current_node.val = key)
                break;
        }
        return queue.peek(); 
        
    }
}
