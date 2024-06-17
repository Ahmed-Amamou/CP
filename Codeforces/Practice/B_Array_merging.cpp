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
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    map<int, ll> mp1, mp2; // will store longuest equal sequence in array a;
    ll count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            count++;
        }
        else
        {
            mp1[a[i - 1]] = max(count, mp1[a[i - 1]]);
            count = 1;
        }
    }
    if (count == 1)
    {
        mp1[a[n - 1]] = max(count, mp2[a[n - 1]]);
    }
    else
    {
        mp1[a[n - 1]] = max(count, mp1[a[n - 1]]);
    }
    // for (auto it : mp1)
    // {
    //     cout << it.first << ": " << it.second << endl;
    // }
    count = 1;
    for (int i = 1; i < n; i++)
    {
        if (b[i] == b[i - 1])
        {
            count++;
        }
        else
        {
            mp2[b[i - 1]] = max(count, mp2[b[i - 1]]);
            count = 1;
        }
    }
    if (count == 1)
    {
        mp2[b[n - 1]] = max(count, mp2[b[n - 1]]);
    }
    else
    {
        mp2[b[n - 1]] = max(count, mp2[b[n - 1]]);
    }
    ll mx1 = 0, mx2 = 0;
    for (auto it : mp2)
    {
        if (mp1.find(it.first) != mp1.end())
        {
            mp1[it.first] += it.second;
        }
        mx2 = max(mx2, it.second);
    }
    // cout << "-" << endl;
    // for (auto it : mp1)
    // {
    //     cout << it.first << ": " << it.second << endl;
    // }
    for (auto it : mp1)
    {

        mx1 = max(mx1, it.second);
    }
    cout << max(mx1, mx2) << endl;
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