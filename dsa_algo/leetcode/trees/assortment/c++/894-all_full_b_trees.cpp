/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::unordered_map<int, std::vector<TreeNode*>> hash;
    vector<TreeNode*> allPossibleFBT(int n) {
        std::vector<TreeNode*> ans;
        if(n % 2 == 0)
            return {};
        if(n == 1)
            return {new TreeNode(0)};
        if(hash.find(n) != hash.end())
            return hash[n];
        for(int i = 1; i < n; i++)
        {
            std::vector<TreeNode*> left = allPossibleFBT(i);
            std::vector<TreeNode*> right = allPossibleFBT(n - i - 1);
            for(TreeNode* l: left)
            {
                for(TreeNode* r: right)
                {
                    ans.push_back(new TreeNode(0, l, r));
                }
            }
        }
        return hash[n] = ans;
    }
};
