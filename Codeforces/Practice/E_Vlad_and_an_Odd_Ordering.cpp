/*
 ▄▀▀▄ ▄▄   ▄▀▀█▄   ▄▀▀▄ ▄▀▄  ▄▀▀▀▀▄   ▄▀▀▀▀▄   ▄▀▀█▄▄  
█  █   ▄▀ ▐ ▄▀ ▀▄ █  █ ▀  █ █      █ █      █ █ ▄▀   █ 
▐  █▄▄▄█    █▄▄▄█ ▐  █    █ █      █ █      █ ▐ █    █ 
   █   █   ▄▀   █   █    █  ▀▄    ▄▀ ▀▄    ▄▀   █    █ 
  ▄▀  ▄▀  █   ▄▀  ▄▀   ▄▀     ▀▀▀▀     ▀▀▀▀    ▄▀▄▄▄▄▀ 
 █   █    ▐   ▐   █    █                      █     ▐  
 ▐   ▐            ▐    ▐                      ▐        
*/


#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;


const double EPS = 0.00000001;
const ll MOD = 1e9+7;
int gcd (ll a, ll b) { return b ? gcd (b, a % b) : a;}
int lcm (int a, int b) { return a * (b / gcd(a, b));}
// vector<vector<int>> dp(n+1, vector<int>(n+1));
void solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0; i < n/2+1; i++){
        dp[0][i] = 2 * i + 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n/2; j++){
            if(dp[i-1][j] * 2<n)
                dp[i][j] = dp[i-1][j] * 2;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
        
    }
    cout << "---"<<endl;
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
 