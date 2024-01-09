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
// ll n, tab[N], dp[N][2];
// vector<int> adj[N];
// bool vis[N][2];
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
char grid[101][101];
int visited[101][101];
ll tt = 1;
int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool valid(int i, int j)
{
    return i < n && i >= 0 && j < n && j >= 0;
}
void dfs(int i, int j)
{
    if (visited[i][j] == 1 || grid[i][j] == '.')
        return;
    visited[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int xc = i + dx[k];
        int yc = j + dy[k];
        if (!visited[xc][yc] && valid(xc, yc) && (grid[xc][yc] == '@' || grid[xc][yc] == 'x'))
        {
            dfs(xc, yc);
        }
    }
}

signed main()
{
    FAST;

    // freopen("input.in", "r", stdin);
    cin >> tt;
    int number = 1;
    while (tt--)
    {
        int count = 0;
        cin >> n;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'x' && visited[i][j] == 0)
                {
                    dfs(i, j);

                    count++;
                    // cout << "(" << i << " , " << j << ")" << grid[i][j] << " " << count << endl;
                }
            }
        }
        cout << "Case " << number << ": " << count << endl;
        number++;
    }
    return 0;
}