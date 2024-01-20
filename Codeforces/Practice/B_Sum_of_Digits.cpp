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
const ll N = 5e5 + 20, MOD = 1e9 + 7;
ll n, tab[N], dp[N][2];
vector<int> adj[N];
bool vis[N][2];
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int sumOfDigits(string number)
{
    int sum = 0;
    for (char digit : number)
    {
        sum += digit - '0';
    }
    return sum;
}

void solve()
{
    string n;
    cin >> n;
    int count = 1;
    if (n.length() > 1)
    {
        while (true)
        {
            if (sumOfDigits(n) >= 10)
            {
                count++;
                n = to_string(sumOfDigits(n));
            }
            else
                break;
        }
        {
            cout << count << endl;
        }
    }
    else
        cout << 0 << endl;
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