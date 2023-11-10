import org.w3c.dom.Node;

class segment_tree{
    public static void main(String[] args)
    {
        int[] arr = {3, 8, 6, 7, -2, -8, 4, 9};
        segment_tree tree = new segment_tree(arr);
    }
    private static class Node{
        int data;
        int start_interval;
        int end_interval;
        Node left;
        Node right;
        public Node(int start, int end)
        {
            this.start_interval = start;
            this.end_interval = end;
        }
    }
    Node root;
    public segment_tree(int[] arr)
    {
        this.root = construct_tree(arr, 0, arr.length - 1);
    }
    private Node construct_tree(int[] arr, int start, int end)
    {
        if(start == end) //leaf
        {
            Node leaf = new Node(start, end);
            leaf.data = arr[start];
            return leaf;
        }
        //create node with current index
        Node node = new Node(start, end);
        int mid = (start + end) /2;
        node.left = this.construct_tree(arr, start, mid);
        node.right = this.construct_tree(arr, mid + 1, end);
        node.data = node.left.data + node.right.data;
        return node;
    }
    public void display()
    {
        display(this.root);
    }
    private void display(Node node)
    {
        String str = "";
        if(node.left != null)
            str = str + "Interval=[" + node.left.start_interval + "-" + node.left.end_interval + "] and data: " + node.left.data + " => ";
        else
            str = str + "No left child";
        str = str + "Interval=[" + node.start_interval + "-" + node.end_interval + "] and data: " + node.data + " <= ";
        if(node.right != null)
            str = str + "Interval=[" + node.right.start_interval + "-" + node.right.end_interval + "] and data: " + node.right.data;
        else
            str = str + "No right child";
        System.out.println(str + '\n');
        if(node.left != null)
            display(node.left);
        if(node.right != null)
            display(node.right);
    }
    public int query(int query_start, int query_end)
    {
        return this.query(this.root, query_start, query_end);
    }
    private int query(Node node, int query_start, int query_end)
    {
        if(node.start_interval >= query_start && node.end_interval <= query_end)
        {//node vals/interval is within query interval
            return node.data;
        }
        else if(node.start_interval > query_end || node.end_interval < query_start)
        {//node vals/interval is outside
            return 0;
        }
        else
        {
            return this.query(node.left, query_start, query_end) + this.query(node.right, query_start, query_end);
        }
    }
    public void update(int index, int value)
    {
        this.root.data = update(this.root, index, value);
    }
    private int update(Node node, int index, int value)
    {
        if(index >= node.start_interval && index <= node.end_interval)
        {
            if(index == node.start_interval && index == node.end_interval)
            {
                node.data = value;
                return node.data;
            }
            else
            {
                int left_ans = update(node.left, index, value);
                int right_ans = update(node.right, index, value);
                node.data = left_ans + right_ans;
                return node.data;
            }
        }
        return node.data;
    }

}
