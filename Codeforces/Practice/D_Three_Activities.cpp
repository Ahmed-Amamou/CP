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
void max_sum_with_no_match(int n,vector<pair<int,int>> &a1,vector<pair<int,int>> &a2 ,vector<pair<int,int>> &a3){
    sort(a1.rbegin(),a1.rend());
    sort(a2.rbegin(),a2.rend());
    sort(a3.rbegin(),a3.rend());
    int result = 0;

    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                if(a1[i].second!=a2[j].second && a1[i].second!=a3[k].second && a2[j].second!=a3[k].second){
                    result = max(result,a1[i].first+a2[j].first+a3[k].first);
                }
            }
        }
    }
    cout << result << endl;
}
 
void solve(){
  int n;
  cin >> n;
    vector<pair<int,int>> arr1(n);
    vector<pair<int,int>> arr2(n);
    vector<pair<int,int>> arr3(n);
    for(int i = 0;i<n;i++){
        cin >> arr1[i].first;
        arr1[i].second = i+1;
    }
    for(int i = 0;i<n;i++){
        cin >> arr2[i].first;
        arr2[i].second = i+1;
    }
    for(int i = 0;i<n;i++){
        cin >> arr3[i].first;
        arr3[i].second = i+1;
    }
    max_sum_with_no_match(n,arr1,arr2,arr3);

}
 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
  cin >> tt;
  while (tt--) solve();
  return 0;
}