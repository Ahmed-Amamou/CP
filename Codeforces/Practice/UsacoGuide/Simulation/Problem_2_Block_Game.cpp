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
    int n;
    cin >> n;
    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
    {
        int current_freqs1[26];
        memset(current_freqs1, 0, sizeof(current_freqs1));
        int current_freqs2[26];
        memset(current_freqs2, 0, sizeof(current_freqs2));
        string s1, s2;
        cin >> s1 >> s2;
        for (auto c : s1)
        {
            current_freqs1[c - 'a']++;
        }
        for (auto c : s2)
        {
            current_freqs2[c - 'a']++;
        }
        for (int j = 0; j < 26; j++)
        {
            freq[j] += max(current_freqs1[j], current_freqs2[j]);
        }
    }
    for (int j = 0; j < 26; j++)
    {
        cout << freq[j] << endl;
    }
}

signed main()
{
    FAST;
    ll tt = 1;
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    // cin >> tt;
    // while (tt--)
    solve();
    return 0;
}