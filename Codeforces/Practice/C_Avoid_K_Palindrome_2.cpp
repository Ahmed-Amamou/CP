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
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
ll factorial(int n)
{
    if (n <= 1)
        return n;
    return n * factorial(n - 1);
}
void solve()
{
    int n, x;
    cin >> n >> x;
    // generate all permutations using next_permutation
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> permutations;
    do
    {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    // cout << permutations.size() << endl;
    ll count = 0;
    set<string> seen;
    for (auto s : permutations)
    {
        for (int i = 0; i < n - x + 1; i++)
        {
            // cout << s.substr(i, x) << endl;
            if (isPalindrome(s, i, i + x - 1) && seen.find(s) == seen.end())
            {
                count++;
                // cout << "count: " << count << endl;
                seen.insert(s);
            }
        }
    }
    cout << permutations.size() - count << endl;
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