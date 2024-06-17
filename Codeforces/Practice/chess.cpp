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
    pair<int, int> source, destination;
    char x, y;
    cin >> x >> source.second >> y >> destination.second;
    source.first = x - 'A';
    destination.first = y - 'A';
    source.second--;
    destination.second--;
    // cout << source.first << " "<<source.second << " - "<<destination.first<<" "<<destination.second<<endl;
    if ((source.first + source.second) % 2 == (destination.first + destination.second) % 2)
    {
        if (source.first == destination.first && source.second == destination.second)
        {
            cout << 0 << " " << (char)('A' + source.first) << " " << source.second + 1 << endl;
        }
        else
        {
            if (abs(source.first - destination.first) == abs(source.second - destination.second))
            {
                cout << 1 << " " << (char)(source.first + 'A') << " " << source.second + 1 << " "
                     << (char)(destination.first + 'A') << " " << destination.second + 1 << endl;
            }
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (abs(i - source.first) == abs(j - source.second) && abs(i - destination.first) == abs(j - destination.second))
                        {
                            cout << 2 << " " << (char)(source.first + 'A') << " " << source.second + 1<<" "
                                 << (char)(i + 'A') << " " << j + 1<<" "
                                 << (char)(destination.first + 'A') << " " << destination.second + 1 << endl;
                                 return;
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "Impossible" << endl;
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