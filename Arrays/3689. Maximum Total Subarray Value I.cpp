class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int mx = -1e9, mn = 1e9 + 1;
        for (int num : nums)
        {
            mx = max(mx, num);
            mn = min(mn, num);
        }

        long long ans = (mx - mn) * 1ll * k;
        return ans;
    }
};