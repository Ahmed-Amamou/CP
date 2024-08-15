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

vector<bool> primes(1000005, true);

void sieve()
{
    primes[1]=primes[0] = false;
    for (int i = 2; i * i < 1000005; i++)
    {
        if (primes[i])
        {
            for (int p = i + i; p < 1000005; p += i)
            {
                primes[p] = false;
            }
        }
    }
}

void solve()
{
    int n, e;
    cin >> n >> e;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll left = 0, right = 0;
        if (primes[a[i]])
        {
            for (int j = i + e; j < n; j+=e)
            {
                if (a[j] == 1)
                {
                    right++;
                }
                else
                {
                    break;
                }
            }
            for (int j = i - e; j >= 0; j-=e)
            {
                if (a[j] == 1)
                {
                    left++;
                }
                else
                {
                    break;
                }
            }
        }
        ans += left + right + right * left;
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    sieve();
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << i << ": " << primes[i] << " ";
    // }

    // freopen("input.in", "r", stdin);
    cin >>
        tt;
    while (tt--)
        solve();
    return 0;
}