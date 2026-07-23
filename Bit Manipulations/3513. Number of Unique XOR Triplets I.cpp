class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;
        int mx_bit = 0;
        while (n > 0)
        {
            mx_bit++;
            n /= 2;
        }

        return (1 << mx_bit);
    }
};