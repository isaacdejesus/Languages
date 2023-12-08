/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //preorder traverse nodes and insert to vector
    void dfs1(TreeNode* root, std::vector<std::string>& res)
    {
        if(root == nullptr)
        {
            res.push_back("N");
            return;
        }
        res.push_back(std::to_string(root->val));
        dfs1(root->left, res);
        dfs1(root->right, res);
    }
    // Encodes a tree to a single string.
    //takes preorder vector and turns into string with , as delimiter
    string serialize(TreeNode* root) {
       std::vector<std::string> result; 
       dfs1(root,  result);
       std::string res = "";
       for(auto item: result)
           res += item + ",";
        return res;
    }

    //takes values from back of arr and creates tree in preorder
    //returns node
    TreeNode* dfs2(std::vector<std::string>& data) 
    {
        std::string current = data.back();
        data.pop_back();
        if(current == "N")
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(current));
        node->left = dfs2(data);
        node->right = dfs2(data);
        return node;
    }
    // Decodes your encoded data to tree.
    //takes string, turns into vector and reverses it
    TreeNode* deserialize(string data) {
        std::vector<std::string> vec;
        while(data != "")
        {
           int delimiter = data.find(',');
           std::string current = data.substr(0, delimiter);
           vec.push_back(current);
           data = data.substr(delimiter + 1);
        }
        std::reverse(vec.begin(), vec.end());
       return dfs2(vec);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));