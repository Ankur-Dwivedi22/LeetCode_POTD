// TC : O(N)
// SC : O(1)
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int ct = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                ct++;
            }
        }

        if (nums[0] < nums[n - 1])
            ct++;

        return (ct <= 1);
    }
};