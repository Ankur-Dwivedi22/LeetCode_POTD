class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            int x = nums[i];
            while (x > 0)
            {
                ans.push_back(x % 10);
                x /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};