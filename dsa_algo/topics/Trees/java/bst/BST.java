class BST {
    public class Node {
        private int value;
        private int height;
        private Node left;
        private Node right;
        public Node(int value)
        {
            this.value = value;
        }
        public int get_value()
        {
            return value;
        }
    }
    private Node root;
    public BST()
    {

    }
    public int height(Node node)
    {
        if(node == null)
            return -1;
        return node.height;
    }
    public boolean is_empty()
    {
        return root == null;
    }
    public void display()
    {
        display(root, "Root node: ");
    }
    private void display(Node node, String details)
    {
        if(node == null)
            return;
        System.out.println(details + node.get_value());
        display(node.left, "Left child of " + node.get_value() + " : ");
        display(node.right, "Right child of " + node.get_value() + " : ");
    }
    public void insert(int value)
    {
       root = insert(value, root);
    }
    private Node insert(int value, Node node)
    {
        if(node == null)  //if node is null create new node with value to be inserted and return
        {
            node = new Node(value);
            return node;
        }
        if(value < node.value)  //check left/right for correct insert loc/null child
            node.left = insert(value, node.left);  //if null, insert val here and set node.left to new node/val
        if(value > node.value)
            node.right = insert(value, node.right); //if null, insert val here and set node.right to new node/val
        node.height = Math.max(height(node.left), height(node.right)) + 1;
        return node;  //if not null, return current node
    }
    public boolean balanced()
    {
        return balanced(root);
    }
    private boolean balanced(Node node)
    {
        if(node == null)
            return true;
        return Math.abs(height(node.left) - height(node.right)) <= 1 && balanced(node.left) && balanced(node.right);
    }
    public void populate(int[] nums)
    {
        for(int i = 0; i < nums.length; i++)
        {
            this.insert(nums[i]);
        }
    }
    public void populate_sorted(int[] nums)
    {
        populate_sorted(nums, 0, nums.length);
    }
    private void populate_sorted(int[] nums, int start, int end)
    {
        if(start >= end)
            return;
        int mid = (start + end) /2;
        this.insert(nums[mid]);
        populate_sorted(nums, start, mid);
        populate_sorted(nums, mid + 1, end);
    }
    public void pre_order()
    {
        pre_order(root);
    }
    private void pre_order(Node node)
    {
        if(node == null)
            return;
        System.out.print(node.value + " ");
        pre_order(node.left);
        pre_order(node.right);
    }
    public void in_order()
    {
        in_order(root);
    }
    private void in_order(Node node)
    {
        if(node == null)
            return;
        in_order(node.left);
        System.out.print(node.value + " ");
        in_order(node.right);
    }
    public void post_order()
    {
        post_order(root);
    }
    private void post_order(Node node)
    {
        if(node == null)
            return;
        post_order(node.left);
        post_order(node.right);
        System.out.print(node.value + " ");
    }
}
