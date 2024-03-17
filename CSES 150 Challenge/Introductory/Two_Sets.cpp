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
    if ((n * (n + 1) / 2) % 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES"<<endl;
    vector<ll> v1, v2;
    ll mid = (n * (n + 1) / 2) / 2;
    // cout << mid << endl;
    for (int i = n; i >= 1; i--)
    {
        if (i <= mid)
        {
            v1.push_back(i);
            mid -= i;
        }
        else{
            v2.push_back(i);
        }
    }
    cout << v1.size()<<endl;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i]<< " ";
    }
    cout << endl;
    cout << v2.size()<<endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i]<< " ";
    }
    cout << endl;
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