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
    int n;
    cin >> n;
    ll a[n];
    ll res = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (count(a, a + n, 1) != 0)
    {
        ll pos = -1;
        bool first = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1 && first == false)
            {
                first = true;
                pos = i;
            }
            else if (a[i] == 1 && first == true)
            {
                res *= (i - pos);
                pos = i;
            }
            // cout << res << endl;
        }
    }
    else
    {
        res = 0;
    }
    cout << res;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--) solve();
    solve();
    return 0;
}