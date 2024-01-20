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
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    int n;
    cin >> n;
    pair<ll, ll> range;
    range.first = 1;
    range.second = 1e9;
    set<ll> toberemoved;
    for (int i = 0; i < n; i++)
    {
        ll q, x;
        cin >> q >> x;
        if (q == 1 && range.first < x)
            range.first = x;
        if (q == 2 && range.second > x)
            range.second = x;
        if( q == 3 ) toberemoved.insert(x);
    }
    int count = 0;
    for (auto it = toberemoved.begin() ; it!=toberemoved.end(); it++ )
    {
        if (*it>=range.first && *it <=range.second) count ++;
    }
    if (range.second < range.first) cout << 0<<endl;
    else cout << range.second - range.first - count +1<<endl;
    
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