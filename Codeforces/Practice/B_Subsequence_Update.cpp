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

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> left, right;
    for (int i = 0; i < r; i++)
    {
        left.push_back(a[i]);
    }
    for (int i = l - 1; i < n; i++)
    {
        right.push_back(a[i]);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    ll sumL = 0, sumR = 0;
    for (int i = 0; i < r - l + 1; i++)
    {
        if (i < left.size())
            sumL += left[i];
    }
    for (int i = 0; i < r - l + 1; i++)
    {
        if (i < right.size())
            sumR += right[i];
    }
    cout << min(sumL, sumR) << endl;
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