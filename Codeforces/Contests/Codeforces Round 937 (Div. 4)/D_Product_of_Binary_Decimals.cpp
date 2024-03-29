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
const int MAX_N = 100005;

int main()
{
    ll t;
    cin >> t;
    vector<int> binary_decimals;
    binary_decimals.push_back(1);
    // this calculates all binary decimals (tree)
    for (int i = 0; i < binary_decimals.size(); i++)
    {
        if (binary_decimals[i] * 10 > 1e5)
            break;
        binary_decimals.push_back(binary_decimals[i] * 10);
        binary_decimals.push_back(binary_decimals[i] * 10 + 1);
    }
    vector<int> dp(MAX_N + 10);
    dp[1] = 1;
    for (int i = 2; i < MAX_N; i++)
    {
        for (int bd : binary_decimals)
        {
            if (i % bd == 0)
                dp[i] = dp[i / bd];
        }
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n] ? "YES" : "NO") << endl;
    }

    return 0;
}