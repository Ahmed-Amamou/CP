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
// #include "debug.h"

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    string s;
    cin >> s;
    set<char> vowels{'A', 'E', 'I', 'O', 'U'};
    int cntVowels = 0, cntCons = 0, cntY = 0, cntG = 0, cntN = 0;

    for (auto c : s)
    {
        if (c == 'Y')
        {
            cntY++;
            continue;
        }
        else if (vowels.find(c) != vowels.end())
        {
            cntVowels++;
        }
        else
        {
            if (c == 'N')
            {
                cntN++;
            }
            else if (c == 'G')
            {
                cntG++;
            }
            cntCons++;
        }
    }
    for (int i = 0; i < cntY; i++)
    {
        if (cntCons > 2 * cntVowels + 1)
        {
            cntVowels++;
        }
        else
        {
            cntCons++;
        }
    }
    if (cntVowels == 0 || cntCons < 2)
    {
        cout << 0 << endl;
        return;
    }
    // cout << cntCons << " " << cntVowels << endl;
    // cout << cntG << " " << cntN << endl;
    int ans = 3 * min(cntCons / 2, cntVowels);
    int consoneLeft = cntCons - (ans / 3) * 2;
    // debug(cntVowels * 2);
    // debug(cntCons);
    ans += min(min(consoneLeft, cntN), cntG);
    cout << ans << endl;
}
signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}