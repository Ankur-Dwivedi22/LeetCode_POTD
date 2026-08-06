class Solution {
public:
    int findDigPro(int n){
        int p = 1;
        while(n){
            int d = n % 10;
            p = p * d;
            n /= 10;
        }

        return p;
    }
    int smallestNumber(int n, int t) {
        int ans = n;
        while(1){
            if(findDigPro(ans) % t == 0){
                return ans;
            }
            ans++;
        }
        return ans;
    }
};