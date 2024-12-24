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
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

void solve()
{
    int n;
    cin >> n;
    ll a[n];
    set<ll> ss;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ss.insert(a[i]);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    sort(a, a + n);
    ll mx = a[n - 1];
    ll best = 0;
    // cout << best << " lina" << endl;
    for (int i = 0; i < n - 1; i++)
    {

        best = abs(gcd(best, mx - a[i]));
    }
    int i = 1;
    ll zambala;
    while (true)
    {
        if (ss.count(mx - best * i))
            i++;
        else
        {
            zambala = mx - best * i;
            break;
        }
    }
    // cout << zambala << endl;
    ll sum = (mx - zambala) / best;
    for (int i = 0; i < n - 1; i++)
    {
        sum += (mx - a[i]) / best;
    }
    cout << sum << endl;
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