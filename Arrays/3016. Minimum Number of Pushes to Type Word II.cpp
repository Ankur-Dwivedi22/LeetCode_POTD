class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> v(26, 0);
        for (char c : word)
        {
            v[c - 'a']++;
        }

        sort(v.rbegin(), v.rend());
        int ct = 0, ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] == 0)
                break;
            ct++;
            int key_press = (ct + 7) / 8;
            ans += (key_press * v[i]);
        }

        return ans;
    }
};