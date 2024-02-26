//...............................................................................................................
//.HHHHH.....HHHHH......AAAAAAA.......MMMMMMM....MMMMMMM.....OOOOOOOOOO.........OOOOOOOOOO.....DDDDDDDDDDDDD.....
//.HHHHH.....HHHHH......AAAAAAA.......MMMMMMM....MMMMMMM....OOOOOOOOOOOOO.....OOOOOOOOOOOOO....DDDDDDDDDDDDDD....
//.HHHHH.....HHHHH......AAAAAAAA......MMMMMMM....MMMMMMM...OOOOOOOOOOOOOOO...OOOOOOOOOOOOOOO...DDDDDDDDDDDDDDD...
//.HHHHH.....HHHHH.....AAAAAAAAA......MMMMMMM...MMMMMMMM..OOOOOOOO.OOOOOOO...OOOOOOO.OOOOOOOO..DDDDD..DDDDDDDD...
//.HHHHH.....HHHHH.....AAAAAAAAA......MMMMMMMM..MMMMMMMM..OOOOOO.....OOOOOO.OOOOOO.....OOOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH.....AAAAAAAAAA.....MMMMMMMM..MMMMMMMM.MOOOOO......OOOOOO.OOOOO.......OOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH....AAAAA.AAAAA.....MMMMMMMM.MMMMMMMMM.MOOOOO.......OOOOO.OOOOO.......OOOOOO.DDDDD......DDDDD..
//.HHHHHHHHHHHHHHH....AAAAA.AAAAAA....MMMMMMMMMMMMMMMMMM.MOOOO........OOOOO.OOOOO........OOOOO.DDDDD......DDDDD..
//.HHHHHHHHHHHHHHH...AAAAAA..AAAAA....MMMMMMMMMMMMMMMMMM.MOOOO........OOOOO.OOOOO........OOOOO.DDDDD......DDDDD..
//.HHHHHHHHHHHHHHH...AAAAA...AAAAA....MMMMMMMMMMMMMMMMMM.MOOOO........OOOOO.OOOOO........OOOOO.DDDDD......DDDDD..
//.HHHHH.....HHHHH...AAAAAAAAAAAAAA...MMMMMMMMMMMMMMMMMM.MOOOOO.......OOOOO.OOOOO.......OOOOOO.DDDDD......DDDDD..
//.HHHHH.....HHHHH..HAAAAAAAAAAAAAA...MMMMMMMMMMMMMMMMMM.MOOOOO......OOOOOO.OOOOOO......OOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH..HAAAAAAAAAAAAAA...MMMMMMMMMMMM.MMMMM..OOOOOO.....OOOOOO.OOOOOO.....OOOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH..HAAAA.....AAAAAA..MMMMM.MMMMMM.MMMMM..OOOOOOOOOOOOOOOO...OOOOOOO.OOOOOOOO..DDDDD...DDDDDDD...
//.HHHHH.....HHHHH.HHAAAA......AAAAA..MMMMM.MMMMMM.MMMMM...OOOOOOOOOOOOOOO...OOOOOOOOOOOOOOO...DDDDDDDDDDDDDDD...
//.HHHHH.....HHHHH.HHAAA.......AAAAAA.MMMMM.MMMMMM.MMMMM....OOOOOOOOOOOOO.....OOOOOOOOOOOOO....DDDDDDDDDDDDDD....
//.HHHHH.....HHHHH.HHAAA.......AAAAAA.MMMM..MMMMM..MMMMM.....OOOOOOOOOO.........OOOOOOOOOO.....DDDDDDDDDDDD......
//...............................................................................................................

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

double euclideanDistance(pair<double, double> p1, pair<double, double> p2)
{
    double xDiff = p2.first - p1.first;
    double yDiff = p2.second - p1.second;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

void solve()
{
    ll n, m, x;
    cin >> n >> m >> x;
    vector<pair<double, double>> S_positions;
    map<char, vector<pair<double, double>>> keyboard;
    map<char, double> best_distance_to_key;
    for (double i = 0; i < n; i++)
    {
        for (double j = 0; j < m; j++)
        {
            char key;
            cin >> key;
            if (key == 'S')
                S_positions.push_back(make_pair(i, j));
            else
            {
                if (keyboard.find(key) != keyboard.end())
                {
                    keyboard[key].push_back(make_pair(i, j));
                }
                else
                {
                    vector<pair<double, double>> v;
                    v.push_back(make_pair(i, j));
                    keyboard[key] = v;
                }
            }
        }
    }
    cout << endl;
    for (auto &pos : S_positions)
    {
        for (auto &pair : keyboard) // Change from const auto& pair to auto& pair
        {   if(best_distance_to_key.find(pair.first) == best_distance_to_key.end()) best_distance_to_key[pair.first] = 1e9;
            for (int i = 0; i < pair.second.size(); i++)
            {
                double distance = euclideanDistance(pos, pair.second[i]);
                best_distance_to_key[pair.first] = min(distance, best_distance_to_key[pair.first]);
                // cout << "Comparing distance between position (" << pos.first << ", " << pos.second << ") and key " << pair.first << " at position (" << pair.second[i].first << ", " << pair.second[i].second << "): " << distance << endl;
            }
        }
    }

    ll l;
    cin >> l;
    string s;
    cin >> s;
    ll sum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if ((keyboard.find(tolower(s[i])) == keyboard.end()) || (isupper(s[i]) && S_positions.size() == 0))
        {
            cout << -1 << endl;
            return;
        }
        if (isupper(s[i]) && best_distance_to_key[tolower(s[i])] > x)
        {
            sum += 1;
        }
    }

    cout << sum << endl;
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