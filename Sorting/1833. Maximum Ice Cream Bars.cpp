// TC : O(N * logN)
// SC : O(logN)
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int ct = 0;
        for (int c : costs)
        {
            if (c <= coins)
            {
                coins -= c;
                ct++;
            }
            else
                break;
        }
        return ct;
    }
};

// Counting Sort
// TC : O(N + M)
// SC : O(M) , M = Maximun of cost
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int mxCost = 0;
        for (int c : costs)
        {
            mxCost = max(mxCost, c);
        }

        vector<int> count(mxCost + 1, 0);
        for (int c : costs)
        {
            count[c]++;
        }

        int bars = 0;
        int remCoins = coins;
        for (int c = 1; c <= mxCost; c++)
        {
            if (count[c] > 0)
            {
                int canBuy = min(count[c], remCoins / c);
                bars += canBuy;
                remCoins -= (canBuy * c);
            }
            if (remCoins == 0)
                break;
        }

        return bars;
    }
};