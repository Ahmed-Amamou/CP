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
    string password = "";
    for (int i = 0; i < n; i++)
    {
        string curr = password + "0";
        cout << "? " << curr << endl;
        cout.flush();
        int res;
        cin >> res;
        if (res)
        {
            password = curr;
            continue;
        }
        else
        {
            curr = password + "1";
            cout << "? " << curr << endl;
            cout.flush();
            int res2;
            cin >> res2;
            if (res2)
            {
                password = curr;
                continue;
            }
            else
                break;
        }
    }
    if (password.size() == n)
    {
        cout << "! " << password << endl;
        cout.flush();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        string curr = "0" + password;
        cout << "? " << curr << endl;
        cout.flush();
        int res;
        cin >> res;
        if (res)
        {
            password = curr;
            if (password.size() == n)
                break;
            continue;
        }
        else
        {
            password = "1" + password;
            if (password.size() == n)
            {
                break;
            }
        }
    }
    cout << "! " << password << endl;
    cout.flush();
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