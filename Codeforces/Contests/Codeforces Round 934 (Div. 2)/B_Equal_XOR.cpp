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
    ll n, k;
    cin >> n >> k;
    ll a[2 * n];
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> chtar_loul;
    map<ll, ll> chtar_theni;
    set<ll> distincts;
    set<ll> repeated_chtar_loul;
    set<ll> repeated_chtar_theni;
    for (int i = 0; i < n; i++)
    {

        chtar_loul[a[i]]++;
    }
    for (auto it = chtar_loul.begin(); it != chtar_loul.end(); it++)
    {
        if (it->second == 2)
        {
            repeated_chtar_loul.insert(it->first);
        }
        else
        {
            distincts.insert(it->first);
        }
    }
    for (int i = n; i < 2 * n; i++)
    {

        chtar_theni[a[i]]++;
    }
    for (auto it = chtar_theni.begin(); it != chtar_theni.end(); it++)
    {
        if (it->second == 2)
        {
            repeated_chtar_theni.insert(it->first);
        }
    }
    // for (auto it = repeated_chtar_loul.begin(); it != repeated_chtar_loul.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // for (auto it = repeated_chtar_theni.begin(); it != repeated_chtar_theni.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl<<" disticnts:\n";
    // for (auto it = distincts.begin(); it != distincts.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;
    vector<ll> res1;
    vector<ll> res2;
    if (k <= repeated_chtar_loul.size())
    {
        for (auto it = repeated_chtar_loul.begin(); it != repeated_chtar_loul.end() && res1.size() < 2*k; it++)
        {
            res1.push_back(*it);
            res1.push_back(*it);
        }
        for (auto it = repeated_chtar_theni.begin(); it != repeated_chtar_theni.end() && res2.size() < 2*k; it++)
        {
            res2.push_back(*it);
            res2.push_back(*it);
        }
    }
    else
    {
        for (auto it = repeated_chtar_loul.begin(); it != repeated_chtar_loul.end() && res1.size() < 2*k; it++)
        {
            res1.push_back(*it);
            res1.push_back(*it);
        }
        for (auto it = distincts.begin(); it != distincts.end() && res1.size() < 2*k; it++)
        {
            res1.push_back(*it);
        }

        for (auto it = repeated_chtar_theni.begin(); it != repeated_chtar_theni.end() && res2.size() < 2*k; it++)
        {
            res2.push_back(*it);
            res2.push_back(*it);
        }
        for (auto it = distincts.begin(); it != distincts.end() && res2.size() <  2*k; it++)
        {
            res2.push_back(*it);
        }
    }
    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < res2.size(); i++)
    {
        cout << res2[i] << " ";
    }
    cout << endl;
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