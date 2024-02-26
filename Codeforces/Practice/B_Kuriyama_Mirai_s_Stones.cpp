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
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;


const double EPS = 0.00000001;
const ll MOD = 1e9+7;
int gcd (ll a, ll b) { return b ? gcd (b, a % b) : a;}
int lcm (int a, int b) { return a * (b / gcd(a, b));}
 

void solve()
{   
    ll n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll pref_a[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        pref_a[i] += pref_a[i - 1] + a[i - 1];
    }


    sort(a, a + n);
    ll sorted_pref_a[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        sorted_pref_a[i] += sorted_pref_a[i - 1] + a[i - 1];
    }


    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int type, l, r;
        cin >> type >> l >> r;
        // cout << type << " " << l << " " << r << endl;
        if (type == 1)
        {
            cout << pref_a[r] - pref_a[l-1] << endl;
        }
        else
        {
            cout << sorted_pref_a[r ] - sorted_pref_a[l-1] << endl;
        }
    }
}

int main()
{   FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)

    solve();
    return 0;
}
