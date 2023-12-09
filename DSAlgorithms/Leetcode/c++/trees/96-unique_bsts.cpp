class Solution {
public:
    int numTrees(int n) {
        std::vector<int> num_of_trees(n + 1, 1); //fill vector with 1s of size n + 1
        for(int nodes = 2; nodes < n + 1; nodes++)
        {
            int total = 0;
            for(int root = 1; root < nodes + 1; root++)
            {
                int left = root - 1;
                int right = nodes - root;
                total += num_of_trees[left] * num_of_trees[right];
            }
            num_of_trees[nodes] = total;
        }
        return num_of_trees[n];
    }
};
