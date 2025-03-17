// Author: Ahmed Amamou

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
    vector<set<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        degree[u]++;
        degree[v]++;
    }
    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 1);
    sort(nodes.begin(), nodes.end(), [&](int a, int b)
         { return degree[a] > degree[b]; });
    int u = nodes[0];
    int v = nodes[1];
    bool are_adjacent = adj[u].count(v);
    if (!are_adjacent)
    {
        cout << degree[u] + degree[v] - 1 << endl;
        return;
    }
    int max_c = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (x == u || adj[u].count(x))
            continue;
        max_c = max(max_c, degree[x]);
    }
    int max_d = 0;
    for (int x = 1; x <= n; ++x)
    {
        if (x == v || adj[v].count(x))
            continue;
        max_d = max(max_d, degree[x]);
    }
    int option1 = degree[u] + degree[v] - 2;
    int option2 = degree[u] + max_c - 1;
    int option3 = degree[v] + max_d - 1;
    cout << max({option1, option2, option3}) << endl;
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
