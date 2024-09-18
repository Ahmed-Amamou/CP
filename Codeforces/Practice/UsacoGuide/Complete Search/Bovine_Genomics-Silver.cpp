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
    vector<string> spotty(n), plain(n);
    for (int i = 0; i < n; i++)
    {
        cin >> spotty[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> plain[i];
    }
    map<tuple<int, int, int>, set<tuple<char, char, char>>> mp;
    for (int i = 0; i < m - 2; i++)
    {
        for (int j = i + 1; j < m - 1; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                for (int p = 0; p < n; p++)
                {
                    tuple<int, int, int> key = {i,
                                                j,
                                                k};
                    mp[key].insert({spotty[p][i], spotty[p][j], spotty[p][k]});
                }
            }
        }
    }
    ll subsets = 0;
    // for (const auto &entry : mp)
    // {
    //     auto key = entry.first;
    //     auto values = entry.second;
    //     cout << "Key: (" << get<0>(key) << ", " << get<1>(key) << ", " << get<2>(key) << ") -> Values: {";
    //     for (const auto &val : values)
    //     {
    //         cout << "(" << get<0>(val) << ", " << get<1>(val) << ", " << get<2>(val) << "), ";
    //         subsets++;
    //     }
    //     cout << "}" << endl;
    // }
    // cout << "subsets: " << subsets << endl;

    //

    ll count = 0;
    for (int i = 0; i < m - 2; i++)
    {
        for (int j = i + 1; j < m - 1; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                bool flag = true;
                tuple<int, int, int> key = {i,
                                            j,
                                            k};
                for (int p = 0; p < n; p++)
                {
                    for (auto subset : mp[key])
                    {
                        if (subset == make_tuple(plain[p][i], plain[p][j], plain[p][k]))
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag)
                        break;
                }
                if (flag)
                    count++;
            }
        }
    }
    cout << count << endl;
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