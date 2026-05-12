// Approach 1 : Binary Search
// TC : O(N * logN) + O(N * log(mx)) where mx = 1e9+5
// SC : O(1)
class Solution
{
public:
    using ll = long long;
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        ll d1 = a[1] - a[0];
        ll d2 = b[1] - b[0];
        return d1 > d2;
    }

    bool valid(ll mn, vector<vector<int>> &t)
    {
        ll val = mn;
        for (auto it : t)
        {
            ll req = it[1];
            ll act = it[0];
            if (val >= req)
            {
                if (val >= act)
                {
                    val -= act;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    int minimumEffort(vector<vector<int>> &tasks)
    {
        ll lo = 0, hi = 1e9 + 5;
        sort(tasks.begin(), tasks.end(), cmp);
        ll ans = -1;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (valid(mid, tasks))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return (int)ans;
    }
};

// Approach 2 : Sorting only
// TC : O(N * logN)
// SC : O(1)
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), cmp);
        int curr = 0, start = 0;

        for (int i = 0; i < tasks.size(); i++)
        {
            int actual = tasks[i][0];
            int mn = tasks[i][1];

            if (curr < mn)
            {
                start += (mn - curr);
                curr = mn;
            }

            curr -= actual;
        }

        return start;
    }
};