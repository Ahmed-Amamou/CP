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

void dfs(vector<vector<vector<int>>> &graph, vector<bool> &visited, int c, int u)
{
    visited[u] = true;
    for (auto x : graph[c][u])
    {
        if (!visited[x])
            dfs(graph, visited, c, x);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> graph(m, vector<vector<int>>(n));
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        c--;
        graph[c][u].push_back(v);
        graph[c][v].push_back(u);
    }
    // for (int c = 0; c < m; c++)
    // {
    //     cout << "Graph for c = " << c << ":" << endl;
    //     for (int u = 0; u < n; u++)
    //     {
    //         cout << "Node " << u << ": ";
    //         for (int v : graph[c][u])
    //         {
    //             cout << v << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int cnt = 0;
        for (int c = 0; c < m; c++)
        {
            vector<bool> visited(n, false);
            dfs(graph, visited, c, u);
            if (visited[v])
                cnt++;
        }
        cout << cnt << endl;
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