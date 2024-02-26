 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

int main() {
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
    FAST;
    ll n , k;
    cin >> n>>k;
    ll a[n];
    for(int i=0 ; i<n;i++  ){
        cin >> a[i];
    }
    sort(a,a+n);
    ll mx=1;
    for(int i =0;i<n-1;i++){
        ll tmp=1;
        for(int j = i+1 ; j < n ;j++)
            tmp+=a[j]-a[i]<=k?1:0;
        mx = max(mx,tmp);
    }
    // for(int i =0;i<n;i++){
    //     cout << a[i]<< " ";
    // }
    // cout << endl;
    cout << mx <<endl;  
	
}
