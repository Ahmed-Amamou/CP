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
int n, x, y;
deque<int> tryThis(int diff)
{
    deque<int> v;
    for (int i = x; i <= y; i += diff)
    {
        if (v.size() == n)
            return v;
        v.push_back(i);
    }
    for (int i = x - diff; i > 0; i -= diff)
    {
        if (v.size() == n)
            return v;
        v.push_front(i);
    }
    for (int i = y + diff; i > 0; i += diff)
    {
        if (v.size() == n)
            return v;
        v.push_back(i);
    }
}
void solve()
{

    cin >> n >> x >> y;
    deque<int> bestQ;
    int mx = INT16_MAX;
    for (int i = 1; i <= y - x; i++)
    {
        deque<int> test = tryThis(i);
        sort(test.begin(), test.end());
        if (find(test.begin(), test.end(), x) != test.end() && find(test.begin(), test.end(), y) != test.end())
        {
            if (test.back() < mx)
            {
                mx = test.back();
                bestQ = test;
            }
        }
    }
    for (auto e : bestQ)
    {
        cout << e << " ";
    }
    cout << endl;
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