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
int ans = 0;
bool diag1[15], diag2[15], col[15];
string reserved[8];
void queens(int column)
{
    if (column == 8)
    {
        ans++;
        return;
    }
    for (int row = 0; row < 8; row++)
    {
        if (diag1[row + column] || diag2[row - column + 7] || col[row] || reserved[row][column] == '*')
        {
            continue;
        }
        col[row] = diag1[row + column] = diag2[row - column + 7] = true;
        queens(column + 1);
        col[row] = diag1[row + column] = diag2[row - column + 7] = false;
    }
}

void solve()
{
    
    for (int i = 0; i < 8; i++)
    {
        cin >> reserved[i];
    }
    memset(diag1, false, 15);
    memset(diag2, false, 15);
    memset(col, false, 15);
    queens(0);
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