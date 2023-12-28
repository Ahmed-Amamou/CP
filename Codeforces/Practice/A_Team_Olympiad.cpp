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
  int n;
  
  cin>>n;
  int a[n],count[4][n];
  for(int i=0; i<n; i++){
    cin>>a[i];
    int p1=0,p2=0,p3 =0 ;
    switch (a[i])
    {
    case 1:
        count[1][p1]=i;
        p1++;
        break;
    case 2:
        count[2][p2]=i;
        p2++;
        break;
    case 3:
        count[3][p3]=i;
        p3++;
        break;
    default:
        break;
    }
  }
  for(int j=0;j<n;j++){
    cout<<a[j]<<" ";
  }
  cout<<endl;
  for(int j=0;j<n;j++){
    cout<<count[0][j]<<" ";
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