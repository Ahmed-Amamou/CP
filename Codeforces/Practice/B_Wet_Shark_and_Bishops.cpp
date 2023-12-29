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
const ll N = 5e5 + 20, MOD = 1e9 + 7;
ll n, tab[N], dp[N][2];
vector<int> adj[N];
bool vis[N][2];



void solve()
{
    unordered_map<int, int> diag1, diag2;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x, y;
        cin >> x >> y;
        diag1[x-y]++;
        diag2[x + y]++;
    }
    ll res = 0;
    for (auto it = diag1.begin(); it != diag1.end(); ++it)
    {
        int n = it->second;
        res += n * (n - 1) / 2;
    }
    for (auto it = diag2.begin(); it != diag2.end(); ++it)
    {
        int n = it->second;
        res += n * (n - 1) / 2;
    }
    cout << res << endl;
    
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--)
    solve();
    return 0;
}