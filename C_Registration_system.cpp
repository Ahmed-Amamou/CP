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
map<string, ll> names;
for (int i = 0; i < n; i++)
{
    string s;
    cin >> s;
    auto it = names.find(s);
    if (it == names.end())
    {
        names[s] = 1;
        cout << "OK" << endl;
    }
    else
    {
        cout << s << it->second << endl;
        it->second++;
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