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

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    ll x;
    cin >> x;
    long long ans[13] = {-1};
    long long i = 0;
    long long neg = x < 0 ? -1 : 1;
    if (x == 0)
    {
        cout << 0;
        return;
    }
    x = abs(x);
    bool flag = false;
    while (x)
    {
        if (flag == false && x % 10 == 10)
        {
            continue;
            x /= 10;
        }
        flag = true;
        // cout << x <<endl;
        // cout << x % 10 << endl;

        ans[i] = x % 10;
        // cout << ans[i]<<endl;
        x /= 10;
        i++;
    }
    cout << i << endl;
    long long res = 0;
    for (int i = 0; i < 11; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    string for (int j = 0; j < i; j++)
    {
        res += (long long)((pow(10, i - j)) * ans[j]);
        // cout << (pow(10, i - j)) * ans[j] << endl;
    }
    // std::cout << res << std::endl;
    cout << neg * res << endl;
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