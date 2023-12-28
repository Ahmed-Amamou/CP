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
    ll k;
    cin >> n >> k;
    map<ll, ll> cheese;
    for (int i = 0; i < n; i++)
    {
        ll A, B;
        cin >> A >> B;
        cheese[A] = B;
    }
    ll res=0;
    // Iterate through the map from the last element to the first
    for (auto it = cheese.rbegin(); it != cheese.rend(); ++it)
    {
        ll key = it->first;
        ll value = it->second;
        if (k <= 0) break; // Added condition to break the loop if k is less than or equal to 0
        if (k < value) {
            res += key * k;
            break;
        }
        else {
            res += key * value;
            k -= value;
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