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
const ll N = 5e5 + 20, MOD = 1e9 + 7;
vector<int> adj[N];
bool vis[N][2];
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
bool visited[9][9];
char grid[9][9];
int n, m;
int dy[3] = {1, -1, 0};
int dx[3] = {0, 0, -1};
string response[3] = {"right", "left", "forth"};

bool valid(int i, int j)
{
    return i < m && i >= 0 && j < n && j >= 0;
}

unordered_map<char, char> path = {{'@', 'I'}, {'I', 'E'}, {'E', 'H'}, {'H', 'O'}, {'O', 'V'}, {'V', 'A'}, {'A', '#'}};

void dfs(int i, int j,vector<string>& res )
{   if (grid[i][j]=='#') return;
    for (int k = 0; k < 3; k++)
    {
        int xc = i + dx[k];
        int yc = j + dy[k];
        // cout << xc << " " << yc << endl;
        // cout << grid[xc][yc] << endl;
        if (valid(xc,yc) && grid[xc][yc] == path[grid[i][j]] )
        {   res.push_back(response[k]);
            dfs(xc, yc,res);
        }
    }
}

void solve()
{
    cin >> m >> n;
    char start = '@';
    pair<int, int> start_pos;
    vector<string> res; 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == start)
            {
                start_pos = make_pair(i, j);
            }
        }
    }
    dfs(start_pos.first, start_pos.second, res);
     for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) {
            cout << " "; // Add space between responses if not the last one
        }
    }
    cout << endl;
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