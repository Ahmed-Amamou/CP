#include <bits/stdc++.h>
using namespace std;

vector<int> r;
vector<bool> visited;
vector<int> component_id;
vector<vector<int>> adj;
vector<int> cycle_nodes;

int n;
int max_distance;
void dfs(int u, int parent, vector<int> &stack, vector<bool> &on_stack, int cid)
{
    visited[u] = true;
    component_id[u] = cid;
    on_stack[u] = true;
    stack.push_back(u);
    int v = r[u];
    if (!visited[v])
    {
        dfs(v, u, stack, on_stack, cid);
    }
    else if (on_stack[v])
    {
        // Found a cycle
        int cycle_start = -1;
        for (int i = stack.size() - 1; i >= 0; --i)
        {
            cycle_nodes.push_back(stack[i]);
            if (stack[i] == v)
                break;
        }
    }
    on_stack[u] = false;
    stack.pop_back();
}

void bfs(int cid)
{
    queue<int> q;
    vector<int> distance(n, -1);
    for (int u : cycle_nodes)
    {
        distance[u] = 0;
        q.push(u);
    }
    int max_dist = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (component_id[v] == cid && distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                max_dist = max(max_dist, distance[v]);
                q.push(v);
            }
        }
    }
    // Update global maximum distance
    max_distance = max(max_distance, max_dist);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        cin >> n;
        r.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> r[i];
            r[i]--;
        }
        visited.resize(n, false);
        component_id.resize(n, -1);
        adj.resize(n);
        for (int i = 0; i < n; ++i)
        {
            adj[i].push_back(r[i]);
        }
        int cid = 0;
        max_distance = 0;
        cycle_nodes.clear();
        for (int u = 0; u < n; ++u)
        {
            if (!visited[u])
            {
                vector<int> stack;
                vector<bool> on_stack(n, false);
                dfs(u, -1, stack, on_stack, cid);
                // Perform BFS from cycle_nodes
                bfs(cid);
                cid++;
                cycle_nodes.clear();
            }
        }
        cout << max_distance + 2 << endl;
        // Clean up for next test case
        r.clear();
        visited.clear();
        component_id.clear();
        adj.clear();
    }
    return 0;
}