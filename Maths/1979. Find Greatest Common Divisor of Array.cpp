class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a < b)
        {
            return gcd(b, a);
        }
        if (b == 0)
            return a;
        return gcd(a % b, b);
    }
    int findGCD(vector<int> &nums)
    {
        int mn = 1001, mx = 0;
        for (int e : nums)
        {
            mn = min(mn, e);
            mx = max(mx, e);
        }

        return gcd(mx, mn);
    }
};