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

class Node
{
public:
    long long sum;      // For sum of values
    int count;          // For number of elements
    long long lazy_set; // For set operations
    long long lazy_add; // For add operations

    Node() : sum(0), count(0), lazy_set(-1), lazy_add(0) {} // Initialize lazy_set to -1 to indicate no operation
};

class SegmentTree
{
private:
    int n;
    vector<Node> tree;

    void build(const vector<int> &arr, int node, int start, int end)
    {
        tree[node].count = end - start + 1;
        if (start == end)
        {
            tree[node].sum = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

    void push_down(int node, int start, int end)
    {
        if (start == end)
        {
            return;
        }

        // Handle set operation
        if (tree[node].lazy_set != -1)
        {
            int mid = (start + end) / 2;
            int left_count = mid - start + 1;
            int right_count = end - mid;

            // Set children's values
            tree[2 * node + 1].sum = tree[node].lazy_set * left_count;
            tree[2 * node + 2].sum = tree[node].lazy_set * right_count;

            // Update children's lazy values
            tree[2 * node + 1].lazy_set = tree[node].lazy_set;
            tree[2 * node + 2].lazy_set = tree[node].lazy_set;
            tree[2 * node + 1].lazy_add = 0;
            tree[2 * node + 2].lazy_add = 0;

            tree[node].lazy_set = -1;
        }

        // Handle add operation
        if (tree[node].lazy_add != 0)
        {
            int mid = (start + end) / 2;
            int left_count = mid - start + 1;
            int right_count = end - mid;

            // Add to children's values
            tree[2 * node + 1].sum += tree[node].lazy_add * left_count;
            tree[2 * node + 2].sum += tree[node].lazy_add * right_count;

            // Update children's lazy values
            tree[2 * node + 1].lazy_add += tree[node].lazy_add;
            tree[2 * node + 2].lazy_add += tree[node].lazy_add;

            tree[node].lazy_add = 0;
        }
    }

public:
    SegmentTree(int size) : n(size)
    {
        tree.resize(4 * n);
    }

    void build(const vector<int> &arr)
    {
        build(arr, 0, 0, n - 1);
    }

    void update_range_set(int node, int start, int end, int l, int r, long long val)
    {
        if (start > r || end < l)
        {
            return;
        }

        if (start >= l && end <= r)
        {
            tree[node].sum = val * (end - start + 1);
            tree[node].lazy_set = val;
            tree[node].lazy_add = 0;
            return;
        }

        push_down(node, start, end);
        int mid = (start + end) / 2;
        update_range_set(2 * node + 1, start, mid, l, r, val);
        update_range_set(2 * node + 2, mid + 1, end, l, r, val);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

    void update_range_add(int node, int start, int end, int l, int r, long long val)
    {
        if (start > r || end < l)
        {
            return;
        }

        if (start >= l && end <= r)
        {
            tree[node].sum += val * (end - start + 1);
            tree[node].lazy_add += val;
            return;
        }

        push_down(node, start, end);
        int mid = (start + end) / 2;
        update_range_add(2 * node + 1, start, mid, l, r, val);
        update_range_add(2 * node + 2, mid + 1, end, l, r, val);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

    long long query_range(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
        {
            return 0;
        }

        if (start >= l && end <= r)
        {
            return tree[node].sum;
        }

        push_down(node, start, end);
        int mid = (start + end) / 2;
        return query_range(2 * node + 1, start, mid, l, r) +
               query_range(2 * node + 2, mid + 1, end, l, r);
    }
};

string format_fraction(long long num, long long den)
{
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
    long long g = gcd(abs(num), abs(den));
    return to_string(num / g) + "/" + to_string(den / g);
}

vector<string> solve(int N, int Q, vector<int> &initial_salaries, vector<vector<ll>> &queries)
{
    // Initialize segment trees for salaries and happiness
    SegmentTree salary_tree(N);
    SegmentTree happiness_tree(N);

    // Build salary tree with initial values
    salary_tree.build(initial_salaries);

    vector<string> result;
    vector<int> prev_salaries = initial_salaries;

    for (const auto &query : queries)
    {
        int query_type = query[0];
        int l = query[1] - 1; // Convert to 0-based indexing
        int r = query[2] - 1; // Convert to 0-based indexing

        if (query_type == 0)
        { // Set salaries
            int c = query[3];
            for (int i = l; i <= r; ++i)
            {
                int old_salary = prev_salaries[i];
                prev_salaries[i] = c;
                if (c > old_salary)
                {
                    happiness_tree.update_range_add(0, 0, N - 1, i, i, 1);
                }
                else if (c < old_salary)
                {
                    happiness_tree.update_range_add(0, 0, N - 1, i, i, -1);
                }
            }
            salary_tree.update_range_set(0, 0, N - 1, l, r, c);
        }
        else if (query_type == 1)
        { // Add to salaries
            int c = query[3];
            for (int i = l; i <= r; ++i)
            {
                int old_salary = prev_salaries[i];
                prev_salaries[i] += c;
                if (c > 0)
                {
                    happiness_tree.update_range_add(0, 0, N - 1, i, i, 1);
                }
                else if (c < 0)
                {
                    happiness_tree.update_range_add(0, 0, N - 1, i, i, -1);
                }
            }
            salary_tree.update_range_add(0, 0, N - 1, l, r, c);
        }
        else if (query_type == 2)
        { // Query average salary
            long long sum_salary = salary_tree.query_range(0, 0, N - 1, l, r);
            int count = r - l + 1;
            result.push_back(format_fraction(sum_salary, count));
        }
        else
        { // Query average happiness
            long long sum_happiness = happiness_tree.query_range(0, 0, N - 1, l, r);
            int count = r - l + 1;
            result.push_back(format_fraction(sum_happiness, count));
        }
    }

    return result;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> initial_salaries(N);
    for (int i = 0; i < N; i++)
    {
        cin >> initial_salaries[i];
    }
    vector<vector<ll>> queries(Q, vector<ll>(4));
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i][0];
        if (queries[i][0] == 0 || queries[i][0] == 1)
        {
            cin >> queries[i][1] >> queries[i][2] >> queries[i][3];
        }
        else
        {
            cin >> queries[i][1] >> queries[i][2];
            queries[i][3] = 0; // Placeholder for uniformity
        }
    }

    vector<string> results = solve(N, Q, initial_salaries, queries);
    for (const auto &res : results)
    {
        cout << res << endl;
    }
}
