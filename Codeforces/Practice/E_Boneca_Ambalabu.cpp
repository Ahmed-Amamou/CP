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

const int B = 31;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> cnt(B, 0);
    for (int i = 0; i < n; i++)
    {
        for (int b = 0; b < B; b++)
        {
            if (a[i] & (1uLL << b))
                cnt[b]++;
        }
    }

    unsigned ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        unsigned ll sum = 0;
        for (int b = 0; b < B; b++)
        {
            if (a[i] & (1u << b))
            {
                sum += (unsigned ll)(n - cnt[b]) * (1ull << b);
            }
            else
            {
                sum += (unsigned ll)cnt[b] * (1ull << b);
            }
        }
        if (sum > ans)
            ans = sum;
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