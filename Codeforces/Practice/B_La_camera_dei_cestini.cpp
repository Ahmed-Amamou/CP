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
    // n: objects; m: baskets; q: queries
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> v(m); // Initialize vector v with the correct size
    vector<int> vv(n);        // Initialize vector vv with the correct size
    for (int i = 0; i < n; i++)
    {
        vv[i] = i;
    }
    v[0] = vv;

    int ele;
    while (q--)
    {
        char query;
        int a, b;
        cin >> query >> a >> b;
        switch (query)
        {
        case 's':
            ele = v[a].back();
            v[a].pop_back();
            v[b].push_back(ele);
            break;

        case 'c':
            if (v[a].size() - 1 < b)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << v[a][b] << endl;
            }
            break;
        default:
            break;
        }
    }
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