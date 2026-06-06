class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int leftSum = 0, rightSum = 0;
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = leftSum;
            leftSum += nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = abs(ans[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
};