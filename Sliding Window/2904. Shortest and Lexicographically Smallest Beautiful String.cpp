// Approach 1 : Brute force
// TC : O(N ^ 3) 
// SC : O(N)

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int mnlen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int ct1 = 0;
            string sub = "";
            for (int j = i; j < n; j++) {
                sub += s[j];
                if (s[j] == '1')
                    ct1++;
                if (ct1 == k) {
                    if (sub.size() < mnlen) {
                        mnlen = sub.size();
                        ans = sub;
                    } else if (sub.size() == mnlen) {
                        ans = min(ans, sub);
                    }
                }
            }
        }

        return ans;
    }
};

// Approach 2 : Sliding Window
// TC : O(N ^ 2)
// SC : O(N)
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        string ans = "";
        int mnlen = INT_MAX;
        int ct1 = 0;
        while(r < n){
            ct1 += (s[r] == '1');
            while(ct1 == k){
                int len = r-l+1;
                string sub = s.substr(l, len);
                if(len < mnlen){
                    mnlen = len;
                    ans = sub;
                }
                else if(len == mnlen){
                    ans = min(ans, sub);
                }
                ct1 -= (s[l] == '1');
                l++;
            }
            r++;
        }

        return ans;
    }
};
