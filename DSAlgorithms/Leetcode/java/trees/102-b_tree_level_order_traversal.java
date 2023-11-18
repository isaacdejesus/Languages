import java.util.Queue;
import java.util.List;

class Main{
    public static void main(String[] args)
    {
    }
    public List<List<Integer>> leverOrder(TreeNode root)
    {
        List<List<Integer>> result = new ArrayList<>();
        if(root == null)
            return result;
        Queue<TreeNode> queue = new LinkedList<>();
        Queue.offer(root);
        while(!queue.isEmpty())
        {
            int level_size = queue.size();
            List<Integer> current_level = new ArrayList<>(level_size);
            for(int i = 0; i < level_size; i++)
            {
                TreeNode current_node = queue.poll();
                current_level.add(current_node.val);
                if(current_node.left != null)
                    queue.offer(current_node.left);
                if(current_node.right != null)
                    queue.offer(current_node.right);
            }
            result.add(current_level);
        }

        return result;
    }
}
