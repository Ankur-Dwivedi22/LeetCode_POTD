class Solution
{
public:
    int maxProduct(int n)
    {
        int f = 0, s = 0;
        while (n > 0)
        {
            int dig = n % 10;
            if (dig > f)
            {
                s = f;
                f = dig;
            }
            else if (dig > s)
            {
                s = dig;
            }
            n /= 10;
        }

        return f * s;
    }
};