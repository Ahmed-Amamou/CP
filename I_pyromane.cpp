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
    ll x[n], y[n];
    vector<pair<double,ll>> a; 
    for (int i = 0; i < n; i++)
    {   
        cin >> x[i];
        
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    for (int i = 0; i < n; i++)
    {   ll goodness;
        cin >> goodness;
        a.push_back(make_pair((sqrt((double)x[i]*x[i]+(double)y[i]*y[i])),goodness));

    }
    sort(a.begin(),a.end());
//    cout << "a" << endl;
    
    // for (auto& p : a) {
    //     cout << p.first << " " << p.second << endl;
    // }
    ll mx =0; 
    ll pref[n+1];
    pref[0]=0;
    for (int i = 1; i < n+1; i++)
    {
        pref[i] = pref[i-1] + a[i-1].second;
        mx = max(mx,pref[i]);
    }
//    cout << "Pref array: ";
//    for (int i = 0; i < n+1; i++) {
//        cout << pref[i] << " ";
//    }
//    cout << endl;
   cout << mx <<endl;
    
    
    
    
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