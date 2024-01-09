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

int summ(vector<int> v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int count = 1;
    int me = v[n - 1];
    v.pop_back();
    // cout << me << endl;
    while (true)
    {
        // cout << "sum: " << sum << " me " << me << endl;
        // for (int i : v)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        int sum = summ(v);
        // cout <<"sum: " <<sum<<endl;
        if (sum >= me)
        {
            me += v[v.size() - 1];
            v.pop_back();
            count++;
        }
        else
            break;
    }
    cout << count << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    // while (tt--)
    solve();
    return 0;
}
