List<List<Integer>> find_paths(Node node, int sum)
{
    List<List<Integer>> paths = new ArrayList<>();
    List<Integer> path = new ArrayList<>();
    helper(node, sum, path, paths);
    return paths;
}
void helper(Node node, int sum, List<Integer> path, List<List<Integer>> paths)
{
    if(node == null)
        return 0;
    if(node.val == sum && node.left == null && node.right == null)
        paths.add(new ArrayList<>(path));
    else 
    {
        helper(node.left, sum-node.val, path, paths);
        helper(node.right, sum-node.val, path, paths);
    }
    //backtrack
    path.remove(path.size() - 1);
}
