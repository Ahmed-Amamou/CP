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
    cin >> n >> m;
    int mnM[m];
    for (int i = 0; i < m; i++)
    {
        mnM[i] = 1000;
    }

    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    ll mn = 27 * m;
    ll minim;
    for (int i = 0; i < n; i++)
    {

        for (int k = i + 1; k < n; k++)
        {
            minim = 0;

            for (int j = 0; j < m; j++)
            {
                minim += abs(s[i][j] - s[k][j]);
                // cout << minim << endl;
            }
            mn = min(minim, mn);
        }

        
        // cout << "-----" << endl;
    }
    // cout << "mnM: ";
    // for (int i = 0; i < m; i++)
    // {
    //     cout << mnM[i] << " ";
    // }
    // cout << endl;

    // cout << "---" << endl;
    cout << mn << endl;
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