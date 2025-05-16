class avl {
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
    public avl()
    {

    }
    public int height()
    {
        return height(root);
    }
    private int height(Node node)
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
        return rotate(node);  //will rotate/balance starting from node-> root and return root
        //rotate will attempt to balance nodes above newly inserted node
        //Note: it will check every node above newly inserted to check if balanced and only rotate
        //upon finding a node that is not balanced.
        //after balancing, it will continue to check nodes up to root and return root.
        //If all nodes are balanced. rotate won't do anything
    }
    private Node rotate(Node node)
    {
        if(height(node.left) - height(node.right) > 1)        
        {
            //means node is left heavy or unbalances bc left height is larger than right side
            if(height(node.left.left) - height(node.left.right) > 0)
            {
                //left left case
                return right_rotate(node);
            }
            if(height(node.left.left) - height(node.left.right) < 0)
            {
                //left right case
                node.left = left_rotate(node.left);
                return right_rotate(node);
            }
        }
        if(height(node.left) - height(node.right) < -1)        
        {
            //means node is right heavy or unbalances bc right height is larger than left side
            if(height(node.right.left) - height(node.right.right) < 0)
            {
                //right right case
                return left_rotate(node);
            }
            if(height(node.right.left) - height(node.right.right) > 0)
            {
                // right left case
                node.right = right_rotate(node.right);
                return left_rotate(node);
            }
        }
        return node;
    }
    public Node right_rotate(Node p)
    {
        Node c = p.left;
        Node t = c.right;
        c.right = p;
        p.left = t;
        p.height = Math.max(height(p.left), height(p.right)) +1;
        c.height = Math.max(height(c.left), height(c.right)) +1;
        return c;
    }
    public Node left_rotate(Node c)
    {
        Node p = c.right;
        Node t = p.left;
        p.left = c;
        c.right = t;
        c.height = Math.max(height(c.left), height(c.right)) +1;
        p.height = Math.max(height(p.left), height(p.right)) +1;
        return p;
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
