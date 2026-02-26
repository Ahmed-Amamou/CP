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
bool doable = false;
ll n, x, y;
bool ok(ll T)
{
    if (T < min(x, y))
        return false;
    return ((T - min(x, y)) / x + (T - min(x, y)) / y >= n - 1);
}
void solve()
{
    cin >> n >> x >> y;
    // we need to fin T such that t/x + t/y >= n+1
    ll l = 0;
    ll r = 1;
    while (!ok(r))
    {
        r <<= 1;
    }
    while (r - l > 1)
    {
        ll mid = l + (r - l) / 2;
        if (ok(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
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