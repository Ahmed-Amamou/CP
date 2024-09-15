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
    int n, m;
    cin >> n >> m;
    vector<int> speedlimit;
    for (int i = 0; i < n; i++)
    {
        int miles, sl;
        cin >> miles >> sl;
        for (int j = 0; j < miles; j++)
            speedlimit.push_back(sl);
    }
    vector<int> cowspeed;
    for (int i = 0; i < m; i++)
    {
        int miles, sl;
        cin >> miles >> sl;

        for (int j = 0; j < miles; j++)
            cowspeed.push_back(sl);
    }
    int mx = 0;
    for (int i = 0; i < 100; i++)
    {
        mx = max(cowspeed[i] - speedlimit[i], mx);
    }
    cout << mx << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}
