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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

long long studpido(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return (abs (p1.first - p2.first)  + abs(p1.second - p2.second));
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        pair<ll, ll> x;
        cin >> x.first >> x.second;
        v.push_back(x);
    }

    for (ll i = 0; i < n; i++)
    {
        ll cnt = 0;

        for (ll j = 0; j < n; j++)
        {
            if (i != j && studpido(v[i], v[j]) <= k)
            {
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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