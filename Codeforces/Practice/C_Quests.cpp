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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int answer = 0;
    int flans = 0;
    int bmaxim = 0;
    for(int j=0;j<n;j++){
        if(k==j) break;
        answer +=a[j];
        bmaxim=max(bmaxim,b[j]);
        flans= max(answer +(k - j-1)*bmaxim,flans);
    }
    cout <<flans<<endl;

    
}
 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
  cin >> tt;
  while (tt--) solve();
  return 0;
}