// Author: Ahmed Amamou

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }   

    vector<int> frequencies;
    for (auto &p : freq)
    {
        frequencies.push_back(p.second);
    }
    sort(frequencies.begin(), frequencies.end());

    int unique = frequencies.size();

    for (int f : frequencies)
    {
        if (k >= f)
        {
            k -= f;
            unique--;
        }
        else
        {
            break;
        }
    }

    cout << max(unique, 1) << endl;
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