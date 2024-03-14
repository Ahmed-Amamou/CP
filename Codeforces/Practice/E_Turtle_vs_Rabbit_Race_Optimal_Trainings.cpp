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
ll BS(vector<ll> &v, ll l, ll u)
{
    ll low = l;
    ll high = v.size() -1 ;
    ll res = l;
    ll mn = abs((v[l] - v[l-1]) -u);
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (abs((v[mid] - v[l - 1]) - u) < mn)
        {
            res = mid;
            low = mid +1;
            mn = abs((v[mid] - v[l - 1]) - u);
        }
        else
        {
            high = mid -1;
        }
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << pref[i] << " ";
    // }
    // cout << endl;

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, u;
        cin >> l >> u;
        // if (u <= pref[l])
        // {
        //     cout << l << " ";
        //     continue;
        // }
        // cout << " l:" << l << ", u:" << u << " :";
        cout << BS(pref, l, u) << " ";
    }

    cout << endl;
    cout << "----" << endl;
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