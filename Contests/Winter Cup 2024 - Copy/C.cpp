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
    ll n;
    cin >> n;
    ll sum = 0;
    ll i = 1;
    if (n % 2 == 0)
    {
        while(i<=n-1){
            cout << "? " << i << " " << i + 1 << endl;
            cout.flush();
            int x;
            cin>> x;
            sum+=x;
            i+=2;
        }
        cout <<"! "<< sum<<endl;
        cout.flush();
    }
    else{
        while(i<=n-2){
            cout << "? " << i << " " << i + 1 << endl;
            cout.flush();
            int x;
            cin>> x;
            sum+=x;
            i+=2;
        }
        ll A,B,C;
        cout <<"? " << n-1 << " " << n << endl;
        cout.flush();
        cin >> A;
        cout <<"? " << n-2 << " " << n << endl;
        cout.flush();
        cin >> B;
        cout <<"? " << n-1 << " " << n-2 << endl;
        cout.flush();
        cin >> C;
        sum+=(A+B-C)/2;
        cout <<"! "<< sum<<endl;
        cout.flush();

    }
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