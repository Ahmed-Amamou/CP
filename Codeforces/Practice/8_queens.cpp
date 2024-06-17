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
// put all queens coordinates in a vector and for each coordinate
// go through the rest of coordinates and check if they happen to be on the same col,row or diagonal.
bool same_col(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second == p2.second;
}

bool same_row(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first == p2.first;
}

bool same_diag(pair<int, int> p1, pair<int, int> p2)
{
    return abs(p1.first - p2.first) == abs(p1.second - p2.second);
}

void solve()
{
    vector<pair<int, int>> queens;
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == '*')
                queens.push_back(make_pair(i, j));
        }
    }
    if (queens.size() != 8)
    {
        cout << "invalid" << endl;
        return;
    }

    for (int i = 0; i < queens.size(); i++)
    {
        for (int j = i + 1; j < queens.size(); j++)
        {

            if (same_col(queens[i], queens[j]) || same_row(queens[i], queens[j]) || same_diag(queens[i], queens[j]))
            {
                cout << "invalid" << endl;
                // cout << queens[i].first <<","<<queens[i].second<<" - "<<queens[j].first <<","<<queens[j].second<<endl;
                return;
            }
        }
    }
    cout << "valid" << endl;
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