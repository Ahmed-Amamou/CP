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
// divs[i] : holds a list of all the prime divisors of integer "i".

/**
 * Generates all the prime divisors of the integers from 1 to "n".
 * After calling this function, "primeDivs[i]" will contains all the prime divisors of integer "i".
 *
 * Complexity: O(n.log(log(n)))
 */
vector<int> generatePrimeDivisors(int n)
{
    vector<vector<int>> primeDivs = vector<vector<int>>(n + 1);

    for (int i = 2; i <= n; ++i)
    {
        if (primeDivs[i].size())
            continue;

        for (int j = i; j <= n; j += i)
        {
            primeDivs[j].push_back(i);
        }
    }
    return primeDivs[n];
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> items = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    // get primes of k
    auto k_factors = generatePrimeDivisors(k);

    auto k_sets = 
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    solve();
    return 0;
}