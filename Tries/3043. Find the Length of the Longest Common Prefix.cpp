// Approach 1 : Using Hash Set
// TC : O((N + M) * D*D)
// SC : O((N + M) * D*D)
// N = length of arr1
// M = length of arr2
// D = max length of digits <= 9
class Solution
{
public:
    unordered_set<string> createSet(vector<int> &arr)
    {
        unordered_set<string> st;
        for (int num : arr)
        {
            string s = to_string(num);
            string sub = "";
            for (int i = 0; i < s.size(); i++)
            {
                sub += s[i];
                st.insert(sub);
            }
        }

        return st;
    }

    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        auto st1 = createSet(arr1);
        auto st2 = createSet(arr2);
        int ans = 0;
        for (auto it : st1)
        {
            if (st2.count(it) > 0)
            {
                ans = max(ans, (int)it.size());
            }
        }

        return ans;
    }
};


// Approach 2 : Optimisation of Approach 1
// TC : O((N+M) * D)
// SC : O(N * D*D)
class Solution {
public:
    int countDigit(int n){
        int ct = 0;
        while(n > 0){
            ct++;
            n /= 10;
        }
        return ct;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int num : arr1){
            while(num > 0){
                st.insert(num);
                num /= 10;
            }
        }

        int ans = 0;
        for(int num : arr2){
            while(num > 0){
                if(st.count(num) > 0){
                    ans = max(ans, countDigit(num));
                }
                num /= 10;
            }
        }

        return ans;
    }
};

// Approach 3 : Prefix Trie
// TC : O((N + M) * D)
// SC : O(N * D)
class TrieNode{
public:
    TrieNode* children[10];
    TrieNode(){
        for(int i=0; i<10; i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode* temp = root;
        string s = to_string(num);
        for(char ch : s){
            int dig = ch - '0';
            if(!temp->children[dig]){
                temp->children[dig] = new TrieNode();
            }
            temp = temp->children[dig];
        }
    }

    bool search(int num){
        TrieNode* temp = root;
        string s = to_string(num);
        for(char ch : s){
            int dig = ch - '0';
            if(!temp->children[dig]){
                return false;
            }
            temp = temp->children[dig];
        }
        return true;
    }

    int findLonestPrefix(int num){
        TrieNode* temp = root;
        string s = to_string(num);
        int len = 0;
        for(char ch : s){
            int dig =  ch - '0';
            if(temp->children[dig]){
                len++;
                temp = temp->children[dig];
            }
            else{
                break;
            }
        }

        return len;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int num : arr1){
            trie.insert(num);
        }
        int ans = 0;
        for(int num : arr2){
            int len = trie.findLonestPrefix(num);
            ans = max(ans, len);
        }

        return ans;
    }
};