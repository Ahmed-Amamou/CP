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
{   vector<pair<int,int>> v ; 
    for (int i = 0; i < 4; i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    int x = v[0].first;
    int y = v[0].second;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first == x) {cout << (y - v[i].second)*(y - v[i].second) << endl;
        break;}
    }
    
    
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