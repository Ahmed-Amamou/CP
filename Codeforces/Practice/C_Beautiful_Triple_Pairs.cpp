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

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<pair<int, int>, int> mp1;
    map<pair<int, int>, int> mp2;
    map<pair<int, int>, int> mp3;

    map<pair<pair<int, int>, int>, int> triple;

    ll ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int cdeja = triple[{{a[i], a[i + 1]}, a[i + 2]}];
        ans += mp1[{a[i], a[i + 1]}] - cdeja;
        ans += mp2[{a[i], a[i + 2]}] - cdeja;
        ans += mp3[{a[i + 1], a[i + 2]}] - cdeja;

        triple[{{a[i], a[i + 1]}, a[i + 2]}]++;

        mp1[{a[i], a[i + 1]}]++;
        mp2[{a[i], a[i + 2]}]++;
        mp3[{a[i + 1], a[i + 2]}]++;
    }
    cout << ans <<endl;
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