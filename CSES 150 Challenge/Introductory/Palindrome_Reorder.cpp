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
    string s;
    cin >> s;
    map<char, ll> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    ll cnt = 0;
    vector<char> res;
    char abdstar = ' ';
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second % 2)
        {
            cnt++;
            abdstar = it->first;
        }
    }
    if (cnt > 1)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        if (abdstar != ' ')
        {
            for (int i = 0; i < mp[abdstar]; i++)
            {
                res.push_back(abdstar);
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second % 2 == 0)
            {
                for (int i = 0; i < it->second / 2; i++)
                {
                    res.push_back(it->first);
                    res.insert(res.begin(), it->first);
                }
            }
        }
        for (char c : res)
        {
            cout << c;
        }
        cout << endl;
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