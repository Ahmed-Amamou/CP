#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds; 

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 

#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const double EPS = 0.00000001;
const ll N = 5e5 + 20, MOD = 1e9+7;
ll n, tab[N], dp[N][2];
vector<int> adj[N];
bool vis[N][2];

 
void solve()
{
    int n ;
    cin>>n;
    vector<pair<ll,ll>>v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    ll res  =0;
    ordered_set<ll>s;
    for(int i = 0 ; i < n ; i++){
        ll k = s.order_of_key(v[i].second);
        res+=(ll)s.size()-k;
        s.insert(v[i].second);
    }
    cout<<res<<endl;
}
 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
  cin >> tt;
  while (tt--) 
  solve();
  return 0;
}