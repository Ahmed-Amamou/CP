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
// double intpart;
// modf(value, &intpart) == 0.0
void solve()
{
    ll a, b, l;
    cin >> a >> b >> l;
    // double max_a = log(l) / log(a);
    // double max_b = log(l) / log(b);
    ll exa = a, exb = b;
    ll x = 0;
    ll y = 0;
    while (a < l)
    {
        if (l % a == 0)
        {
            x++;
        }
        else
        {
            break;
        }
        a *= exa;
    }
    while (b < l)
    {
        if (l % b == 0)
        {
            y++;
        }
        else
        {
            break;
        }
        b *= exb;
    }
    x++;
    y++;
    set<ll> sett;
    for (int i = 0; i < x + 1; i++)
    {
        for (int j = 0; j < y + 1; j++)
        {
            int f = pow(exa, i) * pow(exb, j);
            if (f <= l && l % f == 0)
            {
                sett.insert(l / f);
            }
        }
    }
    cout << sett.size() << endl;
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