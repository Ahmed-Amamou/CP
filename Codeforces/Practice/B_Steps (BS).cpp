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
ll n, m;
bool valid(ll x, ll y)
{
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void solve()
{

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
        ll mid, move;
        ll low = 0;
        ll high = 1e9;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (valid(x + mid * vx, y + mid * vy))
            {
                move = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        x += move * vx;
        y += move * vy;
        moves += move;
        // cout << "x: "<< x << "y: "<<y <<endl;
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