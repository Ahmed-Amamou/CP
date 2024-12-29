#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    const int NMAX = 1e8 + 1;
    vector<int> cnt(NMAX); // Replace int cnt[NMAX] with vector<int> cnt(NMAX)
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    int number_of_distinct = 0;
    for (int i = 0; i < NMAX; i++)
    {
        if (cnt[i] != 0)
            number_of_distinct++;
    }
    cout << number_of_distinct << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--)
    solve();
    return 0;
}