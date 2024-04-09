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
    string s;
    cin >> s;
    pair<int, char> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first, a[i].second = s[i];
    }
    ll mn = 1e9+1;
    bool flag1 = false;
    bool flag2 = false;
    ll pos1, pos2;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second == 'R')
        {
            // cout << "R: "<<a[i].first<<endl;
            pos1 = a[i].first;
            flag1 = true;
        }
        if (a[i].second == 'L' && flag1 == true)
        {
            // cout << "L: "<<a[i].first<<endl;
            pos2 = a[i].first;
            flag2 = true;
        }
        if (flag1 && flag2)
        {
            // cout << pos1 << " " << pos2 << endl;
            mn = min((pos1 + (pos2 - pos1) / 2) - pos1, mn);
            flag1 = flag2 = false;
        }
    }
    cout << (mn==1e9+1?-1:mn) << endl;
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