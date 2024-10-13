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

void solve(int tt)
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    float borne_inf = 0, borne_sup = 100000000;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (((i + 1) * 1.0) / y > borne_inf)
        {
            borne_inf = ((i + 1) * 1.0) / y;
        }
        if (((i + 1) * 1.0) / x < borne_sup)
        {
            borne_sup = ((i + 1) * 1.0) / x;
        }
    }
    if (borne_inf > borne_sup)
    {
        cout << "Case #" << tt << ": " << -1 << endl;
    }
    else
    {
        cout << "Case #" << tt << ": " << borne_inf << endl;
    }
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("Afinal.txt", "w", stdout);
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve(i);
    return 0;
}