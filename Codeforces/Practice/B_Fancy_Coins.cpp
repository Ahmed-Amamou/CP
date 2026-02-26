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
    //
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    // x * 1 + y * k = m
    // 0 <= y <=m/k + 69
    // 0 <= x <= 1e8 + 69
    auto calcul = [m, k, a1, ak](int x)
    {
        int taken_1 = m - k * x;
        return max(0LL, taken_1 - a1) + max(0LL, x - ak);
    };

    int l = 0;
    int r = m / k;
    while (r - l > 2)
    {
        int mid = (l + r) / 2;
        if (calcul(mid) < calcul(mid + 1))
            r = mid + 1;
        else
            l = mid;
    }
    int ans = 1e9 + 69;
    for (int i = l; i <= r; i++)
        ans = min(ans * 1LL, calcul(i));
    cout << ans << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    auto start = chrono::steady_clock::now();
    cin >> tt;
    while (tt--)
        solve();
    auto end = chrono::steady_clock::now();
    chrono::duration<double> duration = end - start;
    // cout << "Time taken: " << duration.count() << " seconds" << endl;
    return 0;
}