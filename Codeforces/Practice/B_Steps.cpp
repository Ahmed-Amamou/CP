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

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll x, y;
    cin >> x >> y;
    ll q;
    cin >> q;
    ll moves = 0;
    ll y_move, x_move;
    for (int i = 0; i < q; i++)
    {
        ll vx, vy;
        cin >> vx >> vy;
        if (vx == 0 && vy == 0)
            continue;
        else if (vx == 0)
        {
            y_move = vy > 0 ? (m - y) / vy : (1 - y) / vy;
            x_move = 1e9;
        }
        else if (vy == 0)
        {
            x_move = vx > 0 ? (n - x) / vx : (1 - x) / vx;
            y_move = 1e9;
        }
        else
        {
            y_move = vy > 0 ? (m - y) / vy : (1 - y) / vy;
            x_move = vx > 0 ? (n - x) / vx : (1 - x) / vx;
        }
        // cout << "x_move: " << x_move << ", y_move: " << y_move << endl;
        moves += min({x_move, y_move});
        // cout << "moves: " << moves << endl;
        x += min({x_move, y_move}) * vx;
        y += min({x_move, y_move}) * vy;
        // cout << "x: " << x << " y: " << y << endl;
    }
    cout << moves << endl;
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