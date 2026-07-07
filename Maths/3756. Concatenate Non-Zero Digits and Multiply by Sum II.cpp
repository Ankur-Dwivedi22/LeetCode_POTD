class Solution {
public:
    using ll = long long;
    const ll M = 1e9 + 7;
    ll power(ll a, ll b){
        ll res = 1;
        while(b > 0){
            if(b % 2 != 0) res = (res * a) % M;
            a = (a * a) % M;
            b /= 2;
        }

        return res % M;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<ll> pre(n + 1, 0);
        vector<ll> preSum(n + 1, 0);
        vector<ll> p(n + 1, 0);
        vector<ll> pow10(n+1, 0);

        for(int i=1; i<=n; i++){
            pow10[i] = power(10, i);
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pre[i + 1] = (pre[i] * 10) % M + (s[i] - '0');
                p[i + 1] = p[i] + 1;
            } else{
                pre[i + 1] = pre[i];
                p[i+1] = p[i];
            }
            preSum[i + 1] = preSum[i] + (s[i] - '0');
        }

        vector<int> res;
        for (auto it : queries) {
            int u = it[0], v = it[1];
            ll sum = preSum[v + 1] - preSum[u];
            ll x = (pre[v + 1] - ((pre[u] * 1ll * pow10[p[v+1] - p[u]]) % M) + M) % M;
            ll ans = ((sum % M) * (x % M)) % M;
            res.push_back((int)ans);
        }

        return res;
    }
};