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
// #include "debug.h"
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
// #define debug(x) cout << #x << ": " << x << endl;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

bool compare(string الأول, string الثاني)
{
    int cnt = 0;
    for (int i = 0; i < (int)الثاني.size(); i++)
    {
        cnt += الثاني[i] != الأول[i % الأول.size()] ? 1 : 0;
        if (cnt > 1)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // cout << 'h' << endl;
    set<int> divisors;
    for (int i = 1; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    // sort(divisors.begin(), divisors.end());
    // debug(divisors);
    for (int d : divisors)
    {
        string s1, s2;
        s1 = s.substr(0, d);
        s2 = s.substr(d, d);
        // debug(s1);
        // debug(s2);
        if (compare(s1, s) || compare(s2, s))
        {
            cout << d << endl;
            break;
        }
    }
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