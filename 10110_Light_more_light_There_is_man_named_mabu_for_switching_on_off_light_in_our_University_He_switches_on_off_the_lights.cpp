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
ll calculate_sum_of_digits(ll n)
{
    ll sum = n % 10;
    ll k = 100;
    while (n / k != 0)
    {
        sum += (n % k) / (k / 10);
        k *= 10;
    }

    return sum += (n % k) / (k / 10);
}
bool is_prime(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            sum++;
    }
    if (sum > 2)
        return false;
    else
        return true;
}
void solve()
{
    ll n;

    // we want to know if the divisors of n are odd or even
    while (true)
    {
        
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