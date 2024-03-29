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



signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    char check[42][42];
    for (int i = 0; i < 42; i++)
    {
        for (int j = 0; j < 42; j++)
        {
            if (i % 4 < 2)
            {
                if (j % 4 >= 2)
                {
                    check[i][j] = '.';
                }
                else{
                  check[i][j] = '#';   
                }
            }
            else{
                if (j % 4 >= 2)
                {
                    check[i][j] = '#';
                }
                else{
                  check[i][j] = '.';   
                }
            }
        }
    }

    cin >> tt;
    while (tt--)
        {
            ll n ;
            cin >> n;
            for (int i = 0; i < 2*n; i++)
            {
                for (int j = 0; j < 2*n; j++)
                {
                    cout << check[i][j];
                }
                cout << endl;
                
            }
            
        }
    return 0;
}