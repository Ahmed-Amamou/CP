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
    ll n, k;
    cin >> n >> k;
    // ll l = 1, r = n;
    // 13 4
    // 4 7 10 13 3 6 9 12 2 5 8 11 1
    vector<ll> a(n, 0LL);
    // fill even values
    ll j = 0;
    ll value = 1;
    while (j < k)
    {
        for (ll i = j; i < n; i += k)
        {
            a[i] = value++;
        }
        j += 2;
    }
    j = 1;
    value = n;
    while (j < k)
    {
        for (ll i = j; i < n; i += k)
        {
            a[i] = value--;
        }
        j += 2;
    }
    for (auto &e : a)
    {
        cout << e << " ";
    }
    cout << endl;
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