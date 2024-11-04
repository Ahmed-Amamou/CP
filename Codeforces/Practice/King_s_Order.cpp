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
    int N, M;
    cin >> N >> M;
    vector<int> groupId(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> groupId[i];
    }
    vector<vector<int>> adj(N + 1);
    vector<int> inDegree(N + 1, 0);

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        inDegree[B]++;
    }

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;

    for (int i = 1; i <= N; ++i)
    {
        if (inDegree[i] == 0)
        {
            pq.push(make_tuple(groupId[i], i));
        }
    }

    vector<int> order;

    while (!pq.empty())
    {
        auto [grp, proj] = pq.top();
        pq.pop();
        order.push_back(proj);
        for (int neighbor : adj[proj])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                pq.push(make_tuple(groupId[neighbor], neighbor));
            }
        }
    }
    //cycle detection
    if (order.size() != N)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int proj : order)
        {
            cout << proj << " ";
        }
        cout << endl;
    }
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    // cin >> tt;
    // while (tt--)
        solve();
    return 0;
}