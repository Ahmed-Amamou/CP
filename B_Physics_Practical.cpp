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

void solve()
{
}

signed main()
{
    FAST;
    ll tt = 1;
    ll n;
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if (n == 2 && (a[1] * 1.0 / a[0]) > 2.0)
    {
        cout << 1 << endl;
        return 0;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for each element we calculate it's best pairing that gets the minimum elements
    // to be removed using binary search
    ll mn = n;
    for (int i = 0; i < n - 1; i++)
    {
        ll low = i + 1, high = n - 1;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            if ((a[mid] * 1.0 / a[i]) <= 2.0)
            {
                mn = min(mn, i + n - 1 - mid);
                low = mid + 1;
                // cout <<"i:" <<i<<" |"<<mid << endl;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    cout << mn;
    return 0;
}