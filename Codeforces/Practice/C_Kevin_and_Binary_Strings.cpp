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

int binaryXORToDecimal(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    int i = n - 1, j = m - 1, result = 0, power = 0;
    while (i >= 0 || j >= 0)
    {
        int bit1 = (i >= 0) ? a[i--] - '0' : 0;
        int bit2 = (j >= 0) ? b[j--] - '0' : 0;

        int xorBit = bit1 ^ bit2;
        result += xorBit * pow(2, power++);
    }

    return result;
}
void solve()
{
    string s;
    cin >> s;
    if (s == "1")
    {
        cout << "1 1 1 1" << endl;
        return;
    }
    int firstZero = s.find_first_of('0');
    if (firstZero == -1)
    {
        cout << 1 << " " << s.length() << " " << 2 << " " << 2 << endl;
    }
    else
    {
        string substring = s.substr(firstZero);
        string bestRes = "0";
        int bestPos = 1;
        for (int i = 0; i < s.length() - substring.length() + 1; i++)
        {
            string zambala = s.substr(i, substring.length());
            string currRes = "";
            for (int j = 0; j <  substring.length(); j++)
            {
                currRes += ((substring[j] - '0') ^ (zambala[j] - '0') == 0 ? '0' : '1');
                // debug(currRes);
            }
            if (currRes > bestRes)
            {
                
                bestRes = currRes;
                bestPos = i + 1;
            }
        }

        cout << 1 << " " << s.length() << " " << bestPos << " " << bestPos + substring.length() - 1 << endl;
    }
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