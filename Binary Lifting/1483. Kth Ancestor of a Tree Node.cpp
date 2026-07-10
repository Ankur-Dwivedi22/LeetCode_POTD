class TreeAncestor
{
public:
    int jumps;
    vector<vector<int>> up;
    TreeAncestor(int n, vector<int> &parent)
    {
        jumps = log2(n) + 1;
        up.resize(n, vector<int>(jumps, -1));

        for (int i = 0; i < n; i++)
        {
            up[i][0] = parent[i];
        }

        for (int j = 1; j < jumps; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (up[i][j - 1] != -1)
                {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int j = 0; j < jumps; j++)
        {
            if (k & (1 << j))
            {
                node = up[node][j];
                if (node == -1)
                    break;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */