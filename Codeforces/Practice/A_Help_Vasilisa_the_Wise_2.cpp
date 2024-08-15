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
#define debug(x) cout << #x << ": " << x << " ";

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
bool checkAll(int a, int b, int c, int d, int clul, int ctheni, int rlul, int rtheni, int dlul, int dtheni)
{
    return (a + c == clul && b + d == ctheni) && (a + b == rlul && c + d == rtheni) && (a + d == dlul && b + c == dtheni);
}
void solve()
{
    int rlul, rtheni, clul, ctheni, dlul, dtheni;
    cin >> rlul >> rtheni >> clul >> ctheni >> dlul >> dtheni;
    int a, b, c, d;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (j != i)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (k != j && k != i)
                    {
                        for (int p = 0; p <= 9; p++)
                        {
                            if (p != k && p != j && p != i)
                            {

                                if (checkAll(i, j, k, p, clul, ctheni, rlul, rtheni, dlul, dtheni))
                                {
                                    cout << i << " " << j << endl;
                                    cout << k << " " << p << endl;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
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