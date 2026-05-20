// Approach 1 : Hash array
// TC : O(N * N)
// SC : O(N)
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> seen(n + 1, 0);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            seen[A[i]]++;
            int ct = 0;
            for (int j = 0; j <= i; j++)
            {
                if (seen[B[j]])
                    ct++;
            }
            ans[i] = ct;
        }

        return ans;
    }
};

// Approach 2 : Single Pass
// TC : O(N)
// SC : O(N)
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> seen(n + 1, 0);
        vector<int> ans(n);
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            seen[A[i]]++;
            if (seen[A[i]] == 2)
                ct++;
            seen[B[i]]++;
            if (seen[B[i]] == 2)
                ct++;
            ans[i] = ct;
        }

        return ans;
    }
};