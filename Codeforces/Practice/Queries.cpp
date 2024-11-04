#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree
{
    vector<ll> tree, lazy;
    int n;

    SegTree(int size)
    {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void propagate(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node] * (end - start + 1);
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, ll val)
    {
        propagate(node, start, end);

        if (start > end || start > r || end < l)
            return;

        if (start >= l && end <= r)
        {
            tree[node] += val * (end - start + 1);
            if (start != end)
            {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll queryRange(int node, int start, int end, int l, int r)
    {
        if (start > end || start > r || end < l)
            return 0;

        propagate(node, start, end);

        if (start >= l && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        return queryRange(2 * node, start, mid, l, r) +
               queryRange(2 * node + 1, mid + 1, end, l, r);
    }

    void update(int l, int r, ll val)
    {
        updateRange(1, 1, n, l, r, val);
    }

    ll query(int l, int r)
    {
        return queryRange(1, 1, n, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    SegTree st(n);
    vector<int> values(n + 1, 0); // Keep track of actual values

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 0)
        {
            int l, r, c;
            cin >> l >> r >> c;
            st.update(l, r, c);
        }
        else if (type == 1)
        {
            int l, r, c;
            cin >> l >> r >> c;
            for (int i = l; i <= r; i++)
            {
                st.update(p[i], p[i], c);
            }
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << "\n";
        }
        else
        { // type == 3
            int l, r;
            cin >> l >> r;
            ll sum = 0;
            for (int i = l; i <= r; i++)
            {
                sum += st.query(p[i], p[i]);
            }
            cout << sum << "\n";
        }
    }

    return 0;
}