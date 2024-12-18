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

    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n < 3)
    {
        cout << 0 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    sort(a, a + n);
    vector<int> ans(n);
    int j = 0;
    for (int i = 1; i < n; i += 2)
    {
        ans[i] = a[j];
        j++;
    }
    j = n - 1;
    for (int i = (n % 2 == 0 ? n - 2 : n - 1); i >= 0; i -= 2)
    {
        ans[i] = a[j];
        j--;
    }
    ll count = 0;
    for (int i = 1; i < n - 1; i++)
    {
        count += (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]);
    }
    cout << count << endl;
    for (auto& e : ans)
    {
        cout << e << " ";
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