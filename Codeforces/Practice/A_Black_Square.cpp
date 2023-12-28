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
    int a[6];
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i + 1];
    }
    string s;
    cin >> s;
    // cout << s << endl;
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << s[i] - '0' << endl;
        sum += a[s[i] - '0'];
    }
    cout << sum;
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