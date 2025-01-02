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
    int k;
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        // will perform two binary searches, 1 to find closet left to r
        //  and the other to find closest right to l
        // closest left to r
        ll low = -1, high = n;
        while (high - low > 1)
        {
            ll mid = low + (high - low) / 2;
            if (a[mid] <= r)
                low = mid;
            else
                high = mid;
        }

        ll right = low;
        // debug(right);
        low = -1, high = n;
        while (high - low > 1)
        {
            ll mid = low + (high - low) / 2;
            if (a[mid] < l)
                low = mid;
            else
                high = mid;
        }
        ll left = high;
        // debug(left);

        cout << right - left + 1 << " ";
    }
    cout << endl;
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