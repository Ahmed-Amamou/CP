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
/*we have 3 hasmaps, by going through all points and for each one we :
    1- increase the count of points on x,
    2- increase the count of points on y,
    3- increase the count of points on y=-x+b & y=x+b (knowing both x and y this should be ez)
* after that we go through each of these maps and ans+= value*(value-1) only when value>1
*/

void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> hor, ver;
    map<pair<ll, ll>, ll> diagonals;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        pair<ll, ll> firstD = make_pair(1, y - x);
        pair<ll, ll> secondD = make_pair(-1, y + x);
        diagonals[firstD]++;
        diagonals[secondD]++;
        hor[y]++;
        ver[x]++;
    }
    ll ans = 0;
    for (auto d : diagonals)
    {
        if (d.second > 1)
        {
            ans += d.second * (d.second - 1);
        }
    }
    for (auto h : hor)
    {
        if (h.second > 1)
        {
            ans += h.second * (h.second - 1);
        }
    }
    for (auto v : ver)
    {
        if (v.second > 1)
        {
            ans += v.second * (v.second - 1);
        }
    }
    cout << ans << endl;
}

signed main()
{
    FAST;
    int tt = 1;
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}