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
    int x, y;
    cin >> x >> y;
    int ones_resting = x;
    int screens_G = y / 2 + y % 2;
    if (y % 2)
    { // x =8; Y =1
        if (screens_G >= 1)
        {
            ones_resting = x - ((5 * 3) * screens_G - (screens_G-1) * 8 - 4);
        }
        // cout << "x:"<< x <<endl;
        // cout << "ones_resting: " << ones_resting << endl;
        if (ones_resting > 0)
        {
            screens_G += ceil((ones_resting + (5 * 3) - 1) / (5 * 3));
        }
    }
    else
    {
        if (screens_G >= 1)
        {
            // cout << "h" << endl;
            // cout << x << endl;
            // cout << ((5 * 3) * screens_G - (screens_G) * 8) << endl;
            ones_resting = x - ((5 * 3) * screens_G - (screens_G) * 8);
        }
        // cout << "ones_resting: " << ones_resting << endl;
        if (ones_resting > 0)
        {
            screens_G += ceil((ones_resting + (5 * 3) - 1) / (5 * 3));
        }
    }
    // cout << "ones_resting: " << ones_resting << endl;
    // cout << (ll)ceil(1 / 15) << endl;
    cout << screens_G << endl;
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