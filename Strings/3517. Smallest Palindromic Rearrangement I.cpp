class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int freq[26] = {0};
        for(int i=0; i<n/2; i++){
            freq[s[i] - 'a']++;
        }

        int ind = 0;
        for(int i=0; i<26; i++){
            while(freq[i]--){
                s[ind++] = (char)(i + 'a') ;
            }
        }

        for(int i=0; i<n/2; i++){
            s[n-1-i] = s[i];
        }

        return s;
    }
};