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
    long long int k, n;
    cin >> k >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    long long int l = 0;
    long long int r = LONG_LONG_MAX - 1;
    auto ok = [&](long long int councils)
    {
        long long int sum = 0;
        for (long long int i = 0; i < n; i++)
        {
            sum += min(a[i], councils);
        }
        return sum / councils >= k;
    };
    while (r - l > 1)
    {
        long long int mid = (l + (r - l) / 2);
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
    long long int tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}