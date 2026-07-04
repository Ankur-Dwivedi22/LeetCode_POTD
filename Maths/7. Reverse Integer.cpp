class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;

        while (x != 0)
        {
            int dig = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && dig > 7))
            {
                return 0;
            }
            if (res < INT_MIN / 10 || ((res == INT_MIN / 10 && dig < -8)))
            {
                return 0;
            }

            res = (res * 10) + dig;
            x /= 10;
        }

        return res;
    }
};