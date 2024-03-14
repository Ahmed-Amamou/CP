/*
 ▄▀▀▄ ▄▄   ▄▀▀█▄   ▄▀▀▄ ▄▀▄  ▄▀▀▀▀▄   ▄▀▀▀▀▄   ▄▀▀█▄▄
█  █   ▄▀ ▐ ▄▀ ▀▄ █  █ ▀  █ █      █ █      █ █ ▄▀   █
▐  █▄▄▄█    █▄▄▄█ ▐  █    █ █      █ █      █ ▐ █    █
   █   █   ▄▀   █   █    █  ▀▄    ▄▀ ▀▄    ▄▀   █    █
  ▄▀  ▄▀  █   ▄▀  ▄▀   ▄▀     ▀▀▀▀     ▀▀▀▀    ▄▀▄▄▄▄▀
 █   █    ▐   ▐   █    █                      █     ▐
 ▐   ▐            ▐    ▐                      ▐
*/

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
vector<int> coins = {15, 10, 6, 3, 1};
ll dpp(int n)
{

    vector<ll> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i - coins[j] >= 0)
            {
                // ll required = dp[i - coins[j]];
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    

    return dp[n];
}
void solve()
{
    ll n;
    cin >> n;
    ll res = 0;
    for (int i = 0; i < 5; i++)
    {
        if (n >= coins[i])
        {
            res = n / coins[i] - 1;
            n %= coins[i];
            n += coins[i];
            res += dpp(n);
            cout << res << endl;
            return;
        }
    }
}
signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}