class Solution
{
public:
    int m, n;
    int findScore(int r, int c, int cost, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (cost < 0)
        {
            return -1e9;
        }

        if (dp[r][c][cost] != -1)
            return dp[r][c][cost];

        if (r == 0 && c == 0)
        {
            if (grid[r][c] == 0)
            {
                return 0;
            }
            else
            {
                if (cost >= 1)
                {
                    return grid[r][c];
                }
                else
                {
                    return -1e9;
                }
            }
        }

        int up = -1e9, left = -1e9;
        if (r - 1 >= 0)
        {
            up = grid[r][c] + findScore(r - 1, c, grid[r][c] == 0 ? cost : cost - 1, grid, dp);
        }

        if (c - 1 >= 0)
        {
            left = grid[r][c] + findScore(r, c - 1, grid[r][c] == 0 ? cost : cost - 1, grid, dp);
        }

        return dp[r][c][cost] = max(up, left);
    }

    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1e9)));
        dp[0][0][0] = 0;
        for (int cost = 1; cost <= k; cost++)
        {
            dp[0][0][cost] = grid[0][0];
        }

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                for (int cost = 0; cost <= k; cost++)
                {
                    if (r == 0 && c == 0)
                        continue;
                    int up = -1e9, left = -1e9;
                    if (r - 1 >= 0)
                    {
                        int val = grid[r][c] == 0 ? cost : cost - 1;
                        if (val >= 0)
                            up = grid[r][c] + dp[r - 1][c][val];
                    }

                    if (c - 1 >= 0)
                    {
                        int val = grid[r][c] == 0 ? cost : cost - 1;
                        if (val >= 0)
                            left = grid[r][c] + dp[r][c - 1][val];
                    }

                    dp[r][c][cost] = max(up, left);
                }
            }
        }
        int ans = dp[m - 1][n - 1][k];
        return ans < 0 ? -1 : ans;
    }
};