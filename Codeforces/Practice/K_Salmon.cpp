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

class Adj
{
public:
    vector<int> adj_next = vector<int>(n);
    vector<int> adj_prev = vector<int>(n);
    vector<int> next_union_find = vector<int>(n);
    int n;
    Adj(int _n, vector<int> a)
    {
        this->n = _n;
        for (int i = 1; i < n - 1; i++)
        {
            adj_next[i] = a[i + 1];
            adj_prev[i] = a[i - 1];
            next_union_find[i] = i;
        }
        adj_next[n - 1] = -1;
        adj_prev[0] = -1;
        next_union_find[0] = 0;
        next_union_find[n - 1] = n - 1;
    }

    int get_adj(int index)
    {
        int prev = index;
        while (next_union_find[index] != prev)
        {
            prev = next_union_find[index];
            next_union_find[index] = next_union_find[next_union_find[index]];
        }
        return prev;
    }
};

void solve()
{

    int n;
    cin >> n;

    ll cnt = 0;
    int a[n];
    vector<ll> res;
    map<int, pair<int, int>> mp;
    map<int, int> deleted;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        deleted[a[i]] = 0;
    }

    if (n > 1)
    {
        mp[a[0]] = make_pair(-1, a[1]);
    }
    else
    {
        mp[a[0]] = make_pair(-1, -1);
    }

    for (int i = 1; i < n - 1; i++)
    {
        mp[a[i]] = make_pair(a[i - 1], a[i + 1]);
    }

    mp[a[n - 1]] = make_pair(a[n - 2], -1);

    for (auto it = mp.begin(); it != mp.end(); it++)
    { // left search
        deleted[it->first] = 1;
        auto prev =it->second.first;
        while (prev != -1 && deleted[prev] == 1)
        {
            prev = mp[prev].first;
            
            
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
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