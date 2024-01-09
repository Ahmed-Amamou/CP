#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

const double EPS = 0.00000001;
const ll N = 5e5 + 20, MOD = 1e9 + 7;
ll n, tab[N], dp[N][2];
vector<int> adj[N];
bool vis[N][2];
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
  int n;
  cin >> n;
  char grid[n][n];
  for (int i = 0; i < n; i++)
  {
    cin >> grid[i];
  }

  char x = grid[0][0];
  // cout << x<<endl;
  set<char> diag;
  set<char> non_diag;

  bool flag = true;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i + j == n - 1 && i != j)
      {
        diag.insert(grid[i][j]);
        continue;
      }
      if (i == j)
      {
        diag.insert(grid[i][j]);
        continue;
      }
      non_diag.insert(grid[i][j]);
    }
  }

  // Print elements of diag
  // for (char c : diag) {
  //   cout << c << " ";
  // }
  // cout << endl;

  // // Print elements of non_diag
  // for (char c : non_diag) {
  //   cout << c << " ";
  // }
  // cout << endl;

  (diag.size() == 1 && non_diag.size() == 1) && (*diag.begin() != *non_diag.begin()) ? cout << "YES" : cout << "NO";
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