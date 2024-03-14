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

// void solve(){

// }
ll combination(ll n)
{
    return (n * (n - 1)) / 2;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << 2 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 3 << endl;
            continue;
        }
        ll low = 3;
        ll high = 2648956421;
        ll res = 3;
        // for (int i = 3; i < 2648956421; i++)
        // {
        //     cout << combination(i)<<" ";
        // }
        // cout << endl;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if (combination(mid) <= n)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        ll bal = combination(res);
        ll ans = n - bal;
        cout << res + ans << endl;
    }
    return 0;
}