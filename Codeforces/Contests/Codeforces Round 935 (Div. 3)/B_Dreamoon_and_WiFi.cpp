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
ll combination(ll n, ll r)
{
    if (r > n - r)
    {
        r = n - r;
    }
    ll result = 1;
    for (ll i = 0; i < r; i++)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}
void solve()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    ll istefham = 0;
    ll count_plus = 0;
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == '?')
        {
            istefham++;
            if (s1[i] == '+')
            {
                count_plus++;
            }
        }
        else
        {
            sum1 += s1[i] == '+' ? 1 : -1;
            sum2 += s2[i] == '+' ? 1 : -1;
        }
    }

    cout << fixed << setprecision(12) << (double)(combination(istefham, count_plus)) / (double)pow(2, istefham) << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--)
    solve();
    return 0;
}