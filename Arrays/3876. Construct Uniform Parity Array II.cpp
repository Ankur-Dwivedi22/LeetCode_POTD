// Approach : Math
// TC : O(N)
// SC : O(1)
class Solution {
public:
    bool check(int mn_odd, vector<int> &nums, int p){
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 != p){
                if(nums[i] - mn_odd < 1) return false;
            }
        }
        return true;
    }

    bool uniformArray(vector<int>& nums1) {
        int mn_odd = 1e9+1;
        for(int num : nums1){
            if(num % 2)
                mn_odd = min(mn_odd, num);
        }

        return check(mn_odd, nums1, 0) || check(mn_odd, nums1, 1);
    }
};
