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
unordered_map<int, tuple<int, int, int>> precomputed;

ll XOR(ll a, ll b, ll c)
{
    return (a ^ b) + (b ^ c) + (a ^ c);
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    if (r - l >= 3)
    { // If range has at least 3 numbers
        ll highestBit = 63 - __builtin_clzll(r);

        vector<ll> possible;
        for (int i = highestBit; i >= 0; i--)
        {
            ll num = 0;
            for (int j = i; j >= 0; j--)
            {
                if ((num | (1LL << j)) <= r)
                {
                    num |= (1LL << j);
                }
            }
            if (num >= l && num <= r)
            {
                possible.push_back(num);
            }

            num = r;
            for (int j = i; j >= 0; j--)
            {
                num &= ~(1LL << j);
            }
            if (num >= l && num <= r)
            {
                possible.push_back(num);
            }
        }

        possible.push_back(l);
        possible.push_back(r);
        sort(possible.begin(), possible.end());
        possible.erase(unique(possible.begin(), possible.end()), possible.end());

        ll maxSum = 0;
        ll bestA = l, bestB = l + 1, bestC = l + 2;

        for (int i = 0; i < min(20LL, (ll)possible.size()); i++)
        {
            for (int j = i + 1; j < min(21LL, (ll)possible.size()); j++)
            {
                for (int k = j + 1; k < min(22LL, (ll)possible.size()); k++)
                {
                    ll a = possible[i];
                    ll b = possible[j];
                    ll c = possible[k];
                    ll sum = (a ^ b) + (b ^ c) + (a ^ c);
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                        bestA = a;
                        bestB = b;
                        bestC = c;
                    }
                }
            }
        }

        cout << bestA << " " << bestB << " " << bestC << "\n";
        // cout << "my score: " << XOR(bestA, bestB, bestC) << endl;

        // cout << "codeforces:" << endl;
        // cout << XOR(7, 16, 11) << endl;
        return;
    }

    // For very small ranges, use consecutive numbers
    cout << l << " " << l + 1 << " " << l + 2 << "\n";
    // cout << a << " " << b << " " << c << "\n";
}

signed main()
{
    FAST;
    ll tt = 1;
    // preprocess();
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}