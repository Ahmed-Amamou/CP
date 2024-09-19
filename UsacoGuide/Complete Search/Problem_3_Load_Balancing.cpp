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
    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> points(n);
    set<int> horizontals, verticals;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
        horizontals.insert(points[i].second + 1);
        verticals.insert(points[i].first + 1);
    }

    sort(points.begin(), points.end());

    ll best = n;
    ll topleft = 0, botleft = 0, topright = 0, botright = 0;
    for (int h : horizontals)
    {
        for (int v : verticals)
        {
            for (auto p : points)
            {
                if (p.first < v && p.second < h)
                    botleft++;
                if (p.first < v && p.second > h)
                    topleft++;
                if (p.first > v && p.second < h)
                    botright++;
                if (p.first > v && p.second > h)
                    topright++;
            }
            best = min(best, max({topleft, topright, botleft, botright}));
            topleft = topright = botright = botleft = 0;
        }
    }
    cout << best << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}