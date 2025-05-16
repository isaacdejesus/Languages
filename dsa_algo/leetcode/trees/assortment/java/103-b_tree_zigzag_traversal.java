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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null)
            return result;
        Deque<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        boolean reverse = false;
        while(!queue.isEmpty())
        {
    
            int level_size = queue.size();
            List<Integer> current_level = new ArrayList<>(level_size);
            for(int i = 0; i < level_size; i++)
            {
                if(!reverse)
                {
                    TreeNode current_node = queue.pollFirst();
                    current_level.add(current_node.val);
                    if(current_node.left != null)
                        queue.addLast(current_node.left);
                    if(current_node.right != null)
                        queue.addLast(current_node.right);
                }
                else
                {
                    TreeNode current_node = queue.pollLast();
                    current_level.add(current_node.val);
                    if(current_node.right != null)
                        queue.addFirst(current_node.right);
                    if(current_node.left != null)
                        queue.addFirst(current_node.left);

                }
            }
            reverse = !reverse;
            result.add(current_level);
        }

        return result; 
    }
}
