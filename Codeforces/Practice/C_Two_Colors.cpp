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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    vector<ll> A(m), B(m);
    for (ll i = 0; i < m; i++)
    {
        A[i] = min(a[i], n - 1);
        B[i] = max(1LL, n - a[i]);
    }
    vector<ll> sortedB = B;
    sort(sortedB.begin(), sortedB.end());
    vector<ll> prefix(m + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        prefix[i + 1] = prefix[i] + sortedB[i];
    }
    ll total = 0;
    for (ll i = 0; i < m; i++)
    {
        ll p = upper_bound(sortedB.begin(), sortedB.end(), A[i]) - sortedB.begin();
        if (p > 0)
        {
            ll count = p;
            ll sumB = prefix[p];
            ll add = (ll)(A[i] + 1) * count - sumB;
            total += add;
        }
    }
    for (ll i = 0; i < m; i++)
    {
        if (A[i] >= B[i])
        {
            total -= (A[i] - B[i] + 1);
        }
    }

    cout << total << endl;
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