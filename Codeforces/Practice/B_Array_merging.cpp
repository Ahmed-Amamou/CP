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
void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> Asucc(2 * n + 1, 0), Bsucc(2 * n + 1, 0);

    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        Asucc[a[i]] = max(Asucc[a[i]], count);
    }
    count = 1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && b[i] == b[i - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        Bsucc[b[i]] = max(Bsucc[b[i]], count);
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        ans = max(ans, Asucc[i] + Bsucc[i]);
    }

    cout << ans << endl;
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