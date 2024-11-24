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
#define debug(x) cout << #x << ": " << x << endl;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    int n;
    cin >> n;
    if (n < 5)
    {
        cout << -1 << endl;
        return;
    }
    int last_odd = (n % 2 == 0) ? n - 1 : n;
    int best;
    for (int i = 2; i <= n; i += 2)
    {
        bool is_prime = true;
        int sum = last_odd + i;
        for (int j = 2; j * j <= sum; ++j)
        {
            if (sum % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (!is_prime)
        {
            best = i;
            break;
        }
    }
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }
    cout << best << " ";
    for (int i = 2; i <= n; i += 2)
    {
        if (i != best)
        {
            cout << i << " ";
        }
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