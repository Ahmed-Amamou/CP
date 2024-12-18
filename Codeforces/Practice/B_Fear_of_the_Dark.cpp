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

double euclidean_distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
void solve()
{
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double distAO = euclidean_distance(ax, ay, 0, 0);
    double distAP = euclidean_distance(ax, ay, px, py);
    double distBP = euclidean_distance(bx, by, px, py);
    double distBO = euclidean_distance(bx, by, 0, 0);
    double distAB = euclidean_distance(bx, by, ax, ay);
    double ans;
    //A a9reb lil O
    if (distAO < distBO)
    {   // A a9reb lil P
        if (distAP < distBP)
        {
            // cout << "first" << endl;
            ans = max(distAP, distAO);
        }
        //B a9reb lil P
        else
        {
            // cout << "second" << endl;
            ans = max(max(distAB / 2, distBP),distAO);
        }
    }
    //B a9reb lil O
    else
    {   //A a9reb lil P
        if (distAP < distBP)
        {
            // cout << "thirs" << endl;
            ans = max(max(distAB / 2, distAP),distBO);
        }
        //B a9reb lil P
        else
        {
            // cout << "fourth" << endl;
            ans = max(distBP, distBO);
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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