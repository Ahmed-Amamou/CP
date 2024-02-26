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
    ll n, k;
    cin >> n >> k;
    ll hp[n];
    map<ll, ll> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> hp[i];
    }
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pos[abs(x)] += hp[i];
    }
    // show map
    //  for (auto it = pos.begin(); it != pos.end(); ++it) {
    //      cout << it->first << " : " << it->second << endl;
    //  }
    //  cout << "---"<<endl;
    ll sum = 0;
    for (auto &dddd : pos)
    {

        sum += dddd.second;
        dddd.second = sum;
    }

    bool res = true;
    for (auto &p : pos)
    {
        if (p.first * k < p.second)
        {
            res = false;
            break;
        }
    }

    cout << (res ? "YES" : "NO") << endl;
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