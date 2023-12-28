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
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    unordered_map<ll, ll> difference;
    ll even = 0, odd = 0;
    string res = "NO";
    for (ll i = 1; i <= n; i++)
    {
        if (i & 1)
            odd += a[i];
        else
            even += a[i];
        ll diff = odd - even;
        if (diff == 0 || difference.find(diff) != difference.end())
        {
            res = "YES";
            break;
        }
        difference[diff] = i;
    }
    cout << res << endl;
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