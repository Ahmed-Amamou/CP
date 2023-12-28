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
    int cnt[401]={};
    for (int i = 0; i < n; i++)
    {   int x;
        cin>>x;
        cnt[x+200]++;
    }
    // [0,0,0,1,0,2,0,0,3,0,...]
    ll sum=0;
    for(int i=0; i<401;i++){
        for (int j=i+1 ; j<401 ; j++){
            if (cnt[i]>0 && cnt[j]>0){
                // cout << sum <<endl;
                sum+=(i-j)*(i-j)*cnt[j]*cnt[i];

            }
        }
    }
    cout << sum <<endl;

    
  
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