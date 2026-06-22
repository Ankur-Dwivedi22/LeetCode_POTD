class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        vector<int> freq(26, 0);
        for (char c : text)
        {
            freq[c - 'a']++;
        }
        int ctB = freq['b' - 'a'];
        int ctA = freq['a' - 'a'];
        int ctL = freq['l' - 'a'] / 2;
        int ctO = freq['o' - 'a'] / 2;
        int ctN = freq['n' - 'a'];

        return min({ctB, ctA, ctL, ctO, ctN});
    }
};