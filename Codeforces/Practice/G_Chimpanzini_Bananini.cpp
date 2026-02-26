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
    int q;
    cin >> q;
    deque<ll> dq;
    bool rev = false;
    ll S = 0;
    ll skibidi_rizz = 0;
    int n = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 3)
        {
            ll k;
            cin >> k;
            n++;
            S += k;
            skibidi_rizz += k * n;
            if (!rev)
            {
                dq.push_back(k);
            }
            else
            {
                dq.push_front(k);
            }
            cout << skibidi_rizz << endl;
        }
        else if (op == 1)
        {
            ll x;
            if (rev)
            {
                x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
            else
            {
                x = dq.back();
                dq.pop_back();
                dq.push_front(x);
            }
            skibidi_rizz = skibidi_rizz + S - (ll)n * x;
            cout << skibidi_rizz << endl;
        }
        else if (op == 2)
        {
            skibidi_rizz = (ll)(n + 1) * S - skibidi_rizz;
            rev = !rev;
            cout << skibidi_rizz << endl;
        }
    }
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
