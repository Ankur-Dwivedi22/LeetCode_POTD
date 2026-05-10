class Solution {
public:
    int dp[1001];
    int dp_func(int ind, vector<int> &nums, int t){
        if(ind == nums.size()-1){
            return 0;
        }

        if(dp[ind] != -1) return dp[ind];

        int ans = -1e9;
        for(int j=ind+1; j<nums.size(); j++){
            int val = nums[j] - nums[ind];
            if(val >= -t && val <= t)
                ans = max(ans, 1 + dp_func(j, nums, t));
        }

        return dp[ind] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int jumps = dp_func(0, nums, target);
        if(jumps < 0){
            return -1;
        }        
        return jumps;
    }
};