#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution
{
private:
    // Function to calculate last multiple less than or equal to n
    ll lastMultiple(ll num, ll n)
    {
        return (n / num) * num;
    }

    // Function to merge two ranges of multiples
    void mergeRanges(vector<pair<ll, ll>> &ranges)
    {
        if (ranges.empty())
            return;

        sort(ranges.begin(), ranges.end());
        vector<pair<ll, ll>> merged;
        merged.push_back(ranges[0]);

        for (int i = 1; i < ranges.size(); i++)
        {
            if (merged.back().second + 1 >= ranges[i].first)
            {
                merged.back().second = max(merged.back().second, ranges[i].second);
            }
            else
            {
                merged.push_back(ranges[i]);
            }
        }
        ranges = merged;
    }

public:
    ll solve(ll n, int k, vector<ll> &elasticity)
    {
        // Handle edge cases
        if (n <= 0 || k == 0)
            return 0;
        if (k == 1)
        {
            return n / elasticity[0];
        }

        // Store ranges of tiles hit for each elasticity
        vector<pair<ll, ll>> ranges;

        // For each elasticity, find all multiples up to n
        for (ll e : elasticity)
        {
            if (e > n)
                continue; // Skip if elasticity is larger than n

            ll first = e;                 // First multiple
            ll last = lastMultiple(e, n); // Last multiple <= n

            // Add all continuous ranges formed by this elasticity
            for (ll start = first; start <= last; start += e)
            {
                ranges.push_back({start, start});
            }
        }

        // Merge overlapping ranges
        mergeRanges(ranges);

        // Count total tiles hit
        ll result = 0;
        for (const auto &range : ranges)
        {
            result += (range.second - range.first + 1);
        }

        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int k;
    cin >> n >> k;

    vector<ll> elasticity(k);
    for (int i = 0; i < k; i++)
    {
        cin >> elasticity[i];
    }

    Solution solution;
    cout << solution.solve(n, k, elasticity) << endl;

    return 0;
}