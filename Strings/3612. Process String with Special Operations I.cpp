class Solution
{
public:
    string processStr(string s)
    {
        string res = "";
        for (char c : s)
        {
            if (c == '*')
            {
                if (!res.empty())
                    res.pop_back();
            }
            else if (c == '#')
            {
                if (!res.empty())
                    res += res;
            }
            else if (c == '%')
            {
                if (!res.empty())
                    reverse(res.begin(), res.end());
            }
            else
            {
                res += c;
            }
        }

        return res;
    }
};