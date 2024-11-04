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
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    int sum = 0;
    bool visited[1005][1005];
    int n, m;
    bool valid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        // cout << "test" << endl;
        visited[i][j] = true;
        sum += grid[i][j];

        for (int k = 0; k < 4; k++)
        {
            if (valid(i + dx[k], j + dy[k]) && !visited[i + dx[k]][j + dy[k]] && grid[i + dx[k]][j + dy[k]] > 0)
            {
                dfs(grid, i + dx[k], j + dy[k]);
            }
        }
        return sum;
    }

    void solve()
    {

        cin >> n >> m;
        // cout << "-----" << endl;

        memset(visited, false, sizeof(visited));
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j]>0)
                {
                    mx = max(dfs(grid, i, j), mx);
                    sum = 0;
                }
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