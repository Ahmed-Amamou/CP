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
string s, t;
vector<bool> presence;

bool verify(string s, string t, int mid)
{
    if (t.size() > (s.size() - mid - 1))
        return false;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {

        if (t[count] == s[i] && presence[i])
            count++;
    }
    if (count >= t.size())
        return true;
    else
        return false;
}
void solve()
{
    cin >> s >> t;
    int n = s.size();
    presence.resize(n, true);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = -1, r = n;

    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        // debug(l);
        // debug(r);
        // debug(mid);
        for (int i = 0; i <= mid; i++)
        {
            presence[a[i] - 1] = false;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << presence[i] << " ";
        // }
        // cout << endl;
        if (verify(s, t, mid))
        {
            l = mid;
        }
        else
            r = mid;
        for (int i = 0; i < n; i++)
        {
            presence[i] = true;
        }
    }
    cout << l + 1 << endl;
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