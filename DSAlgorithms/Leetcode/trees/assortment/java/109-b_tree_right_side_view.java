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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if(root == null)
            return result;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while(!queue.isEmpty())
        {
            int level_size = queue.size();
            for(int i = 0; i < level_size; i++)
            {
                TreeNode current_node = queue.poll();
                if(i == level_size - 1)
                    result.add(current_node.val);
                if(current_node.left != null)
                    queue.offer(current_node.left);
                if(current_node.right != null)
                    queue.offer(current_node.right);
            }
        }
        return result;
    }
}
