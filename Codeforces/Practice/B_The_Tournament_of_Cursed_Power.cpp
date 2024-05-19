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

void print_vec(vector<int> vec)
{
    cout << "-----" << endl;

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " - ";
    }
    cout << "-----" << endl;
}

vector<int> simulate(const vector<int> &powers, int n)
{
    vector<int> winners = vector<int>(n);
    for (int i = 0; i < powers.size() / 2; i++)
    {
        int a = powers[2 * i];
        int b = powers[2 * i + 1];
        if (a > b)
            winners[i] = a;
        else
            winners[i] = b;
    }
    return winners;
}

long long check_gojo(int gojo, const vector<vector<int>> &allpowers, int n, int k = 0)
{
    if (k > n - 1)
        return 0;
    int position = gojo / (1 << k);
    // print_vec(allpowers[k]);
    if (position % 2 == 0)
    {
        return allpowers[k][position + 1] + check_gojo(gojo, allpowers, n, k + 1);
    }
    else
    {
        return allpowers[k][position - 1] + check_gojo(gojo, allpowers, n, k + 1);
    }
}

void solve()
{
    vector<vector<int>> allpowers = vector<vector<int>>();
    int n, t;
    cin >> t;
    vector<vector<int>> solution = vector<vector<int>>(t, vector<int>(n));
    n = 1 << t;

    vector<int> powers = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> powers[i];
    }
    while (powers.size() > 1)
    {
        allpowers.push_back(powers);
        // print_vec(powers);
        powers = simulate(powers, n);
    }
    // print_vec(powers);
    // for (int gojo = 0; gojo < n; gojo++)
    // {
    //     cout << check_gojo(gojo, allpowers, t) << " ";
    // }

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            solution[0][i] = allpowers[0][i + 1];
        else
            solution[0][i] = allpowers[0][i - 1];
    }

    // for (int k = 1; k < t - 1; k++)
    // {

    //     for (int gojo = 0; gojo < n; gojo++)
    //     {
    //         int position = gojo / (1 << (k - 1));
    //         if (position % 2 == 0)
    //         {
    //             solution[k][position] = allpowers[k][position + 1] + solution[k][position];
    //         }
    //         else
    //         {
    //             solution[k][position] = allpowers[k][position - 1] + solution[k][position];
    //         }
    //     }
    // }

    // for (auto row : solution)
    // {
    //     for (auto element : row)
    //     {
    //         cout << element << "-";
    //     }
    //     cout << endl;
    // }
    cout << "hi";
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    solve();
    return 0;
}