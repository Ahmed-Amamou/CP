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
    int n, k;
    cin >> n >> k;
    vector<pair<vector<int>, ll>> a(n);
    a[0].second = 0;
    a[n - 1].second = 0;
    for (int i = 1; i < n - 1; i++)
    {
        cin >> a[i].second;
    }
    for (int i = 1; i < n; i++)
    {
        ll mx = INT32_MAX * -1;
        ll index = -1;
        for (int j = max(i - k, 0); j < i; j++)
        {
            if (mx < a[j].second)
            {
                mx = a[j].second;
                index = j;
            }
        }
        a[i].first = a[index].first;
        a[i].first.push_back(index + 1);
        a[i].second += a[index].second;
    }

    cout << a[n - 1].second << endl;
    cout << a[n - 1].first.size() << endl;
    for (auto it : a[n - 1].first)
    {
        cout << it << " ";
    }
    cout << n << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}