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

struct Element
{
    int value, index;
    bool operator<(const Element &other) const
    {
        return value > other.value; // For min-heap comparison
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    set<pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
            pairs.insert({-a[i], i});
    }
    ll total = 0;
    vector<pair<int, int>> res;
    while (true)
    {

        if (pairs.size() < 2)
            break;

        pair<int, int> x = *pairs.begin();
        pairs.erase(pairs.begin());
        pair<int, int> y = *pairs.begin();
        pairs.erase(pairs.begin());
        res.push_back({x.second + 1, y.second + 1});
        a[x.second]--;
        a[y.second]--;
        if (a[x.second] > 0)
            pairs.insert({-a[x.second], x.second});
        if (a[y.second] > 0)
            pairs.insert({-a[y.second], y.second});
    }
    cout << res.size() << endl;
    for (auto& p : res)
    {
        cout << p.first << " " << p.second << endl;
    }
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