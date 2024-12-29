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
int isMagicSquare(vector<vector<int>> grid, int i, int j)
{
    int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
    for (int k = i + 1; k < i + 3; k++)
    {
        if (sum != grid[k][j] + grid[k][j + 1] + grid[k][j + 2])
            return false;
    }
    for (int p = j; p < j + 3; p++)
    {
        if (sum != grid[i][p] + grid[i + 1][p] + grid[i + 2][p])
            return false;
    }
    if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum)
        return false;
    if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum)
        return false;
    return true;
}
int numMagicSquaresInside(vector<vector<int>> &grid)
{
    int cnt = 0;
    for (int i = 0; i + 2 < grid.size(); i++)
    {
        for (int j = 0; j + 2 < grid[0].size(); j++)
        {
            if (isMagicSquare(grid, i, j))
                cnt++;
        }
    }
    // cout << isMagicSquare(grid, 0, 0) << endl;
    return cnt;
}
void solve()
{
    vector<vector<int>> grid = {{4, 3, 8, 4},
                                {9, 5, 1, 9},
                                {2, 7, 6, 2}};
    cout << numMagicSquaresInside(grid) << endl;
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