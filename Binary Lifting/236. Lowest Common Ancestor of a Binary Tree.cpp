/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int jumps = 20;
    unordered_map<TreeNode *, vector<TreeNode *>> up;
    unordered_map<TreeNode *, int> depth;

    void binaryLift(TreeNode *node, TreeNode *parent, int d)
    {
        if (!node)
            return;

        depth[node] = d;
        up[node] = vector<TreeNode *>(jumps, nullptr);
        up[node][0] = parent;

        for (int j = 1; j < jumps; j++)
        {
            if (up[node][j - 1] != nullptr)
            {
                up[node][j] = up[up[node][j - 1]][j - 1];
            }
        }

        binaryLift(node->left, node, d + 1);
        binaryLift(node->right, node, d + 1);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        binaryLift(root, nullptr, 0);

        if (depth[p] < depth[q])
        {
            swap(p, q);
        }

        int k = depth[p] - depth[q];
        for (int j = 0; j < jumps; j++)
        {
            if (k & (1 << j))
            {
                p = up[p][j];
            }
        }

        if (p == q)
            return p;
        for (int j = jumps - 1; j >= 0; j--)
        {
            if (up[p][j] != nullptr && up[p][j] != up[q][j])
            {
                p = up[p][j];
                q = up[q][j];
            }
        }

        return up[p][0];
    }
};