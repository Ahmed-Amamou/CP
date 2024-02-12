
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

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    set<vector<ll>> set1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (is_sorted(a, a + n))
    {
        cout << 0 << endl;
        return;
    }
    else if (a[n - 1] >= 0 && a[n - 1] >= a[n - 2])
    {
        cout << n - 2 << endl;
        for (int i = 0; i < n - 2; i++)
        {
            vector<ll> v;
            cout << i + 1 << " " << n - 1 << " " << n << endl;
        }
        return;
    }

    else
        cout << -1 << endl;
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