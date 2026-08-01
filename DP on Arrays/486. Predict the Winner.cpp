class Solution
{
public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }

        for (int left = n - 1; left >= 0; left--)
        {
            for (int right = 0; right < n; right++)
            {
                if (left == right)
                    continue;
                int c1 = -1e9, c2 = -1e9;
                if (left + 1 < n)
                    c1 = nums[left] - dp[left + 1][right];
                if (right - 1 >= 0)
                    c2 = nums[right] - dp[left][right - 1];

                dp[left][right] = max(c1, c2);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};

// TC : O(N)
// SC : O(N)
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 0){
            return true;
        }

        vector<int> dp = nums;
        for(int left=n-2; left>=0; left--){
            for(int right=left+1; right<n; right++){
                dp[right] = max(nums[left] - dp[right], nums[right] - dp[right-1]);
            }
        }

        return(dp[n-1] >= 0);
    }
};