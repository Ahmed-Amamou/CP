#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
 
const double EPS = 0.00000001;
const ll N = 5e5 + 20, MOD = 1e9+7;
ll n, tab[N], dp[N][2];
vector<int> adj[N];
bool vis[N][2];

 
void solve(){
 int q;
 cin >> q;
 unordered_map<ll,int> catalog;

 while (q--) {
    char c;
    ll x;
    cin >> c >> x;
    
    auto it = catalog.find(x); 
    
    switch (c) 
    {
    case 'a':
        if (it != catalog.end()) catalog[x] += 1;
        else{
            catalog[x] = 1;
        }
        break;
    
    case 't':
        if (it != catalog.end()) catalog[x] -= 1;
        break;
    case 'c':
        if (it != catalog.end()) cout << catalog[x] << endl;
        else cout << 0 << endl;
        break;
    
    default:
        break;
    }

 } 
}
 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
//   cin >> tt;
//   while (tt--) 
  solve();
  return 0;
}