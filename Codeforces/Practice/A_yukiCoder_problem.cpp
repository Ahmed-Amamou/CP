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
    string s;
    cin>> s;
    bool flag=false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='#' && flag!=true) {
            flag=true;
            continue;}
        if (flag==true and s[i]!='#'){
            cout<<s[i];
        }
        if (s[i]=='#' && flag==true)
            break;        
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