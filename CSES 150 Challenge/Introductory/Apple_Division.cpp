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
ll n;
ll a[20];
ll apple_division(int i, vector<bool>& visited)
{
    if (i == n)
    {
        ll g1 = 0, g2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (visited[j])
            {
                g1 += a[j];
            }
            else
            {
                g2 += a[j];
            }
        }

        return abs(g2 - g1);
    }
    visited[i] = true;
    ll ret1 = apple_division(i + 1, visited);
    visited[i] = false;
    ll ret2 = apple_division(i + 1, visited);
    return min(ret1, ret2);
}

void solve()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // We can do this in O(2^n) complexity since n<=20 (2^20 == 1 048 576 <=10^8 feasible in <1 second)
    // we can do this recursively
    vector<bool> visited(n, false); // Initialize visited vector with correct size
    ll ans = apple_division(0, visited);
    cout << ans<<endl;
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