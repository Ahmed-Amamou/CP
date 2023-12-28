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
unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


void solve()
{
    ll diag1[2001] = {};
    ll diag2[2001] = {};
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x, y;
        cin >> x >> y;
        diag1[max(x, y) - min(x, y)]++;
        diag2[x + y]++;
    }
    ll res = 0;
    for (int i = 0; i < 2001; i++)
    {
        if (diag1[i] >= 3)
        {
            res += nChoosek(diag1[i],2);
        }
        if (diag2[i] >= 3)
        {
            res += nChoosek(diag2[i],2);
        }    
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