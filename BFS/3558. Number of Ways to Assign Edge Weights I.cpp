class Solution
{
public:
    const int M = 1e9 + 7;
    using ll = long long;
    ll power(ll b, ll e)
    {
        ll res = 1;
        b = (b % M);
        while (e > 0)
        {
            if (e % 2 == 1)
                res = (res * b) % M;
            b = (b * b) % M;
            e /= 2;
        }

        return res;
    }

    int height(int node, int parent, vector<vector<int>> &adj)
    {
        int mx = -1;
        for (int adjNode : adj[node])
        {
            if (adjNode != parent)
            {
                mx = max(mx, height(adjNode, node, adj));
            }
        }

        return mx + 1;
    }

    int assignEdgeWeights(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto it : edges)
        {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int h = height(1, -1, adj);
        // cout<<h<<endl;
        int ans = power(2, h - 1);
        return ans;
    }
};