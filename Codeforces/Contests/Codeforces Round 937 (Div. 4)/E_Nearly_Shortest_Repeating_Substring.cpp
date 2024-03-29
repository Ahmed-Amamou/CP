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

bool compare(string s1, string s2)
{

    ll count = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s1[i % s1.size()] != s2[i])
            count++;
    }
    if (count > 1)
        return false;
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set<int> divs;

    for (int i = 1; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divs.insert(i);
            divs.insert(n/i);
        }
    }
    for (int d : divs)
    {
        string comp1 = s.substr(0, d);
        string comp2 = s.substr(d, d);
        if(compare(comp1,s) ||compare(comp2,s)){
            cout << d << endl;
            return;
        }
    }
    cout << endl;
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