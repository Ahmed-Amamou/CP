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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    ll a, b, c;
    vector<ll> v;
    cin >> a >> b >> c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    bool allEqual = (adjacent_find(v.begin(), v.end(), not_equal_to<ll>()) == v.end());
    if (allEqual)
    {
        cout << "YES" << endl;
        return;
    }
    ll gcdd = gcd(gcd(a,b),c);
    ll sum = v[2]/gcdd - 1 + v[1]/gcdd - 1 +v[0]/gcdd -1;
    sum>3?cout << "NO": cout << "YES";
    cout <<endl;


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