class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0, sum = 0, p = 1;
        while (n > 0)
        {
            int dig = n % 10;
            sum += dig;
            if (dig > 0)
            {
                x = x + (dig * p);
                p = (p * 10);
            }
            n /= 10;
        }

        return x * sum;
    }
};