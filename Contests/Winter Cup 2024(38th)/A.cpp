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
    ll count = 0;
    ll last = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            count--;
        }
        else
        {
            count++;
        }
        if (count == -2)
        {
            cout << "1";
            count = 0;
            last = i;
            continue;
        }
        if (count == 1)
        {
            cout << "1";
            count = 0;
            last = i;
            continue;
        }
    }
    for (int i = last+1; i < n; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}