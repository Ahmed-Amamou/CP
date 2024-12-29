

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
const int MAXN = 1e7 + 1;
vector<bool> is_prime(MAXN, true);

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

void solve()
{
    int x, n;
    cin >> x >> n;
    // cout << " racine t3 10^8: " << sqrt(100000000) << endl;
    int q = x / n;
    if (n == 1)
    {
        cout << x << endl;
        return;
    }
    int mx = 0;
    for (int i = 1; i <= sqrt(x) + 1; i++)
    {
        if (x % i == 0 && i<=q)
        {
            mx = max(mx, i);
            if (x / i <= q)
            {
                mx = max(mx, x / i);
            }
        }
    }
    cout << mx << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // sieve();
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
