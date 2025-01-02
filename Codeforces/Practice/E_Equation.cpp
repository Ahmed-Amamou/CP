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
    double c;
    cin >> c;
    double l = 0.0;
    double r = 1e6 + 69;
    auto ok = [&](double x) -> bool
    {
        return (x * x + sqrt(x)) >= c;
    };
    for (int i = 0; i < 69; i++)
    {
        double mid = l + (r - l) / 2;
        if (ok(mid))
        {
            r = mid;
        }
        else
            l = mid;
    }
    cout << setprecision(20) << r << endl;
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