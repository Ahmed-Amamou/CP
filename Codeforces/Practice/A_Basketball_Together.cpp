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

ll bs(ll a[], ll Pmax, ll D, ll remaining)
{

    ll low = 0, high = remaining;
    ll mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // cout << mid << endl;
        if (mid * Pmax > D)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (high == remaining)
    {
        return -1;
    }
    return low;
}

void solve()
{
    ll n, D;
    cin >> n >> D;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll remaining = n;

    int j = n - 1;
    ll count = 0;
    while (true)
    {
        // take elements from biggest to smallest
        ll Pmax = a[j];
        // debug(Pmax);
        // debug(remaining);

        // perform binary search to find the smallest k 0<=k<=remaining such that Pmax * k > D
        if (remaining <= 0)
        {
            break;
        }
        ll k = bs(a, Pmax, D, remaining);
        // debug(k);
        if (k == -1)
            break;
        count++;
        remaining -= k;
        j--;
    }
    cout << count << endl;
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