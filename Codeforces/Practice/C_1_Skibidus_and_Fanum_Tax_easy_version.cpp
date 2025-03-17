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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int b_val = b[0];

    if (n == 1)
    {
        cout << "YES\n";
        return;
    }

    bool prev_not = true, prev_flip = true;

    for (int i = 1; i < n; i++)
    {
        int current_not = a[i];
        int current_flip = b_val - a[i];
        bool new_not = false, new_flip = false;

        if (prev_not && a[i - 1] <= current_not)
            new_not = true;
        if (prev_flip && (b_val - a[i - 1]) <= current_not)
            new_not = true;
        if (prev_not && a[i - 1] <= current_flip)
            new_flip = true;
        if (prev_flip && (b_val - a[i - 1]) <= current_flip)
            new_flip = true;

        prev_not = new_not;
        prev_flip = new_flip;

        if (!prev_not && !prev_flip)
            break;
    }

    cout << (prev_not || prev_flip ? "YES\n" : "NO\n");
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