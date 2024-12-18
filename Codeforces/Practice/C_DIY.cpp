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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> possible;
    for (int i = 0; i < n - 1;)
    {
        if (a[i] == a[i + 1])
        {
            possible.push_back(a[i]);
            i += 2;
        }
        else
        {
            i++;
        }
    }
    // for (auto e : possible)
    // {
    //     cout << e << " ";
    // }
    // cout << endl;
    pair<int, int> p1, p2, p3, p4;
    if (possible.size() >= 4)
    {
        p1.first = possible[0];
        p4.first = possible[0];
        p2.first = possible[possible.size() - 2];
        p3.first = possible[possible.size() - 2];
        p1.second = possible[1];
        p2.second = possible[1];
        p3.second = possible[possible.size() - 1];
        p4.second = possible[possible.size() - 1];
        cout << "YES" << endl;
        cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << " " << p3.first << " " << p3.second << " " << p4.first << " " << p4.second << endl;
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