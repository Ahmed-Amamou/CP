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
pair<int, int> findFirstAndLastOccurrence(const string &str, char target)
{
    int firstOccurrence = -1;
    int lastOccurrence = -1;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == target)
        {
            if (firstOccurrence == -1)
            {
                firstOccurrence = i;
            }
            lastOccurrence = i;
        }
    }

    return {firstOccurrence, lastOccurrence};
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> pos = findFirstAndLastOccurrence(s, 'B');
    if (pos.second - pos.first == 0)
        cout << 1 << endl;
    else if (pos.second == -1 && pos.first == -1)
        cout << 0 << endl;
    else
        cout << pos.second - pos.first +1 << endl;
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