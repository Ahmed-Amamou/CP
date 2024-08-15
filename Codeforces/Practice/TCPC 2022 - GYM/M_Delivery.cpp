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
    #define debug(x) cout << #x << ": " << x << endl;

    const double EPS = 0.00000001;
    const ll MOD = 1e9 + 7;
    int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    int lcm(int a, int b) { return a * (b / gcd(a, b)); }

    void solve()
    {
        ll n;
        cin >> n;
        ll x = n;
        ll cnt = 0;
        ll last_x;
        while (true)
        {
            last_x = x;
            if (x % 2 == 1)
                break;
            x = x / 2;
            cnt++;
        }
        if (x == 1)
        {
            cout << -1 << endl;
            return;
        }
        ll right = (last_x + 1) / 2 + (cnt > 0 ? pow(2, cnt) - 1 : 0);
        ll left = (last_x - 1) / 2 + (cnt > 0 ? -(pow(2, cnt) - 1) : 0);
        if (left <= 0)
        {
            left = abs((last_x - 1) / 2 + (cnt > 0 ? -(pow(2, cnt) - 1) : 0)) + 1;
        }
        else
        {
            left = (last_x - 1) / 2 + (cnt > 0 ? -(pow(2, cnt) - 1) : 0);
        }
        cout << left << " " << right << endl;
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