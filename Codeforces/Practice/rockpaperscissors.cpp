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
int compare(string player1, string player2)
{
    if (player1 == player2)
    {
        return 0; // Tie
    }
    else if ((player1 == "rock" && player2 == "scissors") || (player1 == "scissors" && player2 == "paper") || (player1 == "paper" && player2 == "rock"))
    {
        return 1; // Player 1 wins
    }
    else
    {
        return -1; // Player 2 wins
    }
}

signed main()
{
    FAST;
    ll tt = 2;

    while (true)
    {
        // string line;
        int n, k;
        cin >> n;

        map<int, pair<int, int>> mp;
        if (n == 0)
        {
            break;
        }
        cin >> k;

        // stringstream ss(line);
        // ss >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            mp[i] = make_pair(0, 0);
        }

        for (int i = 0; i < k * (n * (n - 1)) / 2; i++)
        {
            int p1, p2;
            string hit1, hit2;
            cin >> p1 >> hit1 >> p2 >> hit2;
            // cout << p1 << " " << hit1 << " " << p2 << " " << hit2 << endl;
            switch (compare(hit1, hit2))
            {
            case 1:
                mp[p1].first++;
                mp[p2].second++;
                break;
            case -1:
                mp[p2].first++;
                mp[p1].second++;
                break;
            default:
                break;
            }
        }
        for (auto it : mp)
        {
            int wins, losses;
            wins = it.second.first;
            losses = it.second.second;
            // cout << wins << " " << losses << endl;
            if (wins == 0 && losses == 0)
            {
                cout << "-" << endl;
            }
            else
            {
                float res = (float)wins / (float)(wins + losses);
                cout << fixed << setprecision(3) << res << endl;
            }
        }
        cout << endl;
    }
    return 0;
}