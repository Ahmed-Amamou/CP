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
    map<ll, double> mp;
    for (ll i = 1; i <= n; i++)
    {
        mp[i] = 0.0;
    }
    for (int i = 0; i < n; i++)
    {
        ll q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            ll x;
            cin >> x;
            mp[x]++;
        }
    }
    vector<pair<ll, double>> ans;
    for (auto it : mp)
    {
        // cout << ((n * 1.0) / 2) << endl;
        // cout << "---" << endl;
        // cout << it.first << " " << it.second << endl;
        if (it.second > ((n * 1.0) / 2))
        {
            ans.push_back(make_pair(it.first, (it.second * 1.0) / n));
        }
    }

    // cout << "answerarray " << endl;
    // for (auto it : ans)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it.first << " ";
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