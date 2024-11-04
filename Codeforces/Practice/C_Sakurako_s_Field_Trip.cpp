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
// function that calculates disturbence
ll disturbence(vector<ll> &v)
{
    ll count = 0LL;
    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] == v[i - 1])
        {
            ++count;
        }
    }
    return count;
}
// function that returns neighboring elements
set<ll> getNeighbors(int i, vector<ll> &v)
{
    set<ll> neighbors;
    if (i > 0)
    {
        if (!((v.size() % 2 == 0) && (i - 1 != v.size() / 2)))
            neighbors.insert(v[i - 1]);
    }
    if (i < v.size() - 1)
    {
        if (!((v.size() % 2 == 0) && (i + 1 != v.size() / 2)))
            neighbors.insert(v[i + 1]);
    }
    return neighbors;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    for (int i = 1; i < n / 2; i++)
    {
        if (a[i] == a[i - 1] || a[n - i ] == a[n - i - 1])
        {
            swap(a[i], a[n - i - 1]);
        }
    }
    ll count = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
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