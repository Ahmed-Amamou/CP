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
// a b c d
// d a b c
// string rotate(string s)
// {
//     int n = s.length();
//     char last = s[n - 1];
//     // cout<<last<<endl;
//     for (int i = n - 1; i > 0; --i)
//     {
//         s[i] = s[i - 1];
//         // cout<<i<<endl;
//     }
//     s[0] = last;
//     return s;
// }
// a b c
// c a b

void solve()
{
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    // cout << rotate(s);

    while (q--)
    {
        int d, x, pos;
        pos = 0;
        cin >> d >> x;
        // cout<<pos<<endl;
        if (d == 1)
        {
            pos = pos + x;
        }
        else cout << s[(n + x - pos - 1) % n] << endl;
    }
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