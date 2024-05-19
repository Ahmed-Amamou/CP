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

int nCr(int n, int r)
{
    if (n < r)
        return 0;

    if (r == 0)
        return 1;

    return n * nCr(n - 1, r - 1) / r;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> inp = vector<int>(n);
    map<int, int> mp = map<int, int>();
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        inp[i] = c & x;
        if (mp.find(inp[i]) != mp.end())
        {
            mp[inp[i]]++;
        }
        else
        {
            mp[inp[i]] = 1;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        // cout << it->first << " " << it->second << endl;
        if (it->second > 1)
        {
            count += it->second * it->second;
        }
        else
        {
            count += 1;
        }
    }
    cout << count;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    solve();
    return 0;
}