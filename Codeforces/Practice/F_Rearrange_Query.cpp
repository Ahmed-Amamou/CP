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
// Permutation Hashing Technique (using 5 random values for each element in the permutation)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}

struct PermutationHashing
{
    ll a, b, c, d, e;
    PermutationHashing(ll aa, ll bb, ll cc, ll dd, ll ee)
    {
        a = aa;
        b = bb;
        c = cc;
        d = dd;
        e = ee;
    }
    PermutationHashing()
    {
        a = rand(1, 1e9);
        b = rand(1, 1e9);
        c = rand(1, 1e9);
        d = rand(1, 1e9);
        e = rand(1, 1e9);
    }
    // override operators needed for prefix sum
    PermutationHashing operator+(PermutationHashing other)
    {
        return PermutationHashing(a + other.a, b + other.b, c + other.c, d + other.d, e + other.e);
    }
    PermutationHashing operator-(PermutationHashing other)
    {
        return PermutationHashing(a - other.a, b - other.b, c - other.c, d - other.d, e - other.e);
    }
    bool operator==(PermutationHashing other)
    {
        return (a == other.a, b == other.b, c == other.c, d == other.d, e == other.e);
    }
};
void solve()
{
    ll n, q;
    cin >> n >> q;
    PermutationHashing x[n + 1], y[n + 1];
    map<ll, PermutationHashing> mp;
    x[0] = y[0] = PermutationHashing(0, 0, 0, 0, 0);
    for (ll i = 1; i <= n; i++)
    {
        ll p;
        cin >> p;
        if (mp.find(p) == mp.end())
        {
            mp[p] = PermutationHashing();
        }
        x[i] = x[i - 1] + mp[p];
    }
    for (ll i = 1; i <= n; i++)
    {
        ll p;
        cin >> p;
        if (mp.find(p) == mp.end())
        {
            mp[p] = PermutationHashing();
        }
        y[i] = y[i - 1] + mp[p];
    }

    // for (const auto &pair : mp)
    // {
    //     cout << "Key: " << pair.first << " -> Value: (" << pair.second.a << ", " << pair.second.b << ", " << pair.second.c << ", " << pair.second.d << ", " << pair.second.e << ")" << endl;
    // }
    // cout << "x: ";
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << "(" << x[i].a << ", " << x[i].b << ", " << x[i].c << ", " << x[i].d << ", " << x[i].e << ") ";
    // }
    // cout << endl;

    // cout << "y: ";
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << "(" << y[i].a << ", " << y[i].b << ", " << y[i].c << ", " << y[i].d << ", " << y[i].e << ") ";
    // }
    // cout << endl;
    while (q--)
    {
        ll l, r, L, R;
        cin >> l >> r >> L >> R;
        // cout << "x[" << r << "] - x[" << l << "]: (" << (x[r] - x[l]).a << ", " << (x[r] - x[l]).b << ", " << (x[r] - x[l]).c << ", " << (x[r] - x[l]).d << ", " << (x[r] - x[l]).e << ") | ";
        // cout << "y[" << R << "] - y[" << L << "]: (" << (y[R] - y[L]).a << ", " << (y[R] - y[L]).b << ", " << (y[R] - y[L]).c << ", " << (y[R] - y[L]).d << ", " << (y[R] - y[L]).e << ") ";
        if ((x[r] - x[l-1]) == (y[R] - y[L-1]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
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