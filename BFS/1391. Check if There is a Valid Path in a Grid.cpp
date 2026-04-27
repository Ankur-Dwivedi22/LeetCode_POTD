class Solution
{
public:
    void helper(int i, int j, int pi, int pj, vector<vector<int>> &dirs, int m,
                int n, queue<vector<int>> &q, bool &valid)
    {
        if (pi == -1 && pj == -1)
            valid = true;
        for (int k = 0; k < 2; k++)
        {
            int ni = i + dirs[k][0];
            int nj = j + dirs[k][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;
            if (ni == pi && nj == pj)
            {
                valid = true;
            }
            else
            {
                q.push({ni, nj, i, j});
            }
        }
    }

    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dirs = {
            {{0, -1}, {0, +1}}, {{-1, 0}, {+1, 0}}, {{0, -1}, {+1, 0}}, {{0, +1}, {+1, 0}}, {{0, -1}, {-1, 0}}, {{0, +1}, {-1, 0}}};
        queue<vector<int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        q.push({0, 0, -1, -1});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int i = it[0], j = it[1], pi = it[2], pj = it[3];
            // cout << i << " " << j << " " << pi << " " << pj << "\n";
            int ind = grid[i][j] - 1;
            bool valid = false;
            if (i == m - 1 && j == n - 1)
            {
                helper(i, j, pi, pj, dirs[ind], m, n, q, valid);
                if (valid)
                    return true;
            }
            if (vis[i][j])
            {
                return false;
            }
            vis[i][j] = 1;
            helper(i, j, pi, pj, dirs[ind], m, n, q, valid);
            if (!valid)
            {
                // cout << i << " " << j << "\n";
                return false;
            }
        }

        return false;
    }
};