int count_paths(Node node, int sum)
{
    List<Integer> path = new LinkedList<>();
    return helper(node, sum, path);
}
int helper(Node node, int sum, List<Integer> path)
{
    if(node == null)
        return 0;
    path.add(node.val);
    int count = 0;
    int s = 0;
    ListIterator<Integer> itr = path.ListIterator(path.size());
    while(itr.hasPrevious())
    {
        s += itr.previous();
        if(s == sum)
            count++;
    }
    count += helper(node.left, sum, path) + helper(node.right, sum, path);
    //backtrack
    path.remove(path.size(0 -1));
    return count;
}
