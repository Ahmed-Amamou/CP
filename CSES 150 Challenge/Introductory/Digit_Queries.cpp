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
#define debug(x) cout << #x << ": " << x << endl;

// Rest of the code...
signed main()
{
    ll tt = 1;

    // freopen("input.in", "r", stdin);
    vector<ll> powersOfTen(18, 1);
    // cout << powersOfTen[0] << " " << powersOfTen[2] << endl;
    for (int i = 1; i < 18; i++)
    {
        powersOfTen[i] = powersOfTen[i - 1] * 10;
        // cout << powersOfTen[i]<<endl;
    }

    cin >> tt;
    while (tt--)
    {
        long long k;
        cin >> k;
        // cout << "h" << endl;
        ll prev = 1LL;
        ll digits = 0LL;
        ll high, low;
        ll startIndex;
        for (int i = 0; i < powersOfTen.size() - 1; i++)
        {
            ll lowerBound = prev;
            ll higherBound = (powersOfTen[i + 1] - 1 - powersOfTen[i]) * (i + 1) + prev;
            prev = higherBound + i + 1;
            startIndex = lowerBound;
            digits = i + 1;
            if (k <= prev - 1 && k >= lowerBound)
            {
                high = powersOfTen[i + 1];
                low = powersOfTen[i];
                break;
            }
        }
        // binary seach to find x :x is the main number that we will later extract the digit of index k from .
        ll lowerB = low;
        // debug(low);
        // debug(high);
        ll count = 30;
        ll mid;
        ll diff;
        while (high > low)
        {
            mid = low + (high - low) / 2;
            // debug(mid);
            // debug(digits);
            // debug(startIndex);
            ll x = (mid - lowerB) * (digits) + startIndex;
            // cout << low << " " << "| " << mid << " |" << high << endl;
            // debug(x);
            // debug(k);

            if (k - x >= 0 && k - x <= digits - 1)
            {
                break;
            }
            else if (x > k)
            {
                high = mid - 1;
            }
            else if (x < k)
            {
                low = mid + 1;
            }
        }
        mid = low + (high - low) / 2;
        ll x = (mid - lowerB) * (digits) + startIndex;
        diff = k - x;
        string main = to_string(mid);
        cout << main[diff] << endl;
    }
    return 0;
}