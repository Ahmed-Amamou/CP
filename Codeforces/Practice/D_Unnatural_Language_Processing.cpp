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
ll n, tab[N], dp[N][2];
vector<int> adj[N];
bool vis[N][2];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> m;
    m['a'] = 1;
    m['e'] = 1;
    string res;
    for (int i = 0; i < n; i++)
    {
        if (m[s[i]] == 1)
        {
            res.push_back(s[i]);
            int h = i + 1;
            if (h + 1 < n)
            {
                if (m[s[h]] == 0 && m[s[h + 1]] == 0)
                {
                    res.push_back(s[h]);
                    res.push_back('.');
                    i = h;
                }
                else
                    res.push_back('.');
            }
        }
        else
            res.push_back(s[i]);
    }
    cout << res << endl;
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