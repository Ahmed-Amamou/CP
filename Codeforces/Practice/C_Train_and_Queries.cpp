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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    map<ll, pair<ll, ll>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = make_pair(i, i);
        }
        else
        {
            mp[a[i]].second = i;
        }
    }
    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << it->first << ": " << it->second.first << " | " << it->second.second << endl;
    // }
    // cout << " --------" << endl;
    for (int i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (mp.find(x) == mp.end() || mp.find(y) == mp.end())
        {
            cout << "NO" << endl;
            continue;
        }
        if (mp[x].first > mp[y].second)
        {
            cout << "NO" << endl;
        }

        else
        {
            cout << "YES" << endl;
        }
    }
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