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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //two prefix sums that calculate the sum of the odd and even elements respectively
    vector<int> odd(n+1, 0), even(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        odd[i+1] = odd[i];
        even[i+1] = even[i];
        if (i%2==0) even[i+1] += a[i];
        else odd[i+1] += a[i];
    }
    //find if there exists a subarray with same bounds for odd and even where odd[r+1]-odd[l-1] == even[r+1]-even[l-1]
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (odd[i+1] == even[i+1]){ found = true; break;}
        for (int j = i+2; j < n; j++)
        {
            if (odd[j+1]-odd[i] == even[j+1]-even[i]) {found = true; break;}
        
        }
    }
    if (found)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}    
//     if (found)
//         cout << "YES" << endl;
//     else
//         cout << "NO" << endl;
// }
    


 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
  cin >> tt;
  while (tt--) 
  solve();
  return 0;
}
