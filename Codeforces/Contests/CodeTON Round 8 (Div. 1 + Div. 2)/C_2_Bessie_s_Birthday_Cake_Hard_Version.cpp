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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> visited(X);
    for (int &a : visited)
    {
        cin >> a;
        a--;
    }
    sort(visited.begin(), visited.end());
    vector<int> o;
    vector<int> e;
    for (int i = 0; i < X; i++)
    {
        int R = visited[i];
        int next = visited[(i + 1) % X];
        int D = (next - R);
        if (!(D < 3))
        {
            int no = D - 1;
            if (no & 1)
                o.push_back(no);
            else
                e.push_back(no);
        }
    }
    sort(o.begin(), o.end());
    int ans = N - 2;
    for (int &y : o)
    {
        if (Y >= y / 2)
        {
            Y -= y / 2;
            // y = 0;
        }
        else
        {
            int a = min(Y, y / 2);
            // y -= 2 * a;
            Y -= a;
            ans -= y;
        }
    }
    for (int &y : e)
    {
        int a = min(Y, y / 2);
        y -= 2 * a;
        Y -= a;
        ans -= y;
    }
    cout << ans << endl;
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