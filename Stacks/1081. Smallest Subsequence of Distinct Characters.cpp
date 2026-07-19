class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        vector<int> freq(26, 0);
        vector<int> seen(26, 0);
        for(char c : s){
            freq[c-'a']++;
        }

        for(char c : s){
            while(!st.empty() && c < st.top() && !seen[c-'a'] && freq[st.top() - 'a'] > 0){
                char t = st.top();
                st.pop();
                seen[t-'a'] = 0;
            }
            if(!seen[c-'a']){
                st.push(c);
                seen[c-'a'] = 1;
            }
            freq[c-'a']--;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};