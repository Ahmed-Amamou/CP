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

 
// #include <cctype> // Include the necessary header file

void solve(){
    string s;
    cin>>s;
    int maj=0,mini=0;
    for(int i=0;i<s.length();i++){
        s[i] == toupper(s[i]) ? maj++ : mini++;
    }
    if(mini>=maj){
        for(int i=0;i<s.length();i++) putchar(tolower(s[i]));
    }
    else {
        for(int i=0;i<s.length();i++) putchar(toupper(s[i]));
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