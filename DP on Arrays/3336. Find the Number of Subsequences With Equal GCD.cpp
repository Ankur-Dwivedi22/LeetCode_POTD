// TC : O(N * M * M)
// SC : O(N * M * M)
class Solution
{
public:
    const int M = 1e9 + 7;
    int dp[201][201][201];
    int f(int ind, int g1, int g2, vector<int> &nums)
    {
        if (ind == nums.size())
        {
            return (g1 != 0 && g2 != 0 && (g1 == g2));
        }

        if (dp[ind][g1][g2] != -1)
            return dp[ind][g1][g2];

        int skip = f(ind + 1, g1, g2, nums) % M;
        int pick1 = f(ind + 1, (g1 == 0 ? nums[ind] : __gcd(g1, nums[ind])), g2, nums) % M;
        int pick2 = f(ind + 1, g1, (g2 == 0 ? nums[ind] : __gcd(g2, nums[ind])), nums) % M;

        return dp[ind][g1][g2] = ((((skip + pick1) % M) + pick2)) % M;
    }

    int subsequencePairCount(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 0, nums);
    }
};

// TC : O(N * M * M)
// SC : O(M * M)

class Solution
{
public:
    int subsequencePairCount(vector<int> &nums)
    {
        int M = 1e9 + 7;
        int n = nums.size();

        // 1. Precompute GCDs to drop the __gcd() overhead to O(1)
        int gcd_val[201][201];
        for (int i = 1; i <= 200; i++)
        {
            for (int j = 1; j <= 200; j++)
            {
                gcd_val[i][j] = std::gcd(i, j);
            }
        }

        // 2. Space Optimized DP: We only need the previous state
        vector<vector<int>> dp(201, vector<int>(201, 0));

        // Base case: at index 0, both subsequences are empty (GCDs = 0)
        dp[0][0] = 1;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            vector<vector<int>> next_dp = dp; // Automatically handles the "skip" case

            for (int g1 = 0; g1 <= 200; g1++)
            {
                for (int g2 = 0; g2 <= 200; g2++)
                {

                    // 3. PRUNING: Only process reachable states!
                    if (dp[g1][g2] == 0)
                        continue;

                    int ng1 = (g1 == 0) ? num : gcd_val[g1][num];
                    int ng2 = (g2 == 0) ? num : gcd_val[g2][num];

                    // Pick for seq 1
                    next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % M;
                    // Pick for seq 2
                    next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % M;
                }
            }
            dp = next_dp;
        }

        // 4. Sum up all valid states where g1 == g2 (and neither is empty/0)
        int ans = 0;
        for (int g = 1; g <= 200; g++)
        {
            ans = (ans + dp[g][g]) % M;
        }

        return ans;
    }
};