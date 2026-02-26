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
    ll k, n;
    cin >> k >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    ll l = 0;
    ll r = LONG_LONG_MAX - 6 - 9;
    auto ok = [&](ll councils)
    {
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += min(a[i], councils);
        }
        return sum / councils >= k;
    };
    while (r - l > 1)
    {
        ll mid = (l + (r - l) / 2);
        if (ok(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}