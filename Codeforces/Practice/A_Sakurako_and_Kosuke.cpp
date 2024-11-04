
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
    int n;
    cin >> n;
    ll sign = 1;
    ll sum = 0;
    for (int i = 1; i < INT32_MAX; i++)
    {
        sum += sign * (2 * i - 1);
        sign *= -1;
        // cout << sum << endl;
        if ((sum > n) || (sum < -1 * n))
            break;
    }
    if (sign == -1)
    {
        cout << "Sakurako" << endl;
    }
    else
    {
        cout << "Kosuke" << endl;
    }
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