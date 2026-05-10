class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        // vector<vector<int>> grid = v;
        int m = grid.size(), n = grid[0].size();
        int layers = min(m / 2, n / 2);
        for (int l = 0; l < layers; l++)
        {
            vector<int> r, c, val;
            // left
            for (int i = l; i < m - 1 - l; i++)
            {
                r.push_back(i);
                c.push_back(l);
                val.push_back(grid[i][l]);
            }

            // down;
            for (int j = l; j < n - 1 - l; j++)
            {
                r.push_back(m - 1 - l);
                c.push_back(j);
                val.push_back(grid[m - 1 - l][j]);
            }

            // right
            for (int i = m - 1 - l; i > l; i--)
            {
                r.push_back(i);
                c.push_back(n - 1 - l);
                val.push_back(grid[i][n - 1 - l]);
            }

            // up
            for (int j = n - 1 - l; j > l; j--)
            {
                r.push_back(l);
                c.push_back(j);
                val.push_back(grid[l][j]);
            }

            int sz = val.size();
            int kk = k % sz;

            for (int i = 0; i < sz; i++)
            {
                int ind = (i + sz - kk) % sz;
                grid[r[i]][c[i]] = val[ind];
            }
        }

        return grid;
    }
};