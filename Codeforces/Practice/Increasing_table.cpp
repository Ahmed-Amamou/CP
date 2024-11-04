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
const ll MOD = 998244353;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

const int MAXN = 2005;

void solves()
{
    int N;
    cin >> N;

    int X;
    cin >> X;
    unordered_set<int> A;
    for (int i = 0; i < X; ++i)
    {
        int a;
        cin >> a;
        A.insert(a);
    }

    int Y;
    cin >> Y;
    unordered_set<int> B;
    for (int i = 0; i < Y; ++i)
    {
        int b;
        cin >> b;
        B.insert(b);
    }

    // DP array: dp[j] represents the number of ways to fill columns with exactly j elements in row 1
    vector<int> dp(N + 1, 0);
    dp[0] = 1; // Initial state with zero columns filled

    for (int i = 1; i <= 2 * N; ++i)
    {
        vector<int> new_dp(N + 1, 0);

        if (A.count(i) > 0)
        { // Current number must go in row 1
            for (int j = 1; j <= N; ++j)
            {
                new_dp[j] = dp[j - 1]; // Shift previous row 1 configuration
            }
        }
        else if (B.count(i) > 0)
        { // Current number must go in row 2
            for (int j = 0; j <= N; ++j)
            {
                new_dp[j] = dp[j]; // Retain previous row 2 configuration
            }
        }
        else
        { // Current number can go in either row
            for (int j = 0; j <= N; ++j)
            {
                if (j > 0)
                {
                    new_dp[j] = (new_dp[j] + dp[j - 1]) % MOD; // Option to place in row 1
                }
                new_dp[j] = (new_dp[j] + dp[j]) % MOD; // Option to place in row 2
            }
        }

        dp = new_dp; // Update dp to new_dp for next iteration
    }

    // Result is in dp[N], as it represents valid ways to fill N columns with row constraints satisfied
    cout << dp[N] -1 << endl;
}
signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    solves();
    return 0;
}