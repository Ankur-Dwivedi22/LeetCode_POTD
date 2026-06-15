// Approach : Binary lifting
// TC : O((N + Q) * logN)
// SC : O(N * logN + Q)
class Solution
{
public:
    using ll = long long;
    const int M = 1e9 + 7;

    ll power(ll b, ll e)
    {
        if (e == -1)
            return 0ll;
        ll ans = 1;
        b = b % M;
        while (e > 0)
        {
            if (e % 2 == 1)
            {
                ans = (ans * b) % M;
            }
            b = (b * b) % M;
            e /= 2;
        }

        return ans;
    }

    void dfs(ll node, ll par, ll d, vector<vector<ll>> &adj, vector<ll> &parent, vector<ll> &depth)
    {
        parent[node] = par;
        depth[node] = d;
        for (ll adjNode : adj[node])
        {
            if (adjNode != par)
            {
                dfs(adjNode, node, d + 1, adj, parent, depth);
            }
        }
    }

    vector<vector<ll>> binaryLifting(ll n, vector<ll> &parent)
    {
        ll jumps = log2(n) + 1;
        vector<vector<ll>> up(n + 1, vector<ll>(jumps, -1));
        for (ll i = 1; i <= n; i++)
        {
            up[i][0] = parent[i];
        }

        for (ll j = 1; j < jumps; j++)
        {
            for (ll node = 1; node <= n; node++)
            {
                if (up[node][j - 1] != -1)
                {
                    up[node][j] = up[up[node][j - 1]][j - 1];
                }
            }
        }

        return up;
    }

    ll findLCA(ll u, ll v, ll n, vector<ll> &depth, vector<vector<ll>> &up)
    {
        ll jumps = log2(n) + 1;
        ll depth_u = depth[u];
        ll depth_v = depth[v];

        if (depth_u != depth_v)
        {
            ll k = abs(depth_u - depth_v);
            if (depth_u < depth_v)
            {
                swap(u, v);
            }

            for (int j = 0; j < jumps; j++)
            {
                if (k & (1 << j))
                {
                    u = up[u][j];
                }
            }
        }

        if (u == v)
            return u;

        for (ll j = jumps - 1; j >= 0; j--)
        {
            if (up[u][j] != up[v][j])
            {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        ll n = edges.size() + 1;
        vector<vector<ll>> adj(n + 1);

        for (auto it : edges)
        {
            ll u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> parent(n + 1, -1);
        vector<ll> depth(n + 1, 0);
        dfs(1, -1, 0, adj, parent, depth);

        auto up = binaryLifting(n, parent);
        vector<int> ans;
        for (auto q : queries)
        {
            ll u = q[0], v = q[1];
            ll lca = findLCA(u, v, n, depth, up);
            ll d = depth[u] + depth[v] - 2 * depth[lca];
            ans.push_back((int)power(2, d - 1));
        }

        return ans;
    }
};