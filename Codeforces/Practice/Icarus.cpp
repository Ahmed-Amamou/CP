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

struct Node
{
    int left = 0;
    int right = 0;
    int parent = 0;
};

// Simulates movement through the tree following string S and returns the set of visited nodes
set<int> simulatePath(int start, const string &s, vector<Node> &tree)
{
    set<int> visited;
    map<pair<int, int>, bool> statesSeen; // (position, string_index)

    int pos = start;
    int strIdx = 0;

    while (true)
    {
        visited.insert(pos);

        // Check if we've seen this state before (detected a cycle)
        pair<int, int> currentState = {pos, strIdx};
        if (statesSeen[currentState])
            break;
        statesSeen[currentState] = true;

        // If we've visited too many states, we might have an issue
        if (statesSeen.size() > 10000)
            break;

        char move = s[strIdx];
        int nextPos = pos;

        // Try to make the move
        if (move == 'L' && tree[pos].left != 0)
        {
            nextPos = tree[pos].left;
        }
        else if (move == 'R' && tree[pos].right != 0)
        {
            nextPos = tree[pos].right;
        }
        else if (move == 'U' && tree[pos].parent != 0)
        {
            nextPos = tree[pos].parent;
        }

        pos = nextPos;
        strIdx = (strIdx + 1) % s.length();
    }

    return visited;
}

bool isValidTree(const vector<Node> &tree)
{
    int n = tree.size() - 1;
    vector<int> hasParent(n + 1, 0);

    // Check each node's connections
    for (int i = 1; i <= n; i++)
    {
        // Check left child
        if (tree[i].left != 0)
        {
            if (tree[i].left > n || hasParent[tree[i].left])
                return false;
            hasParent[tree[i].left]++;
            if (tree[tree[i].left].parent != i)
                return false;
        }

        // Check right child
        if (tree[i].right != 0)
        {
            if (tree[i].right > n || hasParent[tree[i].right])
                return false;
            hasParent[tree[i].right]++;
            if (tree[tree[i].right].parent != i)
                return false;
        }
    }

    // Make sure each node (except root) has exactly one parent
    int rootCount = 0;
    for (int i = 1; i <= n; i++)
    {
        if (hasParent[i] > 1)
            return false;
        if (hasParent[i] == 0)
            rootCount++;
    }

    return rootCount == 1; // Only one node should have no parent (root)
}

bool tryBuildTree(const string &s, vector<Node> &tree, int &start, int &exit)
{
    int n = s.length() + 1; // Start with string length + 1 nodes
    tree.resize(n + 1, Node());

    // Try different start and exit positions
    for (int root = 1; root <= n; root++)
    {
        for (start = 1; start <= n; start++)
        {
            for (exit = 1; exit <= n; exit++)
            {
                if (start == exit)
                    continue;

                // Clear previous tree connections
                for (int i = 0; i <= n; i++)
                {
                    tree[i].left = tree[i].right = tree[i].parent = 0;
                }

                // Build a simple tree structure that might create cycles
                if (root + 1 <= n)
                {
                    tree[root].left = root + 1;
                    tree[root + 1].parent = root;
                }
                if (root + 2 <= n)
                {
                    tree[root].right = root + 2;
                    tree[root + 2].parent = root;
                }

                // Add some additional connections to create cycles
                for (int i = root + 1; i < n - 1; i++)
                {
                    if (tree[i].left == 0 && i + 2 <= n)
                    {
                        tree[i].left = i + 2;
                        tree[i + 2].parent = i;
                    }
                }

                // Verify tree is valid
                if (!isValidTree(tree))
                    continue;

                // Simulate Icarus's path
                set<int> visitedNodes = simulatePath(start, s, tree);

                // If exit node is not in visited nodes, we found a solution
                if (visitedNodes.find(exit) == visitedNodes.end())
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void solve()
{
    string s;
    cin >> s;

    vector<Node> tree;
    int start, exit;

    // Try to build a valid tree
    if (tryBuildTree(s, tree, start, exit))
    {
        cout << tree.size() - 1 << " " << start << " " << exit << endl;
        // Output the tree structure
        for (int i = 1; i < tree.size(); i++)
        {
            cout << tree[i].left << " " << tree[i].right << endl;
        }
    }
    else
    {
        cout << -1 << endl;
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