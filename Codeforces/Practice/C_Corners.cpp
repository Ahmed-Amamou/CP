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

vector<pair<pair<int, int>, pair<int, int>>> Ls = {{{0, 1}, {-1, 1}}, {{0, -1}, {-1, -1}}, {{0, 1}, {1, 1}}, {{0, -1}, {1, -1}}, {{-1, 0}, {-1, -1}}, {{-1, 0}, {-1, 1}}, {{1, 0}, {1, -1}}, {{1, 0}, {1, 1}}};

bool valid(int i, int j, int n, int m)
{
    return i < n && i >= 0 && j < m && j >= 0;
}
bool checkMatrixAllZeros(vector<string> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == '1')
                return false;
        }
    }
    return true;
}
bool findBestL(vector<string> &matrix, int i, int j)
{
    int best = 4;
    pair<pair<int, int>, pair<int, int>> bestMove = Ls[0];
    for (auto move : Ls)
    {
        if (!valid(i + move.first.first, j + move.first.second, matrix.size(), matrix[0].size()) ||
            !valid(i + move.second.first, j + move.second.second, matrix.size(), matrix[0].size()))
            continue;
        int count = (matrix[i][j] == '0' ? 0 : 1);
        count += (matrix[i + move.first.first][j + move.first.second] == '0' ? 0 : 1);
        count += (matrix[i + move.second.first][j + move.second.second] == '0' ? 0 : 1);
        if (count < best && count >= 1)
        {
            best = count;
            bestMove = move;
        }
    }
    if (!valid(i + bestMove.first.first, j + bestMove.first.second, matrix.size(), matrix[0].size()) ||
        !valid(i + bestMove.second.first, j + bestMove.second.second, matrix.size(), matrix[0].size()))
        return false;
    matrix[i][j] = '0';
    matrix[i + bestMove.first.first][j + bestMove.first.second] = '0';
    matrix[i + bestMove.second.first][j + bestMove.second.second] = '0';
    return best != 4;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    // cout << "H" << endl;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i];
    }
    int count = 0;
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    continue;
                count += (findBestL(matrix, i, j) ? 1 : 0);
            }
        }
        if (checkMatrixAllZeros(matrix))
            break;
    }

    cout << count << endl;
}

signed main()
{
    // cout << "h"<<endl;
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}