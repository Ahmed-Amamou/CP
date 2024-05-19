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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = 1;
    if (a[n - 1] < 0)
    {
        for (int i = 0; i < 5; i++)
        {
            res *= a[i];
        }
        cout << res << endl;
    }
    else if (a[n - 1] == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        res = a[n - 1];
        n -= 1;
        int count = 1;
        int k = 0;
        while (count < 5)
        {
            if (a[n - 1] * a[n - 2] >= a[k] * a[k + 1])
            {
                // cout << "a li5ra " << a[n - 1] << endl;
                res *= a[n - 1] * a[n - 2];
                a.pop_back();
                a.pop_back();
                n -= 2;
            }
            else
            {
                res *= a[k] * a[k + 1];
                k += 2;
            }
            count+=2;
        }
        cout << res << endl;
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