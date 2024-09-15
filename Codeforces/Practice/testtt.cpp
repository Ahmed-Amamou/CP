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
map<int, int> count_points_before_x(const set<pair<int, int>> &points)
{
    map<int, int> result; // Map to store the number of points before each x
    int count = 0;        // Prefix sum to count points

    for (const auto &point : points)
    {
        int x = point.first; // Get the x-coordinate of the current point

        // If this is the first time we encounter this x value, store the count
        if (result.find(x) == result.end())
        {
            result[x] = count;
        }

        count++; // Increment the count for the next point
    }

    return result;
}

void solve()
{
    set<pair<int, int>> points = {{1, 2}, {3, 4}, {3, 5}, {5, 6}, {7, 8}};

    map<int, int> result = count_points_before_x(points);

    // Output the result
    for (const auto &[x, count] : result)
    {
        cout << "Number of points with x < " << x << ": " << count << endl;
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