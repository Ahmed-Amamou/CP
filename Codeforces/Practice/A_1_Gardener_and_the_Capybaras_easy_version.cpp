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
#define debug(x) cout << #x << ": " << x << endl;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
bool isLexicographicallySmaller(string x, string y)
{
    int n = min(x.size(), y.size());
    for (int i = 0; i < n; ++i)
    {
        if (x[i] != y[i])
        {
            return x[i] < y[i];
        }
    }
    return x.size() <= y.size();
}
bool isLexicographicallyBigger(string x, string y)
{
    int n = min(x.size(), y.size());
    for (int i = 0; i < n; ++i)
    {
        if (x[i] != y[i])
        {
            return x[i] > y[i];
        }
    }
    return x.size() >= y.size();
}
void solve()
{
    string s;
    cin >> s;
    string a, b, c;
    for (int i = 1; i < s.size() - 1; ++i)
    {
        for (int j = i + 1; j < s.size(); ++j)
        {
            a = s.substr(0, i);
            b = s.substr(i, j - i);
            c = s.substr(j);
            if ((isLexicographicallySmaller(a, b) && isLexicographicallySmaller(c, b)) || (isLexicographicallyBigger(a, b) && isLexicographicallyBigger(c, b)))
            {
                cout << a << " " << b << " " << c << endl;
                return;
            }
        }
    }
    cout << ":(" << endl;
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