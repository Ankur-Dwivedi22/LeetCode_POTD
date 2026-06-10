class SegmentTree
{
public:
    vector<int> mx, mn;
    SegmentTree(int n)
    {
        mx.resize(4 * n + 1);
        mn.resize(4 * n + 1);
    }

    void create(int node, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            mx[node] = nums[l];
            mn[node] = nums[r];
            return;
        }
        int mid = l + (r - l) / 2;
        create(2 * node, l, mid, nums);
        create(2 * node + 1, mid + 1, r, nums);
        mx[node] = max(mx[2 * node], mx[2 * node + 1]);
        mn[node] = min(mn[2 * node], mn[2 * node + 1]);
    }

    int rangeMaxQ(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
        {
            return INT_MIN;
        }
        if (ql <= l && r <= qr)
        {
            return mx[node];
        }
        int mid = l + (r - l) / 2;
        int left = rangeMaxQ(2 * node, l, mid, ql, qr);
        int right = rangeMaxQ(2 * node + 1, mid + 1, r, ql, qr);
        return max(left, right);
    }

    int rangeMinQ(int node, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
        {
            return INT_MAX;
        }
        if (ql <= l && r <= qr)
        {
            return mn[node];
        }
        int mid = l + (r - l) / 2;
        int left = rangeMinQ(2 * node, l, mid, ql, qr);
        int right = rangeMinQ(2 * node + 1, mid + 1, r, ql, qr);
        return min(left, right);
    }
};

class Solution
{
public:
    using ll = long long;
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        SegmentTree st(n);
        st.create(1, 0, n - 1, nums);
        ll ans = 0;
        priority_queue<vector<ll>> pq;

        for (int l = 0; l < n; l++)
        {
            ll best_range_val = st.rangeMaxQ(1, 0, n - 1, l, n - 1) -
                                st.rangeMinQ(1, 0, n - 1, l, n - 1);
            pq.push({best_range_val, l, n - 1});
        }

        while (k > 0)
        {
            auto it = pq.top();
            pq.pop();
            ans += it[0];
            ll l = it[1], r = it[2];
            if (l <= r - 1)
            {
                ll best_range_val = st.rangeMaxQ(1, 0, n - 1, l, r - 1) -
                                    st.rangeMinQ(1, 0, n - 1, l, r - 1);
                pq.push({best_range_val, l, r - 1});
            }
            k--;
        }

        return ans;
    }
};