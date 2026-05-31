//Approach : Sorting
// TC : O(N * logN)
// SC : O(1)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long sum = mass;
        for(int w : asteroids){
            if(w > sum){
                return false;
            }
            sum += w;
        }

        return true;
    }
};

// Approach : Countinhg Sort
// TC : O(N + Max_Value)
// SC : O(M)
class Solution {
public:
    using ll = long long;
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        vector<ll> freq(100001, 0);
        ll xmax = 0;
        for(ll x : asteroids){
            freq[x]++;
            xmax = max(xmax, x);
        }
        ll planet = mass;
        for(ll x=1; x<=xmax; x++){
            if(freq[x] == 0) continue;
            if(x > planet){
                return false;
            }
            planet += x * freq[x];
        }

        return true;
    }
};