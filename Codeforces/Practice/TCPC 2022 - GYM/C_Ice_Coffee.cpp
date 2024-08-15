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

vector<int> nextVal(10000005, 1);
void sieve()
{
    for (int i = 1; i < 10000002; i++)
    {
        for (int j = i + i; j < 10000002; j += i)
        {
            nextVal[j] = i;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i + 1];
    }
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        while (true)
        {
            if (a[i] == b[i])
                break;
            if (a[i] > b[i])
            {
                a[i] = nextVal[a[i]];
            }
            else
            {
                b[i] = nextVal[b[i]];
            }
            ans++;
        }
    }
    cout << ans << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << b[i] << endl;
    // }
}

signed main()
{
    FAST;
    ll tt = 1;
    sieve();
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}