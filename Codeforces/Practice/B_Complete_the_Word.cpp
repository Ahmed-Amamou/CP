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
    int freq[26];
    int n = s.size();

    if (n < 26)
    {
        cout << -1 << endl;
        return;
    }
    bool flag;
    for (int i = 0; i < n - 25; i++)
    {
        memset(freq, 0, sizeof(freq));
        int cntNone = 0;
        for (int j = 0; j < 26; j++)
        {
            if (s[i + j] == '?')
            {
                cntNone++;
                continue;
            }
            else
                freq[s[i + j] - 'A']++;
        }
        int cntZeros = 0;
        flag = true;
        for (int j = 0; j < 26; j++)
        {
            if (freq[j] > 1)
            {
                flag = false;
                break;
            }
            if (freq[j] == 0)
                cntZeros++;
        }
        if (flag && cntNone == cntZeros)
        {
            // go through the substring and change "?" with any x such that freq[x]==0
            for (int j = 0; j < 26; j++)
            {
                if (s[j + i] == '?')
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (freq[k] == 0)
                        {
                            s[j + i] = 'A' + k;
                            freq[k]++;
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
    if (flag == false)
    {
        cout << -1 << endl;
        return;
    }
    for (auto &c : s)
    {
        if (c == '?')
            c = 'A';
    }
    cout << s << endl;
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