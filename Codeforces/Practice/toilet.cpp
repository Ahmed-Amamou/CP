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

int policy1(string s)
{
    int count = 0;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'D' && prev == 'U')
            count += 2;
        else if (s[i] == 'U' && prev == 'D')
            count += 1;
        else if (s[i] == 'D' && prev == 'D')
            count++;
        prev = 'U';
    }
    return count;
}
int policy2(string s)
{
    int count = 0;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'U' && prev == 'D')
            count += 2;
        else if (s[i] == 'U' && prev == 'U')
            count += 1;
        else if (s[i] == 'D' && prev == 'U')
            count++;
        prev = 'D';
    }
    return count;
}

int policy3(string s)
{
    int count = 0;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != prev)
            count++;
        prev = s[i];
    }
    return count;
}

void solve()
{
    string s;
    cin >> s;
    cout << policy1(s) << endl;
    cout << policy2(s) << endl;
    cout << policy3(s) << endl;
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