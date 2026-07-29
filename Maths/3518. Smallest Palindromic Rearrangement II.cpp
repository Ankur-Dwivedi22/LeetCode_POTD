class Solution {
public:
    using ll = long long;
    const ll L = 1e6;

    ll nCr(ll n, ll r){
        ll res = 1;
        for(int i=1; i<=r; i++){
            res = res * (n - r + i) / (i);
            if(res > L) return L + 1;
        }

        return res;
    }

    ll findWays(vector<ll> &arr){
        ll s = 0, n = arr.size();
        for(int i=0; i<n; i++){
            s += arr[i];
        }
        
        ll ans = 1;
        for(int i=0; i<26; i++){
            if(arr[i] == 0) continue;
            ll res = nCr(s, arr[i]);
            ans = (ans * res);
            if(ans > L) return L+1;
            s -= arr[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        ll n = s.size();
        vector<ll> freq(26, 0), half(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
        }

        ll len = 0;
        string mid = "";
        for(int i=0; i<26; i++){
            half[i] = (freq[i] / 2);
            len += half[i];
            if(freq[i] % 2) mid += (char)(i + 'a');
        }

        if(findWays(half) < k) return "";

        string left = "";
        for(int i=0; i<len; i++){
            for(int j=0; j<26; j++){
                if(half[j] == 0) continue;
                half[j]--;

                ll ways = findWays(half);
                if(ways >= k){
                    left += (char)(j + 'a');
                    break;
                }
                else{
                    k -= ways;
                    half[j]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};