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
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    sort(b.begin(), b.end());

    const long long INF = 1LL << 60;

    long long candidateNotFlip = a[0];
    long long candidateFlip = b[0] - a[0];
    long long dp = min(candidateNotFlip, candidateFlip);
    for (int i = 1; i < n; i++)
    {
        long long new_dp = INF;

        if (a[i] >= dp)
            new_dp = min(new_dp, a[i]);

        long long need = dp + a[i];
        auto it = lower_bound(b.begin(), b.end(), need);
        if (it != b.end())
        {
            long long candidate = *it - a[i];
            new_dp = min(new_dp, candidate);
        }

        dp = new_dp;
        if (dp == INF)
            break;
    }

    cout << (dp == INF ? "NO" : "YES") << "\n";
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