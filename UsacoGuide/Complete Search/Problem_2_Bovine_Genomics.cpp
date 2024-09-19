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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<set<char>> spotty(m), plain(m);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            spotty[j].insert(s[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            plain[j].insert(s[j]);
        }
    }
    // cout << "testt:" << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << "spotty ";
    //     for (char c : spotty[i])
    //     {
    //         cout << c << " ";
    //     }
    //     cout << "- plain: ";
    //     for (char c : plain[i])
    //     {
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }

    ll cnt = 0;
    for (int i = 0; i < m; i++)
    {
        // cout << "Current spotty:" << endl;

        // for (char c : spotty[i])
        // {
        //     cout << c << " ";
        // }
        // cout << endl;

        // cout << "Current plain:" << endl;

        // for (char c : plain[i])
        // {
        //     cout << c << " ";
        // }
        // cout << endl;

        if ((spotty[i].size() == 1 && plain[i].find(*spotty[i].begin()) == plain[i].end()) ||
            (plain[i].size() == 1 && spotty[i].find(*plain[i].begin()) == spotty[i].end()) ||
            (spotty[i].size() == 2 && plain[i].find(*spotty[i].begin()) == plain[i].end() && plain[i].find(*spotty[i].rbegin()) == plain[i].end()) ||
            (plain[i].size() == 2 && spotty[i].find(*plain[i].begin()) == spotty[i].end() && spotty[i].find(*plain[i].rbegin()) == spotty[i].end()))
        {
            cnt++;
            // cout << "here" << endl;
        }
    }

    cout << cnt << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}