class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string ans = "";
        for (string word : words)
        {
            int sum = 0;
            for (char c : word)
            {
                int ind = c - 'a';
                sum += (weights[ind]);
            }

            sum = (sum % 26);
            ans += (char)((25 - sum) + 'a');
        }

        return ans;
    }
};