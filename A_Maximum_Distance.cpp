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

ll euclideanDistance(pair<ll, ll> p1, pair<ll, ll> p2)
{
    ll xDiff = p2.first - p1.first;
    ll yDiff = p2.second - p1.second;
    return (xDiff * xDiff + yDiff * yDiff);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> abscisses(n);
    vector<ll> ordonnees(n);
    set<ll> euc;
    for (int i = 0; i < n; i++)
    {
        cin >> abscisses[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ordonnees[i];
    }
    ll maxx =0;
    for (int i = 0; i < n - 1; i++)
    {
        pair<ll, ll> p1 = make_pair(abscisses[i], ordonnees[i]);
        for (int j = i + 1; j < n; j++)
        {
            pair<ll, ll> p2 = make_pair(abscisses[j], ordonnees[j]);
            maxx = max(maxx,euclideanDistance(p1, p2));
        }
    }
    cout << maxx << endl;
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