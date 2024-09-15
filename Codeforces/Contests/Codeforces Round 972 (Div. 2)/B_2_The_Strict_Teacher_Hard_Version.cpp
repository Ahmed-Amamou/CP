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

pair<ll, ll> get_neighbors(const set<ll> &s, ll x)
{
    pair<ll, ll> result = {-1, -1};
    auto it_upper = s.upper_bound(x);
    if (it_upper != s.end())
    {
        result.second = *it_upper;
    }

    auto it_lower = s.lower_bound(x);
    it_lower--;
    result.first = *it_lower;

    return result;
}
void solve()
{
    ll n, m, q;
    cin >> n >> m >> q;
    set<ll> teachers;
    ll mx = 0, mn = 1000000002;
    for (ll i = 0; i < m; i++)
    {

        ll x;
        cin >> x;
        teachers.insert(x);
        mn = min(x, mn);
        mx = max(x, mx);
    }
    while (q--)
    {
        ll pos;
        cin >> pos;
        if (teachers.find(pos) != teachers.end())
        {
            cout << 0 << endl;
            return;
        }
        if (pos > mx)
        {
            cout << n - mx << endl;
        }
        else if (pos < mn)
        {
            cout << mn - 1 << endl;
        }
        else
        {
            pair<ll, ll> neighbors = get_neighbors(teachers, pos);
            cout << (neighbors.second - neighbors.first) / 2 << endl;
        }
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