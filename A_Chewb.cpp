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
    string s;
    map<int, char> mp = {{5, '4'}, {6, '3'}, {7, '2'}, {8, '1'}, {9, '0'}};
    cin >> s;
    if (s.size() == 1 && (s[0] == '9'))
    {
        cout << 9 << endl;
        return;
    }
    else if (s.size() == 1 && s[0] == '0')
    {
        cout << 0 << endl;
        return;
    }
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (flag == false && s[0] == '9')
        {
            flag = true;
            continue;
        }

        if (s[i] - '0' >= 5)
        {
            s[i] = mp[s[i] - '0'];
        }
    }

    for (int i = 0; i < s.size(); i++)
    {

        cout << s[i];
    }
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