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
bool possible(vector<ll> &pos, int distance, int cows)
{
    int last = 0;
    int count = 1;
    for (int i = 1; i < pos.size(); i++)
    {
        if (pos[i] - pos[last] >= distance)
        {
            count++;
            last = i;
        }
        if (count >= cows)
            return true;
    }
    return false;
}

void solve()
{
    ll n, cows;
    cin >> n >> cows;
    vector<ll> pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    // for (ll &a : pos)
    // {
    //     cout << a << " ";
    // }
    // cout << endl;
    int low = 1, high = pos[n - 1] - pos[0];
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (possible(pos, mid, cows))
        {
            low = mid + 1;
            // cout << mid <<endl;
        }
        else
        {
            high = mid - 1;
            // cout << mid << endl;
        }
    }
    cout << high << endl;
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