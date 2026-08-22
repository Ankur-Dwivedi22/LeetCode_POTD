class Solution
{
public:
    bool checkDivisibility(int n)
    {
        long long s = 0;
        long long temp = n, sum = 0, pro = 1;
        while (temp > 0)
        {
            pro = pro * 1LL * (temp % 10);
            sum += temp % 10;
            temp /= 10;
        }
        // cout<<sum<<" "<<pro;
        s = sum + pro;
        return (n % (int)s == 0);
    }
};