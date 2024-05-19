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
    ll n, m;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    ll b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);
    // cout << "a:\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // cout << "b:\n";
    // for (int i = 0; i < m; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    ll count = 0;

    int i = 0, j = 0,min_j=0;
    
    while (i < n)
    {   j = min_j;
        while (j < m)
        {
            if (abs(a[i] - b[j]) <= 1)
            {
                count++;
                min_j = j + 1;
                break;
            }
            j++;
            
        }
        i++;
    }
    cout << count << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--)
    solve();
    return 0;
}