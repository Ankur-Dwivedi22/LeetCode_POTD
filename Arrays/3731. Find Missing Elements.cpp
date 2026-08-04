class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int ind = 0, mn = nums[0], mx = nums.back();
        for(int i=mn; i<=mx; i++){
            if(i != nums[ind]){
                ans.push_back(i);
            }
            else{
                ind++;
            }
        }

        return ans;
    }
};