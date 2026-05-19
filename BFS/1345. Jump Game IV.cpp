// Approach 1 : BFS
// TC : O(N)
// SC : O(N) + O(N) + O(N)
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int ind = q.front();
                q.pop();
                if (ind == n - 1)
                {
                    return steps;
                }

                for (int next_ind : mp[arr[ind]])
                {
                    if (!vis[next_ind])
                    {
                        q.push(next_ind);
                        vis[next_ind] = 1;
                    }
                }
                mp.erase(arr[ind]);

                if (ind + 1 < n && !vis[ind + 1])
                {
                    vis[ind + 1] = 1;
                    q.push(ind + 1);
                }

                if (ind - 1 >= 0 && !vis[ind - 1])
                {
                    vis[ind - 1] = 1;
                    q.push(ind - 1);
                }
            }
            steps++;
        }

        return 0;
    }
};