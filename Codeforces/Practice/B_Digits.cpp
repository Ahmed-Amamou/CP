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

ll fact(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    ll result = 1;
    for (ll i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

bool div3(ll n, ll d)
{
    if ((d % 3) == 0 || n >= 3 || ((n * d) % 3) == 0)
    {
        return true;
    }
    return false;
}
bool div9(ll n, ll d)
{
    if ((d % 9) == 0 || n >= 9 || (fact(n) * d) % 9 == 0)
        return true;
    return false;
}

bool div5(ll n, ll d)
{
    return (d % 5) == 0;
}

bool div7(int n, int d)
{
    if (d == 7)
        return true;
    if (n > 2)
        return true;
    return false;
}

void solve()
{
    ll n, d;
    cin >> n >> d;
    cout << 1 << " ";
    if (div3(n, d))
        cout << 3 << " ";
    if (div5(n, d))
        cout << 5 << " ";
    if (div7(n, d))
        cout << 7 << " ";
    if (div9(n, d))
        cout << 9;
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