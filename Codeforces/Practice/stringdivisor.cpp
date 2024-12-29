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
bool is_divisible(string s, string x)
{
    int n = s.size();
    int m = x.size();
    if (n < m)
        return false;
    if (n == m)
        return s == x;
    int i = 0;
    if(n % m != 0)
        return false;
    while (i < n)
    {
        if (s[i] != x[i % m])
            return false;
        i++;
    }
    return true;
}
string gcdOfStrings(string str1, string str2)
{
    // start with empty string
    // we take the shortst string of them both and see if it divides the whole two string
    // if it does we save it and move to the next
    string ans = "";
    string string_to_work_with = (str1.size() >= str2.size() ? str1 : str2);
    string local = "";
    for (char c : string_to_work_with)
    {
        local += c;
        // check first string
        if (is_divisible(str1, local) && is_divisible(str2, local))
        {
            ans = local;
        }
    }
    return ans;
}
void solve()
{
    string s, x;
    cin >> s >> x;
    cout << gcdOfStrings(s, x) << endl;

    // check if s string is divisible by x string
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