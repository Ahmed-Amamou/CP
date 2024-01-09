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

int binarysearch(int x, vector<pair<int, int>> &v, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid].first == x)
            return mid;
        if (v[mid].first > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // Element not found
}

void solve()
{
    int n;
    cin >> n; // Initialize the variable 'n'
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        v.push_back({y, i});
    }

    // Sort the vector of pairs
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    ll vasya = 0, petya = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int index = binarysearch(x, v, 0, n);
        vasya += v[index].second + 1;
        petya += n - v[index].second;
    }
    cout << vasya << " " << petya << endl;

    // // Print the elements of vector v
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
}
void solve2()
{
    ll n;
    cin >> n;
    ll pos[n];
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        pos[x] = i + 1;
    }
    ll m,vasya=0,petya=0;
    cin >> m;
    for (ll  i = 0; i < m; i++)
    {
        ll x;
        cin >>x;
        vasya+=pos[x];
        petya+=n-pos[x]+1;

    }
    cout << vasya << " "<< petya;
    
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--)
    solve2();
    return 0;
}