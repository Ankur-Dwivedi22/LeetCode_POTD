// TC : O((N + Q) * logN)
// SC : O(N * logN + Q)
class Solution
{
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<int> s = nums;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());

        int M = s.size();
        int jumps = 20;

        vector<vector<int>> up(M, vector<int>(jumps, 0));

        for (int i = 0; i < M; i++)
        {
            auto it = upper_bound(s.begin(), s.end(), s[i] + maxDiff);
            up[i][0] = prev(it) - s.begin();
        }

        for (int j = 1; j < jumps; j++)
        {
            for (int i = 0; i < M; i++)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto q : queries)
        {
            int u = q[0], v = q[1];
            if (u == v)
            {
                ans.push_back(0);
                continue;
            }

            int val_u = nums[u];
            int val_v = nums[v];

            if (val_u > val_v)
            {
                swap(val_u, val_v);
            }

            int idx_u = lower_bound(s.begin(), s.end(), val_u) - s.begin();
            int idx_v = lower_bound(s.begin(), s.end(), val_v) - s.begin();

            if (up[idx_u][jumps - 1] < idx_v)
            {
                ans.push_back(-1);
                continue;
            }
            int d = 0;
            for (int j = jumps - 1; j >= 0; j--)
            {
                if (up[idx_u][j] < idx_v)
                {
                    idx_u = up[idx_u][j];
                    d += (1 << j);
                }
            }

            ans.push_back(d + 1);
        }

        return ans;
    }
};