class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &grid)
    {
        int m, n;
        m = grid.size();
        n = grid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, ' '));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = grid[m - 1 - j][i];
            }
        }

        for (int j = 0; j < m; j++)
        {
            int last = n - 1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (ans[i][j] == '#')
                {
                    ans[i][j] = '.';
                    ans[last][j] = '#';
                    last--;
                }
                if (ans[i][j] == '*')
                {
                    last = i - 1;
                }
            }
        }

        return ans;
    }
};