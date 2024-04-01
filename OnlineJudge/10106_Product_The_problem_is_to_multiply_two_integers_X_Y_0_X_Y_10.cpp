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
    while (true)
    {
        string X, Y;
        cin >> X >> Y;
        if (X.empty() || Y.empty())
        {
            return;
        }

        vector<int> ans(X.size() * Y.size() +1, 0);
        for (int i = 0; i < X.size(); i++)
        {
            for (int j = 0; j < Y.size(); j++)
            {
                int x = X[X.size() - i - 1] - '0';
                int y = Y[Y.size() - j - 1] - '0';
                ans[i + j] += (x * y);
                

            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }
        
        bool flag = false;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            if (ans[i] == 0 && flag == false && i!=0)
            {
                continue;
            }
            else
            {
                flag = true;
                cout << ans[i] ;
            }
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