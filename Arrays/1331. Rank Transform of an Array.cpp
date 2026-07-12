// TC : O(N * logN)
// SC : O(N)
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i], i});
        }

        sort(v.begin(), v.end());
        vector<int> ranks(n);
        int rank = 0, prev = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int idx = v[i].second;
            int curr = v[i].first;
            if (curr != prev)
                rank++;
            ranks[idx] = rank;
            prev = curr;
        }

        return ranks;
    }
};