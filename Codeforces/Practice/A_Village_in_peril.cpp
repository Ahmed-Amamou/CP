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
    ll a[n];
    ll pos_0 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            pos_0 = i;
    }
    if (n == 1 && a[0] == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (pos_0 == -1)
    {
        cout << 1 << endl;
        return;
    }

    ll longuest_right = 1LL;
    ll longuest_left = 1LL;
    ll amin = pos_0 + 1;
    ll k = 1;
    while (amin < n)
    {
        if (a[amin] == k)
        {
            k++;
            longuest_right++;
            amin++;
        }
        else
            break;
    }
    k = 1;
    amin = pos_0 - 1;
    while (amin >= 0)
    {
        if (a[amin] == k)
        {
            k++;
            longuest_right++;
            amin--;
        }
        else
            break;
    }
    // if (longuest_left == 1 && longuest_right==1){
    //     cout << 2 << endl;
    // }

    cout << max(longuest_left, longuest_right) + 1 << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}