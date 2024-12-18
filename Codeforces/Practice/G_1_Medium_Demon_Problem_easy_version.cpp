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
const ll MAXN = 200005;

vector<ll> graph[MAXN];
ll visited[MAXN], scc_id[MAXN], idx[MAXN], lowlink[MAXN];
ll chain_length[MAXN]; 
bool in_cycle[MAXN];
stack<ll> st;
ll timer = 0, scc_count = 0;

void tarjan(ll u)
{
    idx[u] = lowlink[u] = ++timer;
    visited[u] = 1;
    st.push(u);

    ll v = graph[u][0];
    if (!visited[v])
    {
        tarjan(v);
        lowlink[u] = min(lowlink[u], lowlink[v]);
    }
    else if (!scc_id[v])
    {
        lowlink[u] = min(lowlink[u], idx[v]);
    }

    if (idx[u] == lowlink[u])
    { // Found SCC
        ++scc_count;
        ll node;
        bool is_cycle = false;
        vector<ll> members;

        do
        {
            node = st.top();
            st.pop();
            scc_id[node] = scc_count;
            members.push_back(node);
        } while (node != u);

        // Mark cycle nodes
        if (members.size() > 1 || graph[members[0]][0] == members[0])
        {
            is_cycle = true;
        }
        for (ll x : members)
            in_cycle[x] = is_cycle;
    }
}

//using Memoization for a better complexity #blhy imchy yarhem bouk
ll dfs_chain(ll u)
{
    if (in_cycle[u])
        return 0;
    if (chain_length[u] != -1)
        return chain_length[u]; // Return cached result

    ll v = graph[u][0];
    return chain_length[u] = 1 + dfs_chain(v);
}

void solve()
{
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        graph[i].clear();
        visited[i] = scc_id[i] = idx[i] = lowlink[i] = 0;
        chain_length[i] = -1; // Reset memoization array
        in_cycle[i] = false;
    }
    while (!st.empty())
        st.pop();
    timer = scc_count = 0;

    // Input edges
    for (ll i = 1; i <= n; i++)
    {
        ll r;
        cin >> r;
        graph[i].push_back(r);
    }

    // Step 1: Find SCCs using Tarjan's Algorithm
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
            tarjan(i);
    }

    // Step 2: Calculate the longest chains leading into cycles
    ll max_chain_length = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!in_cycle[i])
        { // Calculate chain length for nodes outside cycles
            max_chain_length = max(max_chain_length, dfs_chain(i));
        }
    }

    // Result: longest chain + 2 (nodes in the cycle)
    cout << max_chain_length + 2 << endl;
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
