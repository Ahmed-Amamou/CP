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
int bfs(vector<int> graph[], int n, int start)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    q.push(start);
    dist[0] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : graph[v])
        {
            if (dist[v] + 1 < dist[u])
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist[n - 1];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> railways[n];
    vector<int> roads[n];
    set<pair<int, int>> seen;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        railways[u].push_back(v);
        railways[v].push_back(u);
        seen.insert(make_pair(u, v));
        seen.insert(make_pair(v, u));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            pair<int, int> pp1 = make_pair(i, j);
            pair<int, int> pp2 = make_pair(j, i);
            if (j != i && seen.find(pp1) == seen.end() && seen.find(pp2) == seen.end())
            {
                roads[i].push_back(j);
                roads[j].push_back(i);
            }
        }
    }
    int rails_path = bfs(railways, n, 0);
    int road_path = bfs(roads, n, 0);
    if (road_path == INT_MAX || rails_path == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << max(road_path, rails_path) << endl;
    }
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}