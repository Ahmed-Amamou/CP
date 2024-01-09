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
    ll a[100000];
    a[0] = 0;
    ll energy = 0;
    ll money = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }
    
    // Sort the array in ascending order
    // sort(a, a + n + 1);

    cout<<a[n]<<endl;
    
    // Rest of the code...
}

signed main()
{
    FAST;
    // freopen("input.in", "r", stdin);
    //   while (tt--)
    solve();
    return 0;
}