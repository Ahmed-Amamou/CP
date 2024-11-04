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

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }

    int countComponents()
    {
        set<int> components;
        for (int i = 0; i < parent.size(); i++)
            components.insert(find(i));
        return components.size();
    }
};

vector<int> solve(string &S)
{
    int N = S.length();
    vector<int> result(N, INT_MAX);

    // Try all possible substring lengths
    for (int len = 1; len <= N; len++)
    {
        // Try all possible substrings of current length
        for (int i = 0; i <= N - len; i++)
        {
            string T = S.substr(i, len);
            UnionFind uf(N);

            // Find all occurrences of T in S and build bridges
            for (int j = 0; j <= N - len; j++)
            {
                if (S.substr(j, len) == T)
                {
                    // Connect islands j to j+len-1
                    for (int k = j; k < j + len - 1; k++)
                    {
                        uf.unite(k, k + 1);
                    }
                }
            }

            int components = uf.countComponents();
            result[components - 1] = min(result[components - 1], len);
        }
    }

    // Replace INT_MAX with 0 for impossible cases
    for (int i = 0; i < N; i++)
    {
        if (result[i] == INT_MAX)
            result[i] = 0;
    }

    return result;
}


signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    string S;
    cin >> S;

    vector<int> result = solve(S);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}