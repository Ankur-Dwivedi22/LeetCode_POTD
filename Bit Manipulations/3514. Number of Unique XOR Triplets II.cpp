class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for(int i=0; i<n; i++){
            m = max(m, nums[i]);
        }

        int u = 1;
        while(u <= m){
            u = (u << 1);
        }

        vector<int> one(u), two(u), three(u);
        for(int x : nums){
            one[x] = 1;
            for(int y=0; y<u; y++){
                if(one[y] == 1){
                    two[x ^ y] = 1;
                }
            }
        }

        for(int x : nums){
            for(int y=0; y<u; y++){
                if(two[y]){
                    three[x ^ y] = 1;
                }
            }
        }

        int ans = 0;
        for(int x=0; x<u; x++){
            if(three[x] == 1) ans++;
        }

        return ans;
    }
};