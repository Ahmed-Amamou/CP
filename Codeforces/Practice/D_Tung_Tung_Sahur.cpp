// Author: Ahmed Amamou

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

vector<pair<char, int>> group(const string &str)
{
    vector<pair<char, int>> groups;
    int n = str.size();
    for (int i = 0; i < n;)
    {
        char ch = str[i];
        int cnt = 0;
        while (i < n && str[i] == ch)
        {
            cnt++;
            i++;
        }
        groups.emplace_back(ch, cnt);
    }
    return groups;
}

void solve()
{
    string p, s;
    cin >> p >> s;

    vector<pair<char, int>> gp = group(p);
    vector<pair<char, int>> gs = group(s);

    if (gp.size() != gs.size())
    {
        cout << "NO" << endl;
        return;
    }

    for (int i = 0; i < gp.size(); i++)
    {
        if (gp[i].F != gs[i].F)
        {
            cout << "NO" << endl;
            return;
        }

        int min_len = gp[i].S;
        int max_len = 2 * gp[i].S;

        if (gs[i].S < min_len || gs[i].S > max_len)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
