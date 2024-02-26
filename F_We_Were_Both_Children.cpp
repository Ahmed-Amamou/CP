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
 
void solve(){
    ll n ;
    cin >> n ;
    ll a[n];
    map<ll,ll> mp;
    ll np1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i]==1){
            np1++;
            continue;
        }
        mp[(n/a[i])*a[i]]++;
    }
    mp[1]=np1;
    for (auto& pair : mp) {
        if (pair.first != 0) {
            pair.second += np1;
        }
    }
    
    
    ll maxKey = 0;
    ll maxValue = 0;
    for (const auto& pair : mp) {
        if (pair.second > maxValue) {
            maxKey = pair.first;
            maxValue = pair.second;
        }
        // cout << pair.first << ":"<< pair.second << endl;
    }
    if (maxKey==0)
        cout  << 0 <<endl;
    else cout  << maxValue <<endl;
    
    
    
    
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