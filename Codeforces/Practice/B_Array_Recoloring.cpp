// Author: Ahmed Amamou

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

using namespace std;
#define debug(x) cout << #x << ": " << x << endl;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
const ll NEG_INF = -1e17;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // dpLeft[i][j] = maximum sum by selecting exactly j elements from arr[0..i-1]
    vector<vector<ll>> dpLeft(n + 1);
    dpLeft[0].resize(1, 0);
    for (int i = 1; i <= n; i++)
    {
        int sz = min(i, k) + 1;
        dpLeft[i].resize(sz, NEG_INF);
        for (int j = 0; j < dpLeft[i - 1].size(); j++)
        {
            dpLeft[i][j] = dpLeft[i - 1][j];
        }
        for (int j = 1; j < sz; j++)
        {
            if (j - 1 < (int)dpLeft[i - 1].size() && dpLeft[i - 1][j - 1] != NEG_INF)
                dpLeft[i][j] = max(dpLeft[i][j], dpLeft[i - 1][j - 1] + arr[i - 1]);
        }
    }

    // Build dpRight: dpRight[i] is for suffix starting at index i (arr[i..n-1])
    vector<vector<ll>> dpRight(n + 1);
    dpRight[n].resize(1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int sz = min(n - i, k) + 1;
        dpRight[i].resize(sz, NEG_INF);
        for (int j = 0; j < dpRight[i + 1].size(); j++)
        {
            dpRight[i][j] = dpRight[i + 1][j];
        }
        for (int j = 1; j < sz; j++)
        {
            if (j - 1 < (int)dpRight[i + 1].size() && dpRight[i + 1][j - 1] != NEG_INF)
                dpRight[i][j] = max(dpRight[i][j], dpRight[i + 1][j - 1] + arr[i]);
        }
    }

    ll ans = 0;
    for (int p = 0; p < n; p++)
    {
        ll best = NEG_INF;
        if (p == 0)
        {
            if (n > 1 && (int)dpRight[1].size() > k && dpRight[1][k] != NEG_INF)
                best = arr[0] + dpRight[1][k];
        }
        else if (p == n - 1)
        {
            // No right part; all k picks come from left.
            if ((int)dpLeft[n - 1].size() > k && dpLeft[n - 1][k] != NEG_INF)
                best = arr[n - 1] + dpLeft[n - 1][k];
        }
        else
        {
            for (int leftCount = 1; leftCount <= min(p, k - 1); leftCount++)
            {
                int rightCount = k - leftCount;
                if (rightCount < 1)
                    continue;
                if (rightCount >= (int)dpRight[p + 1].size())
                    continue;
                if (leftCount >= (int)dpLeft[p].size())
                    continue;
                if (dpLeft[p][leftCount] == NEG_INF || dpRight[p + 1][rightCount] == NEG_INF)
                    continue;
                best = max(best, arr[p] + dpLeft[p][leftCount] + dpRight[p + 1][rightCount]);
            }
        }
        ans = max(ans, best);
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}