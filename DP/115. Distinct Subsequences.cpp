// Memoisation
// TC : O(N1 * N2)
// SC : O(N1 * N2) + O(N1 + N2)
class Solution {
public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j == t.size()){
            return 1;
        }

        if(i == s.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int skip = solve(i+1, j, s, t, dp);
        int pick = 0;
        if(s[i] == t[j]){
            pick = solve(i+1, j+1, s, t, dp);
        }

        return dp[i][j] = pick + skip;
    }

    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve(0, 0, s, t, dp);
    }
};

// Tabulation
// TC : O(N1 * N2)
// SC : O(N1 * N2)

class Solution {
public:
    using ll = long long;
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<ll>> dp(n1 + 1, vector<ll>(n2 + 1, 0));
        for (int i = 0; i <= n1; i++) {
            dp[i][n2] = 1;
        }

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                ll skip = dp[i+1][j];
                ll pick = 0;
                if (s[i] == t[j]) {
                    pick = dp[i+1][j+1];
                }

                dp[i][j] = min(1ll * INT_MAX, pick + skip);
            }
        }
        return dp[0][0];
    }
};

// Space Optimisation 
// TC : O(N1 * N2)
// SC : O(N2)

class Solution {
public:
    using ll = long long;
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<ll> dp(n2 + 1, 0), curr(n2+1, 0);
        for (int i = 0; i <= n1; i++) {
            dp[n2] = curr[n2] = 1;
        }

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                ll skip = dp[j];
                ll pick = 0;
                if (s[i] == t[j]) {
                    pick = dp[j+1];
                }
                curr[j] = min(1LL * INT_MAX, pick + skip);
            }
            dp = curr;
        }

        return dp[0];
    }
};
