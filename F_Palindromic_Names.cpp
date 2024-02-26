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
#define FAST                        \
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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  map<char, ll> mp;
  for (char c = 'a'; c <= 'z'; c++)
  {
    mp[c] = 0;
  }
  ll count = 0;
  for (int i = 0; i < s.size(); i++)
  {
    mp[s[i]]++;
  }

  for (auto it = mp.begin(); it != mp.end(); it++)
  {

    char key = it->first;
    ll value = it->second;
    if (value % 2 == 1)
    {
      count++;
    }
  }
  cout << count / 2 << endl;
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