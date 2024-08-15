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
map<int, vector<int>> digitToSegments = {
    {0, {1, 1, 1, 0, 1, 1, 1}}, // 0
    {1, {0, 0, 1, 0, 0, 1, 0}}, // 1
    {2, {1, 0, 1, 1, 1, 0, 1}}, // 2
    {3, {1, 0, 1, 1, 0, 1, 1}}, // 3
    {4, {0, 1, 1, 1, 0, 1, 0}}, // 4
    {5, {1, 1, 0, 1, 0, 1, 1}}, // 5
    {6, {1, 1, 0, 1, 1, 1, 1}}, // 6
    {7, {1, 0, 1, 0, 0, 1, 0}}, // 7
    {8, {1, 1, 1, 1, 1, 1, 1}}, // 8
    {9, {1, 1, 1, 1, 0, 1, 1}}  // 9
};
void solve()
{
    
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