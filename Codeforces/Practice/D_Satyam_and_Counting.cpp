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

void solve()
{
    int n;
    cin >> n;
    set<pair<int, int>> poinet;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> point;
        cin >> point.first >> point.second;
        poinet.insert(point);
    }

    set<int> horizontals; // defined by their x
    for (auto it : poinet)
    {
        pair<int, int> test1 = make_pair(it.first, 0);
        pair<int, int> test2 = make_pair(it.first, 1);

        if ((it.second == 1 && poinet.find(test1) != poinet.end()) || (it.second == 0 && poinet.find(test2) != poinet.end()))
        {
            horizontals.insert(it.first);
        }
    }

    ll count = 0;
    count += horizontals.size() * (poinet.size() - 2);

    for (auto it : poinet)
    {
        if (it.second == 0 && poinet.find({it.first - 1, 1}) != poinet.end() && poinet.find({it.first + 1, 1}) != poinet.end())
            count++;

        if (it.second == 1 && poinet.find({it.first - 1, 0}) != poinet.end() && poinet.find({it.first + 1, 0}) != poinet.end())
            count++;
    }
    cout << count << endl;
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