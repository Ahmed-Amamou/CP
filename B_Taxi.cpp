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
    int a[n];
    int occurence[5] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        occurence[a[i]]++;
    }
    ll ans = occurence[4];

    if (occurence[3] > occurence[1])
    {
        ans += occurence[3];
        occurence[1] = 0;
    }
    else
    {
        ans += occurence[3];
        occurence[1] -= occurence[3];
    }
    // cout << ans <<endl;
    if (occurence[1] == 0)
    {
        ans += (int)ceil(occurence[2] / (double)2);
    }
    
    else
    {
        ans += occurence[2] / 2;
        occurence[2] -= 2*(occurence[2] / 2);
        if (occurence[2] && occurence[1] >= 2)
        {
            ans += 1;
            occurence[1] -= 2;
        }
        // cout << ans <<endl;
        if (occurence[1] > 0)
        {
            ans += (int)ceil((double)(occurence[1]) / (double)4);
        }
    }
    cout << ans << endl;
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