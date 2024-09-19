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
// #define debug(x) cout << #x << ": " << x << endl;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    int n;
    cin >> n;
    int swaps[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> swaps[i][0] >> swaps[i][1] >> swaps[i][2];
    }
    // pebble is in first
    int k[3] = {1, 0, 0};
    ll cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        swap(k[swaps[i][0] - 1], k[swaps[i][1] - 1]);
        cnt1 += (k[swaps[i][2] - 1]) == 1 ? 1 : 0;
    }
    int l[3] = {0, 1, 0};
    ll cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        swap(l[swaps[i][0] - 1], l[swaps[i][1] - 1]);
        cnt2 += (l[swaps[i][2] - 1]) == 1 ? 1 : 0;
    }

    int m[3] = {0, 0, 1};
    ll cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        swap(m[swaps[i][0] - 1], m[swaps[i][1] - 1]);
        cnt3 += (m[swaps[i][2] - 1]) == 1 ? 1 : 0;
    }
    cout << max({cnt1, cnt2, cnt3}) << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}