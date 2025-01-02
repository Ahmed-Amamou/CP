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
ll binary_search_loul(vector<int> &a, ll mx)
{
    ll low = 0;
    ll high = a.size() - 2;
    ll mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] + a[mid + 1] <= mx)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
ll binary_search_theni(vector<int> &a, ll mn)
{
    ll low = 1;
    ll high = a.size();
    ll mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // debug(mid);
        // debug(a[mid-1]);
        // debug(a[mid]);
        if (a[mid - 1] + mn <= a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        // debug(high);
        // debug(low);
    }
    return a.size() - mid;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++)
    // {

    //     cout << a[i] << " ";
    // }
    // cout << endl;
    ll mx = a[n - 1];
    ll mn = a[0];
    // we binary search to find the last i such that:  a[i]+a[i+1]<= mx ; 0<=i<=n-2;
    ll loul = binary_search_loul(a, mx);
    ll theni = binary_search_theni(a, mn);
    cout << min(loul, theni) << endl;

    // cout << res << endl;
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