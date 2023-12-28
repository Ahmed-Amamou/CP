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
    cin >> n;
    int arrA[n],arrB[n];
    for(int& i : arrA) cin >> i;
    for(int& i : arrB) cin >> i;
    vector<pair<int,int>> marbles(n);
    for(int i = 0;i<n;i++){
        marbles[i].F = arrA[i]+arrB[i];
        marbles[i].S = i;
    }
    sort(marbles.begin(),marbles.end());
    ll res= 0,q = 0;
    for(int i = n-1;i>=0;i--){
        if(q%2==0){
            res+=arrA[marbles[i].S]-1;
        }else{
            res-=arrB[marbles[i].S]-1;
        }
        q++;
    }
    cout << res << endl;
}
 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
  cin >> tt;
  while (tt--) solve();
  return 0;
}