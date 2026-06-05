class Solution
{
public:
    using ll = long long;
    ll dp[17][11][11][2][2][17];
    ll dp_func(ll ind, ll prev, ll curr, bool tight, bool started, ll wav, string &s)
    {
        if (ind == s.size())
        {
            return wav;
        }

        if (dp[ind][prev + 1][curr + 1][tight][started][wav] != -1)
            return dp[ind][prev + 1][curr + 1][tight][started][wav];

        ll lb = 0;
        ll ub = (tight ? s[ind] - '0' : 9);
        ll ans = 0;

        for (int dig = lb; dig <= ub; dig++)
        {
            bool next_started = (started || dig > 0);
            ll next_prev = (started ? curr : -1);
            ll next_curr = (next_started ? dig : -1);
            bool next_tight = (tight && dig == ub);

            ll is_wave = 0;
            if (started && prev != -1 && curr != -1)
            {
                if ((prev < curr && curr > dig) || (prev > curr && curr < dig))
                {
                    is_wave = 1;
                }
            }

            ans += dp_func(ind + 1, next_prev, next_curr, next_tight, next_started, wav + is_wave, s);
        }

        return dp[ind][prev + 1][curr + 1][tight][started][wav] = ans;
    }

    ll solve(ll n)
    {
        if (n < 100)
            return 0;

        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dp_func(0, -1, -1, true, false, 0, s);
    }

    ll totalWaviness(ll num1, ll num2)
    {
        ll left = solve(num1 - 1);
        ll right = solve(num2);

        return right - left;
    }
};