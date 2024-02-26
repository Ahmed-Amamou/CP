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
    ll grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll local_sum = grid[i][j];
            int curr_j = j - 1, curr_i = i - 1;
            while (curr_i >= 0 && curr_i < n && curr_j >= 0 && curr_j < m)
            {
                local_sum += grid[curr_i][curr_j];
                curr_i--;
                curr_j--;
            }
            curr_j = j + 1, curr_i = i + 1;
            while (curr_i >= 0 && curr_i < n && curr_j >= 0 && curr_j < m)
            {
                local_sum += grid[curr_i][curr_j];
                curr_i++;
                curr_j++;
            }
            curr_j = j - 1, curr_i = i + 1;
            while (curr_i >= 0 && curr_i < n && curr_j >= 0 && curr_j < m)
            {
                local_sum += grid[curr_i][curr_j];
                curr_i++;
                curr_j--;
            }
            curr_j = j + 1, curr_i = i - 1;
            while (curr_i >= 0 && curr_i < n && curr_j >= 0 && curr_j < m)
            {
                local_sum += grid[curr_i][curr_j];
                curr_i--;
                curr_j++;
            }
            mx = max(mx, local_sum);
        }
    }
    cout << mx << endl;
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