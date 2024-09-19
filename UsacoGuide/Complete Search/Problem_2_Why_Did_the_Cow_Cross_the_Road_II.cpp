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

void solve()
{
    string s;
    cin >> s;
    int matrix[26][26];
    memset(matrix, 0, sizeof(matrix));
    for (char c = 'A'; c != ('Z' + 1); c++)
    {
        int first, second;
        first = s.find_first_of(c);
        for (int i = first + 1;; i++)
        {
            if (s[i] == c)
                break;
            matrix[c - 'A'][s[i] - 'A']++;
        }
    }
    ll count = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            count += (matrix[i][j] & 1);
        }
    }
    count /= 2;
    cout << count << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}