class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> freq(n+1, 0);
        for(int i=0; i<nums.size(); i++){
            if((nums[i] > n) || (nums[i] != n && freq[nums[i]] > 0)){
                return false;
            }
            freq[nums[i]]++;
        }

        return (freq[n] == 2);
    }
};