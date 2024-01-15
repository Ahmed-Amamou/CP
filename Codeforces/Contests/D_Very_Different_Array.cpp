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
    ll n, m;
    cin >> n >> m;
    ll a[n], b[m];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    ll pref_a[n];
    ll pref_b[m];
    for (ll i = 0; i < n; i++)
    {
        if (i == 0)
            pref_a[i] = a[i];
        else
            pref_a[i] = a[i] + pref_a[i - 1];
    }
    for (ll i = 0; i < m; i++)
    {
        if (i == 0)
            pref_b[i] = b[i];
        else
            pref_b[i] = b[i] + pref_b[i - 1];
    }
    ll suff_a[n];
    ll suff_b[m];
    for (ll i = n-1; i >=0; i--)
    {
        if(i == n-1) suff_a[i] = a[i];
        else suff_a[i] = a[i] + suff_a[i+1];
    }
    for (ll i = m-1; i >=0; i--)
    {
        if(i == m-1) suff_b[i] = b[i];
        else suff_b[i] = b[i] + suff_b[i+1];
    }
    ll ans = -1;
    for (ll i = 0; i <= n; i++)
    {
        ll nuna=i;
        ll nana=n-i;
        ll nunb=n-i;
        ll nanb=i;
        ll sum=0;
        if(i == 0) sum=suff_b[m-nunb]-pref_a[n-1];
        else if(i == n) sum=suff_a[0]-pref_b[n-1];
        else sum=suff_a[n-nuna]+suff_b[m-nunb]-pref_a[nana-1]-pref_b[nanb-1];
        ans=max(ans,sum);
    }
    cout << ans << endl;
    
    
    
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