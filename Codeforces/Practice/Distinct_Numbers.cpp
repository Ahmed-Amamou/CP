
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
  const int NMAX = 2e5 + 1;
    int n;
    cin >> n;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cnt[i];
   
    }
    sort(cnt.begin(),cnt.end());
    int res=0;
    for (int i = 0; i < n-1; i++)
    {
        if(cnt[i+1]!=cnt[i]) res+=1;
    }
    cout << res+1;
    
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

