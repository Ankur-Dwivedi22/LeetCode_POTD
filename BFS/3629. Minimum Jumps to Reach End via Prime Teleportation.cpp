bool sieved = false;
bitset<1000005> is_prime;
class Solution {
public:
    using ll = long long;
    const static ll MAXN = 1e6 + 5;

    void sieve(){
        if(sieved) return;
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;

        for(ll p=2; p*p<=MAXN; p++){
            if(is_prime[p]){
                for(ll i=p*p; i<=MAXN; i+=p){
                    is_prime[i] = 0;
                }
            }
        }

        sieved = true;
    }

    int minJumps(vector<int>& nums) {
        sieve();
        ll mx = *max_element(nums.begin(), nums.end());
        vector<vector<ll>> mp(mx+1);
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        int n = nums.size();

        // min value to reach index i
        vector<ll> dp(n, 1e9);
        dp[0] = 0;

        queue<ll> q;
        q.push(0);

        bitset<MAXN> used;

        while(!q.empty()){
            ll u = q.front();
            q.pop();

            if(u == n-1){
                return dp[u];
            }

            if(u+1 < n && dp[u+1] > dp[u] + 1){
                dp[u+1] = 1 + dp[u];
                q.push(u+1);
            }

            if(u-1 >= 0 && dp[u-1] > dp[u] + 1){
                dp[u-1] = 1 + dp[u];
                q.push(u-1);
            }

            ll p = nums[u];
            if(is_prime[p] && !used[p]){
                used[p] = 1;
                for(ll i=p; i<=mx; i+=p){
                    if(!mp[i].empty()){
                        for(int v : mp[i]){
                            if(dp[v] > dp[u] + 1){
                                dp[v] = 1 + dp[u];
                                q.push(v);
                            }
                        }
                        mp[i].clear();
                    }
                }
            }
        }

        return dp[n-1];
    }
};