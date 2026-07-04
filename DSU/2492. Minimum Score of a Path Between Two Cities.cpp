class DSU
{
public:
    int n;
    vector<int> parent, rank, size;

    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] <= size[ulp_v])
        {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = parent[ulp_v];
        }
        else
        {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = parent[ulp_u];
        }
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = parent[ulp_v];
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = parent[ulp_u];
        }
        else
        {
            parent[ulp_u] = parent[ulp_v];
            rank[ulp_v]++;
        }
    }
};

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        DSU ds(n);

        for (auto it : roads)
        {
            ds.unionBySize(it[0], it[1]);
        }

        int ans = 1e9;
        for (auto it : roads)
        {
            int u = it[0], v = it[1], d = it[2];
            if (ds.find(u) == ds.find(1) || ds.find(v) == ds.find(1))
            {
                ans = min(ans, d);
            }
        }

        return ans;
    }
};