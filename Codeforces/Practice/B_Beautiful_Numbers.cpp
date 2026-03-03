// Author: Ahmed Amamou

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
    // s is a string of numbers , I have to get the total of all numbers.. in a while loop check if the total is <= 10 (only condition to meet)
    // to achieve that we will start greedily switching the larger numbers first to 0 -- edge case if the turn is for the number in index 0, then we change it to 1 and not 0 like the rest.
    // we substract the number each time
    sort(s.rbegin(), s.rend() - 1);
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        sum += s[i] - '0';
    }
    int changes = 0;
    int j = 1;
    while (sum >= 10)
    {
        if (s[j] >= s[0])
        {
            sum -= (s[j] - '0');
            s[j] = '0';
            j++;
        }
        else
        {
            sum-=(s[0]-'0');
            sum++;
            // cout << sum << endl;
            s[0]='1';
        }
        // cout << s << endl<< "--------"<< endl;
        changes++;
    }
    cout << changes << endl;
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