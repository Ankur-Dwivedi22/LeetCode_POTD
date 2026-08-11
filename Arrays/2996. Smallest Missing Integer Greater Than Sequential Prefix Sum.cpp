class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] - nums[i-1] == 1){
                ans += nums[i];
            }
            else break;
        }
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] == ans) ans++;
        }

        return ans;
    }
};