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
    ll n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    map<char, ll> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        mp1[s1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        mp2[s2[i]]++;
    }

    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    else if (n > m)
    {
        for (int i = 0; i < m; i++)
        {
            if (mp1[s2[i]] > 0)
            {
                mp1[s2[i]]--;
                mp2[s2[i]]--;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        ll cnt = 0;
        for (auto it : mp1)
        {
            cnt += (it.second % 2 ? 1 : 0);
        }
        if(cnt<=1){
            cout << "YES"<<endl;
            return;
        }
        else{
            cout << "NO"<<endl;
            return;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (mp2[s1[i]] > 0)
            {
                mp1[s1[i]]--;
                mp2[s1[i]]--;
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
        ll cnt = 0;
        for (auto it : mp2)
        {
            cnt += (it.second % 2 ? 1 : 0);
        }
        if(cnt<=1){
            cout << "YES"<<endl;
            return;
        }
        else{
            cout << "NO"<<endl;
            return;
        }
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