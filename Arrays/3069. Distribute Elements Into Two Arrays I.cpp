class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        res[0] = nums[0];
        res[n - 1] = nums[1];
        int l = 0, r = n - 1;
        for (int i = 2; i < n; i++)
        {
            if (res[l] > res[r])
            {
                res[++l] = nums[i];
            }
            else
            {
                res[--r] = nums[i];
            }
        }
        reverse(res.begin() + r, res.end());
        return res;
    }
};