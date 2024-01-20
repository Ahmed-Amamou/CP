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
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << abs(a[i + 1] - a[i]) << " " << abs(a[n - 1] - a[i]) << endl;
            continue;
        }
        if ( i == n-1)
        {
            cout << abs(a[i] - a[i-1]) << " " <<abs(a[i] - a[0]) << endl;
            continue;
        }
        cout << min(abs(a[i]-a[i+1]),abs(a[i]-a[i-1]))<<" "<< max(abs(a[n-1]-a[i]),abs(a[i] - a[0]))<<endl;
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