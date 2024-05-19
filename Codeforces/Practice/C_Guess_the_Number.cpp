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
#define debug(x) cout << #x << "-" << x << endl;
using namespace std;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    int n;
    cin >> n;
    ll lo = 1, hi = n;
    ll mid;
    while (abs(lo - hi) > 1)
    {
        mid = (lo + hi) / 2;
        // debug(lo);
        // debug(mid);
        // debug(hi);
        // debug("----");
        cout << mid << endl;
        cout.flush();

        string ele;
        cin >> ele;

        if (ele == "<")
        {
            hi = mid - 1;
        }
        else if (ele == ">=")
        {
            lo = mid;
        }
    }
    mid = (lo + hi) / 2;

    if (lo == hi)
    {
        cout << "! " << mid << endl;
        cout.flush();
        return;
    }
    else
    {
        cout << hi << endl;
        cout.flush();

        string ele;
        cin >> ele;

        if (ele == "<")
        {
            cout << "! " << lo << endl;
            cout.flush();
        }
        else if (ele == ">=")
        {
            cout << "! " << hi << endl;
            cout.flush();
        }
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