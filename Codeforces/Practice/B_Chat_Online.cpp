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
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    set<int> Z;
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        for(int j=x; j<=y;j++){
            Z.insert(j);
        }
    }
    set<int> X;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        for(int j=x; j<=y;j++){ // Corrected the loop variable increment from 'i++' to 'j++'
            X.insert(j);
        }
    }
    
    int count = 0;
    for (int i = l; i <= r; i++) {
        for (auto it = X.begin(); it != X.end(); it++) {
            if (Z.find(*it + i) != Z.end()) {
                count++;
                break;
            }
        }
    }
    cout << count ;
}
signed main()
{
    FAST;

    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)

    solve();
    return 0;
}
