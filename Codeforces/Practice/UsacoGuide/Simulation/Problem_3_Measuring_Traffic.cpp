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
    int n;
    cin >> n;
    vector<pair<string, pair<int, int>>> highway;
    for (int i = 0; i < n; i++)
    {
        string s;
        int l, r;
        cin >> s >> l >> r;
        if (i != 0 && highway.back().first == "none" && s == "none")
        {

            highway.back().second.first = max(l, highway.back().second.first);
            highway.back().second.second = min(r, highway.back().second.second);
        }
        else
        {
            highway.push_back(make_pair(s, make_pair(l, r)));
        }
    }

    int l_diff = 0, r_diff = 0;
    for (auto e : highway)
    {
        if (e.first == "none")
        {
            cout << e.second.first - r_diff << " " << e.second.second - l_diff << endl;
            break;
        }
        else if (e.first == "on")
        {
            l_diff += e.second.first;
            r_diff += e.second.second;
        }
        else
        {
            l_diff -= e.second.first;
            r_diff -= e.second.second;
            r_diff = max(r_diff, 0);
        }
    }
    l_diff = 0, r_diff = 0;
    for (auto it = highway.rbegin(); it != highway.rend(); it++)
    {
        if (it->first == "none")
        {
            cout << it->second.first - r_diff << " " << it->second.second - l_diff << endl;
            break;
        }
        else if (it->first == "off")
        {
            l_diff += it->second.first;
            r_diff += it->second.second;
        }
        else
        {
            l_diff -= it->second.first;
            r_diff -= it->second.second;
            
        }
    }
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("traffic.in", "r", stdin);
    // freopen("traffic.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}