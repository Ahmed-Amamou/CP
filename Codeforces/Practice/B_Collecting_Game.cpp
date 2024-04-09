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
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first, a[i].second = i;
    }
    sort(a, a + n);
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] += pref[i - 1] + a[i - 1].first;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i].first << " : " << a[i].second << " |";
    // }
    // cout << endl;
    // for (int i = 0; i < pref.size(); i++)
    // {
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    ll ans[n];
    ans[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (pref[i+1] >= a[i + 1].first)
        {
            ans[i] = ans[i + 1];
        }
        else
        {
            ans[i] = i ;
        }
    }
    ll real_ans[n];
    for (int i = 0; i < n; i++)
    {
        real_ans[a[i].second] = ans[i]; 
    }
    for (int i = 0; i < n; i++)
    {
        cout << real_ans[i]<<" ";
    }
    cout << endl;
    
    
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