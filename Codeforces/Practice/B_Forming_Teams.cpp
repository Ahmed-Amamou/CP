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
int numOddCycles = 0;
void dfs(int node, int parent, int depth, const vector<vector<int>> &adj, vector<int> &visited, vector<int> &depthArray)
{
    visited[node] = 1;
    depthArray[node] = depth;

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, node, depth + 1, adj, visited, depthArray);
        }
        else if (neighbor != parent && depthArray[node] > depthArray[neighbor])
        {

            if ((depthArray[node] - depthArray[neighbor]+1) % 2)
            {
                numOddCycles += 1;
            }
        }
    }
}

int countOddLengthCycles(const vector<vector<int>> &adj, int n)
{
    vector<int> visited(n + 1, 0);
    vector<int> depthArray(n + 1, -1);
    vector<int> parentArray(n + 1, -1);
    int oddCycles = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, -1, 0, adj, visited, depthArray);
        }
    }

    return numOddCycles;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    // cout << "test"<<endl;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // Detect the number of odd cycles in the graph
    int odd_cycles = countOddLengthCycles(adj, n);
    if ((n - odd_cycles) % 2)
    {
        cout << odd_cycles + 1 << endl;
    }
    else
    {
        cout << odd_cycles << endl;
    }
}

signed main()
{
    FAST;

    ll tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}