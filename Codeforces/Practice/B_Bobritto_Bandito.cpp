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
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    ll minus = n - m;
    ll newL = l;
    ll newR = r;
    while (minus > 0)
    {
        if (minus > 0 && newL < 0)
        {
            newL += 1;
            minus -= 1;
        }
        if (minus > 0 && newR > 0)
        {
            newR -= 1;
            minus -= 1;
        }
    }
    cout << newL << " " << newR << endl;
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