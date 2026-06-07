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
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        map<int, TreeNode *> nodes;
        unordered_set<int> children;
        TreeNode *root = nullptr;

        for (auto it : descriptions)
        {
            int val = it[0], child_val = it[1], is_left = it[2];
            if (nodes.find(val) == nodes.end())
            {
                nodes[val] = new TreeNode(val);
            }

            if (nodes.find(child_val) == nodes.end())
            {
                nodes[child_val] = new TreeNode(child_val);
            }

            if (is_left)
            {
                nodes[val]->left = nodes[child_val];
            }
            else
            {
                nodes[val]->right = nodes[child_val];
            }

            children.insert(child_val);
        }

        for (auto it : nodes)
        {
            int val = it.first;
            if (children.find(val) == children.end())
            {
                root = it.second;
                break;
            }
        }

        return root;
    }
};