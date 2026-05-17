// TC : O(N)
// SC : O(N) + O(N)
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty())
        {
            int ind = q.front();
            q.pop();
            int val = arr[ind];
            if (val == 0)
            {
                return true;
            }
            int leftInd = ind - val;
            int rightInd = ind + val;

            if (leftInd >= 0 && !vis[leftInd])
            {
                vis[leftInd] = 1;
                q.push(leftInd);
            }

            if (rightInd < n && !vis[rightInd])
            {
                vis[rightInd] = 1;
                q.push(rightInd);
            }
        }

        return false;
    }
};