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
    vector<pair<string, pair<int, int>>> highway;
    for (int i = 0; i < n; i++)
    {
        string s;
        int l, r;
        cin >> s >> l >> r;
        if (i != 0 && highway.back().first == "none" && s == "none")
        {

            highway.back().second.first = max(l, highway.back().second.first);
            highway.back().second.second = min(r, highway.back().second.second);
        }
        else
        {
            highway.push_back(make_pair(s, make_pair(l, r)));
        }
    }
    int mn = 0, mx = 100000000;
    for (int i = highway.size() - 1; i >= 0; i--)
    {
        string type = highway[i].first;
        pair<int, int> range = highway[i].second;
        if (type == "none")
        {
            mn = max(mn, range.first);
            mx = min(mx, range.second);
        }
        else if (type == "on")
        {
            mn = max(0, mn - range.second);
            mx = mx - range.first;
        }
        else
        {
            mn = mn + range.first;
            mx = mx + range.second;
        }
    }
    cout << mn << " " << mx << endl;
    mn = 0, mx = 100000000;
    for (int i = 0; i < highway.size(); i++)
    {
        string type = highway[i].first;
        pair<int, int> range = highway[i].second;
        if (type == "none")
        {
            mn = max(mn, range.first);
            mx = min(mx, range.second);
        }
        else if (type == "on")
        {
            mn = mn + range.first;
            mx = mx + range.second;
        }
        else
        {
            mn = max(0, mn - range.second);
            mx = mx - range.first;
        }
    }
    cout << mn << " " << mx << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}