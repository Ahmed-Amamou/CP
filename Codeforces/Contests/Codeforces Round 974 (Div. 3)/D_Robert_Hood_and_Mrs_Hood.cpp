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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        //  int max=0,min=k,maxu=1,minu=1;
        cin >> n >> m >> k;
        vector<pair<int, int>> l(k);
        for (int i = 0; i < k; i++)
        {
            cin >> l[i].first >> l[i].second;
        }
        vector<int> p(n + 1, 0);
        vector<int> pre(n + 1, 0);
        for (auto &lo : l)
        {
            p[lo.first]++;
            if (lo.second + 1 <= n)
                p[lo.second + 1]--;
        }
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + p[i];
        }
        int max = 0, min = k, maxu = 1, minu = 1;
        int o = 0;
        for (int i = 1; i <= m; i++)
        {
            o += pre[i];
        }
        max = o;
        min = o;

        for (int i = m + 1; i <= n; i++)
        {
            o += pre[i] - pre[i - m];
            if (o > max)
            {
                max = o;
                maxu = i - m + 1;
            }
            if (o < min)
            {
                min = o;
                minu = i - m + 1;
            }
        }
        cout << maxu << " " << minu << endl;
    }
    return 0;
}