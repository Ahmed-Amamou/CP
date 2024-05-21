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
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    ll n, t;
    cin >> n >> t;
    ll a[n];
    ll sum = 0;
    int currentTime = 0, serversUsed = 0;
    for (int i = 0; i < n; i++)
    {
        cin>> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        
        if (currentTime + a[i] <= t)
        {
            currentTime += a[i];
        }
        else {
            
            if (a[i] > t)
        {
            cout << -1 << endl;
            return;
        }
            serversUsed++;
            currentTime = a[i]; // Start fresh on the new server
        }

        
    }
    cout << serversUsed +1<<endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     if(a[i]>t){
    //         cout << -1 <<endl;
    //         return;
    //     }
    //     sum+=a[i];
    // }
    // cout << (ll)ceil((double)sum/(double)t)<<endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--)
    solve();
    return 0;
}