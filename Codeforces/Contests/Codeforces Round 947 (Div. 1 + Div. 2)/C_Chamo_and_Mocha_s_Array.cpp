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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // cout << a[i]<<" ";
    }
    // cout << endl;
    vector<vector<int>> doublets, triplets;
    // generate doubles
    for (int i = 0; i < n - 1; i++)
    {
        vector<int> sub;
        sub.push_back(a[i]);
        sub.push_back(a[i + 1]);
        // cout << "Sub: ";
        // for (const auto& num : sub) {
        //     cout << num << " ";
        // }
        // cout << endl;

        sort(sub.begin(), sub.end());
        doublets.push_back(sub);
    }
    for (int i = 0; i < n - 2; i++)
    {
        vector<int> sub;
        sub.push_back(a[i]);
        sub.push_back(a[i + 1]);
        sub.push_back(a[i + 2]);
        sort(sub.begin(), sub.end());
        triplets.push_back(sub);
    }
    // // Print doublets
    // for (const auto& doublet : doublets) {
    //     cout << "Doublet: ";
    //     for (const auto& num : doublet) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // // Print triplets
    // for (const auto& triplet : triplets) {
    //     cout << "Triplet: ";
    //     for (const auto& num : triplet) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // }
    int mx1 = 0;
    for (int i = 0; i < doublets.size(); i++)
    {
        mx1 = max(doublets[i][0], mx1);
    }
    int mx2 = 0;
    for (int i = 0; i < triplets.size(); i++)
    {
        mx2 = max(triplets[i][1], mx2);
    }
    cout << max(mx1, mx2) << endl;
    
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