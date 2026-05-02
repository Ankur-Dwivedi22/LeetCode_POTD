// Approach 1 : Simulation
// TC : O(n * log10(n))
// SC : O(1)
class Solution
{
public:
    int rotatedDigits(int n)
    {
        int good = 0;
        for (int num = 1; num <= n; num++)
        {
            // cout<<num<<"\n";
            bool valid = true, diff = false;
            int temp = num;
            while (temp > 0)
            {
                int dig = temp % 10;
                if (dig == 2 || dig == 5 || dig == 6 || dig == 9)
                {
                    diff = true;
                }
                else if (dig == 0 || dig == 1 || dig == 8)
                {
                    valid = true;
                }
                else
                {
                    valid = false;
                    break;
                }
                temp /= 10;
            }
            if (valid && diff)
            {
                good++;
            }
        }

        return good;
    }
};

// Approach 2 : Digit DP
// TC : O (6 * 2 * 2 * 9) + O(5) => O(1)
// SC : O (6 * 2 * 2) + O(5) => O(1)
class Solution
{
public:
    int dp[6][2][2];

    int dp_func(int ind, bool tight, bool diff, string &s)
    {
        if (ind == s.size())
        {
            return diff;
        }

        if (dp[ind][tight][diff] != -1)
        {
            return dp[ind][tight][diff];
        }

        int lb = 0;
        int ub = tight ? (s[ind] - '0') : 9;
        int res = 0;
        for (int i = lb; i <= ub; i++)
        {
            if (i == 3 || i == 4 || i == 7)
                continue;
            res += dp_func(ind + 1, (tight && i == ub), (diff || i == 2 || i == 5 || i == 6 || i == 9), s);
        }
        return dp[ind][tight][diff] = res;
    }

    int rotatedDigits(int n)
    {
        string num = to_string(n);
        while (num.size() != 5)
        {
            num = "0" + num;
        }
        memset(dp, -1, sizeof(dp));
        return dp_func(0, 1, 0, num);
    }
};