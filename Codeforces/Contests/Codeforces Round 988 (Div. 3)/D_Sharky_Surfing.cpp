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
void mergeMaps(map<ll, ll> &map1, const map<ll, ll> &map2)
{
    for (const auto &pair : map2)
    {
        map1[pair.first] += pair.second;
    }
}

void solve()
{
    ll n, m, L;
    cin >> n >> m >> L;
    map<ll, ll> obstacles;
    map<ll, map<ll, ll>> powerUps;
    ll count = 0;
    ll power = 1;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        obstacles[x] = y;
    }
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        auto it = obstacles.upper_bound(x);
        if (it != obstacles.end())
        {
            powerUps[it->first][y]++;
        }
    }
    for (const auto &obstacle : obstacles)
    {
        if (obstacle != *obstacles.begin())
        {
            mergeMaps(
                powerUps[obstacle.first],
                powerUps[prev(obstacles.find(obstacle.first))->first]);
        }
        ll k = obstacle.first;
        ll value = obstacle.second;
        ll need = value - k + 2;

        for (auto it = powerUps[k].rbegin(); it != powerUps[k].rend(); ++it)
        {
            ll powerUpValue = it->first;
            ll powerUpCount = it->second;
            while (need > power && powerUpCount > 0)
            {
                power += powerUpValue;
                powerUpCount--;
                count++;
            }   
        }
        if (need > power)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << count << endl;
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