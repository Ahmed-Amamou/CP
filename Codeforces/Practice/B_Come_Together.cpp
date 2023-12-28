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

ll manhatten_ditance(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x1 - x2) + abs(y2 - y1);
}

void solve()
{
    ll xa, ya, xb, yb, xc, yc;

    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    ll d_ab = manhatten_ditance(xa, ya, xb, yb);
    ll d_ac = manhatten_ditance(xa, ya, xc, yc);
    ll d_bc = manhatten_ditance(xb, yb, xc, yc);
    //   cout<<d_ab<<endl;
    //   cout<<d_ac<<endl;
    //   cout<<d_bc<<endl;
    cout << abs(d_ab + d_ac - d_bc) / 2 + 1 << endl;
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