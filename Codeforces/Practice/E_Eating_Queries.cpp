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
int bs(vector<ll>& pref, int x)
{
    ll low = 0, high = pref.size() - 1;
    ll res = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (pref[mid] >= x)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<ll>());
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << pref[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        // cout << x << ": ";
        cout << bs(pref, x) << endl;
    }
    // cout << "---" << endl;
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