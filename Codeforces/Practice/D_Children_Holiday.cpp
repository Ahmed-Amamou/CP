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
// t= 10s , y = 15s , z = 5
ll m, n;
ll calcul(ll t, ll z, ll y, ll X)
{
    ll fullCycles = X / (t * z + y);
    ll remainingCycle = X % (t * z + y);
    return fullCycles * z + min(z, remainingCycle / t);
}

void solve()
{
    cin >> m >> n;
    tuple<ll, ll, ll> a[n];
    for (int i = 0; i < n; i++)
    {
        ll t, z, y;
        cin >> t >> z >> y;
        a[i] = make_tuple(t, z, y);
    }
    ll l = -1;
    ll r = 1;
    vector<int> res(n, 0);
    auto ok = [&](ll X) -> bool
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            ll p = calcul(get<0>(a[i]), get<1>(a[i]), get<2>(a[i]), X);
            sum += p;
        }
        if (sum >= m)
        {
            for (int i = 0; i < n; i++)
            {
                ll p = calcul(get<0>(a[i]), get<1>(a[i]), get<2>(a[i]), X);
                res[i] = p;
            }
        }
        return sum >= m;
    };
    while (!ok(r))
    {
        r <<= 1;
    }

    while (r - l > 1)
    {
        ll mid = l + (r - l) / 2;
        // count for each person how many balloons he can inflate
        if (ok(mid))
        {
            r = mid;
        }
        else
            l = mid;
    }
    cout << r << endl;
    ll tnaf5ou = 0;
    for (auto e : res)
    {
        if (tnaf5ou + e > m)
        {
            if (m > 0)
            {
                cout << m - tnaf5ou << " ";
                m = 0;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {

            cout << e << " ";
        }
        tnaf5ou += e;
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