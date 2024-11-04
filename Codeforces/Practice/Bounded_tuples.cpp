#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1e18;

// Structure to hold constraint information
struct Constraint {
    ll low, high;
    vector<int> indices;
};

// Check if current assignment satisfies all constraints
bool check_constraints(const vector<ll>& values, const vector<Constraint>& constraints) {
    for (const auto& c : constraints) {
        ll sum = 0;
        for (int idx : c.indices) {
            sum += values[idx - 1];  // -1 because indices are 1-based
            if (sum > INF) return false;  // Check for overflow
        }
        if (sum < c.low || sum > c.high) return false;
    }
    return true;
}

// Check if problem has infinite solutions
bool has_infinite_solutions(int n, const vector<Constraint>& constraints) {
    // Check if any variable is unconstrained
    vector<bool> is_constrained(n, false);
    for (const auto& c : constraints) {
        for (int idx : c.indices) {
            is_constrained[idx - 1] = true;
        }
    }
    
    // If any variable is unconstrained and all constraints have high >= low,
    // we have infinite solutions
    for (int i = 0; i < n; i++) {
        if (!is_constrained[i]) {
            bool all_satisfied = true;
            // Check if we can satisfy all constraints with this variable being arbitrarily large
            vector<ll> test_values(n, 0);
            test_values[i] = INF;
            if (check_constraints(test_values, constraints)) {
                return true;
            }
        }
    }
    return false;
}

// Find maximum possible value for any variable based on constraints
ll find_max_possible_value(const vector<Constraint>& constraints) {
    ll max_val = 0;
    for (const auto& c : constraints) {
        max_val = max(max_val, c.high);
    }
    return max_val;
}

ll solve(int n, vector<Constraint>& constraints) {
    // First check for infinite solutions
    if (has_infinite_solutions(n, constraints)) {
        return -1;  // Special value to indicate infinity
    }
    
    // Find maximum possible value we need to check
    ll max_val = min(find_max_possible_value(constraints), 100LL);
    
    // Use dynamic programming / brute force to count solutions
    ll count = 0;
    vector<ll> values(n, 0);
    
    function<void(int)> generate = [&](int pos) {
        if (pos == n) {
            if (check_constraints(values, constraints)) {
                count = (count + 1) % MOD;
            }
            return;
        }
        
        for (ll val = 0; val <= max_val; val++) {
            values[pos] = val;
            generate(pos + 1);
        }
    };
    
    generate(0);
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<Constraint> constraints;
    for (int i = 0; i < m; i++) {
        ll low, high;
        int k;
        cin >> low >> high >> k;
        
        vector<int> indices(k);
        for (int j = 0; j < k; j++) {
            cin >> indices[j];
        }
        
        constraints.push_back({low, high, indices});
    }
    
    ll result = solve(n, constraints);
    if (result == -1) {
        cout << "infinity\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}