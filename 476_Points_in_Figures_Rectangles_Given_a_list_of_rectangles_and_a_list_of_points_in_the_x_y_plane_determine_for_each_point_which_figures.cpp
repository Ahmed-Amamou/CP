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
char c;
void solve()
{
    string line;
    vector<pair<pair<float, float>, pair<float, float>>> rectangles;
    while (getline(cin, line) && line != "*")
    {
        stringstream ss(line);
        char rectangle;
        ss >> rectangle;
        vector<float> values;
        float value;
        while (ss >> value)
        {
            values.push_back(value);
        }
        float x1 = values[0], y1 = values[1], x2 = values[2], y2 = values[3];
        pair<float, float> pair1 = x1 > x2 ? make_pair(x1, x2) : make_pair(x2, x1);
        pair<float, float> pair2 = y1 > y2 ? make_pair(y1, y2) : make_pair(y2, y1);
        rectangles.push_back(make_pair(pair1, pair2));
    }
    ll point = 1;
    while (getline(cin, line) && line != "9999.9 9999.9")
    {
        stringstream ss(line);
        float value;
        vector<float> v;

        while (ss >> value)
        {
            v.push_back(value);
        }
        ll k = 0;
        for (int i = 0; i < rectangles.size(); i++)
        {
            // cout << "point to test is: " << v[0] << " " << v[1] << endl;
            // cout << "test: "<<rectangles[i].first.first <<" "<< rectangles[i].first.second <<" "<< rectangles[i].second.first<<" " <<rectangles[i].second.second<<endl;
            if (v[0] < rectangles[i].first.first && v[0] > rectangles[i].first.second && v[1] < rectangles[i].second.first && v[1] > rectangles[i].second.second)
            {
                cout << "Point " << point << " is contained in figure " << i + 1 << endl;
                k++;
            }
        }
        if (k == 0)
        {
            cout << "Point " << point << " is not contained in any figure" << endl;
        }
        point += 1;
    }
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