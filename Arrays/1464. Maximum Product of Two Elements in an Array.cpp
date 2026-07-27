class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 0, smx = 0;
        for(int e : nums){
            if(e > mx){
                smx = mx;
                mx = e;
            }
            else if(e > smx){
                smx = e;
            }
        }

        return (mx - 1) * (smx - 1);
    }
};