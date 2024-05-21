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
    int n;
    cin >> n;
    string s;

    cin >> s;
    map<char, int> mp = {{'N', 0}, {'W', 0}, {'E', 0}, {'S', 0}};
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    if (mp['N'] > mp['S'])
    {
        mp['N'] -= mp['S'];
        mp['S'] = 0;
    }
    else if (mp['N'] < mp['S'])
    {
        mp['S'] -= mp['N'];
        mp['N'] = 0;
    }
    else
    {
        mp['N'] = 0;
        mp['S'] = 0;
    }
    if (mp['W'] > mp['E'])
    {
        mp['W'] -= mp['E'];
        mp['E'] = 0;
    }
    else if (mp['W'] < mp['E'])
    {
        mp['E'] -= mp['W'];
        mp['W'] = 0;
    }
    else
    {
        mp['W'] = 0;
        mp['E'] = 0;
    }
    cout << "mp: ";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << ": " << it->second << " ";
    }
    cout << endl;
    if ((mp['E'] + mp['W'] )% 2 == 0 && (mp['N'] + mp['S']) % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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