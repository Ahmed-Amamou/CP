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

int scores[3];
int compare(string a, string b)
{
    if (a == b)
    {
        return 0;
    }
    else if ((a == "rock" && b == "scissors") || (a == "scissors" && b == "paper") || (a == "paper" && b == "rock"))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void solve()
{
    string f, m, s;
    cin >> f >> m >> s;
    scores[0] += compare(f, m) + compare(f, s);
    scores[1] += compare(m, f) + compare(m, s);
    scores[2] += compare(s, f) + compare(s, m);
    if (scores[0] == 2)
    {
        cout << "F" << endl;
    }
    else if (scores[1] == 2)
    {
        cout << "M" << endl;
    }
    else if (scores[2] == 2)
    {
        cout << "S" << endl;
    }
    else
    {
        cout << "?" << endl;
    }
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