class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int ct1 = 0, n = s.size();
        for (char c : s)
        {
            if (c == '1')
                ct1++;
        }

        int prev = -1e9, curr = 0;
        int mx0 = 0;
        int i = 0;
        while (i < n)
        {
            int start = i;
            while (i < n && s[i] == s[start])
            {
                i++;
            }

            if (s[start] == '0')
            {
                curr = i - start;
                mx0 = max(mx0, curr + prev);
                prev = curr;
            }
        }

        return mx0 + ct1;
    }
};