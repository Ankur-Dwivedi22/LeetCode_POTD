// Approach : Greedy
// TC : O(N)
// SC : O(1)

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        int mx = INT_MIN, mn = INT_MAX;
        int loc_mx = -1, loc_mn = -1;
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(num > mx){
                mx = num;
                loc_mx = i;
            }
            if(num < mn){
                mn = num;
                loc_mn = i;
            }
        }

        int left = max(loc_mx, loc_mn) + 1;
        int right = n - min(loc_mx, loc_mn);
        int mix = 0;
        for(int i=0; i<n; i++){
            mix++;
            if(nums[i] == mx || nums[i] == mn){
                break;
            }
        }

        for(int i=n-1; i>=0; i--){
            mix++;
            if(nums[i] == mn || nums[i] == mx){
                break;
            }
        }

        return min({left, right, mix});
    }
};
