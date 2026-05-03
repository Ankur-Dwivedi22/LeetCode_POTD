// Approach 1 : Brute force
// TC : O(N * N)
// SC : O(N)
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        s += s;
        int n = s.size(), m = goal.size();
        for (int i = 0; i <= n - m; i++)
        {
            string sub = s.substr(i, m);
            if (sub == goal)
            {
                return true;
            }
        }
        return false;
    }
};

// Approach 2 : Brute force
// TC : O(N * N) worst case, best caase : O(N)
// SC : O(N)
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        string double_s = s + s;
        return double_s.find(goal) != string::npos;
    }
};

// Approach 3 : KMP Algorithm
// goal -> M , double_s -> N
// TC : O(M + N)
// SC : O(M) [KMP] + O(N) [ind array] => O(M)
class Solution
{
public:
    vector<int> createLPS(string &s)
    {
        int m = s.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i++] = len;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }
        return lps;
    }

    vector<int> search(string &pat, string &txt)
    {
        vector<int> ind;
        vector<int> lps = createLPS(pat);
        int i = 0, j = 0;
        int n = txt.size(), m = pat.size();
        while (i < n)
        {
            if (txt[i] == pat[j])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                ind.push_back(i - m);
                j = lps[j - 1];
            }
            else if (i < n && txt[i] != pat[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return ind;
    }

    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;
        string double_s = s + s;
        vector<int> ans = search(goal, double_s);
        return (!ans.empty());
    }
};