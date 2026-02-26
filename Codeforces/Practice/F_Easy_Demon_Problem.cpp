#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

// Precompute divisors for all |x| up to 200,000
vector<vector<long long>> precompute_divisors(long long max_x)
{
    vector<vector<long long>> divisors(max_x + 1);
    for (long long x = 1; x <= max_x; ++x)
    {
        long long sqrt_x = static_cast<long long>(sqrt(x)) + 1;
        for (long long i = 1; i <= sqrt_x; ++i)
        {
            if (x % i == 0)
            {
                divisors[x].push_back(i);
                divisors[x].push_back(-i);
                divisors[x].push_back(x / i);
                divisors[x].push_back(-(x / i));
            }
        }
    }
    return divisors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, q;
    cin >> n >> m >> q;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (long long j = 0; j < m; ++j)
    {
        cin >> b[j];
    }

    long long sum_a = 0;
    for (long long val : a)
    {
        sum_a += val;
    }

    long long sum_b = 0;
    for (long long val : b)
    {
        sum_b += val;
    }

    // Precompute S1 and S2
    unordered_set<long long> S1;
    for (long long val : b)
    {
        S1.insert(sum_b - val);
    }

    unordered_set<long long> S2;
    for (long long val : a)
    {
        S2.insert(sum_a - val);
    }

    // Precompute divisors for all |x| up to 200,000
    const long long MAX_X = 200000;
    vector<vector<long long>> divisors(MAX_X + 1);
    for (long long x = 1; x <= MAX_X; ++x)
    {
        long long sqrt_x = static_cast<long long>(sqrt(x)) + 1;
        for (long long i = 1; i <= sqrt_x; ++i)
        {
            if (x % i == 0)
            {
                divisors[x].push_back(i);
                divisors[x].push_back(-i);
                divisors[x].push_back(x / i);
                divisors[x].push_back(-(x / i));
            }
        }
    }

    // Process each query
    while (q--)
    {
        long long x;
        cin >> x;
        if (x == 0)
        {
            // Check if (sum_b - b[c]) * (sum_a - a[r]) = 0
            // This happens if sum_b - b[c] = 0 or sum_a - a[r] = 0
            // i.e., b[c] = sum_b or a[r] = sum_a
            bool b_has_sum_b = S1.find(0) != S1.end();
            bool a_has_sum_a = S2.find(0) != S2.end();
            if (b_has_sum_b || a_has_sum_a)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }
        // Retrieve precomputed divisors for |x|
        long long abs_x = abs(x);
        if (abs_x > MAX_X)
        {
            // x is out of precomputed range, compute divisors on the fly
            vector<long long> temp_divisors;
            long long sqrt_abs_x = static_cast<long long>(sqrt(abs_x)) + 1;
            for (long long i = 1; i <= sqrt_abs_x; ++i)
            {
                if (abs_x % i == 0)
                {
                    temp_divisors.push_back(i);
                    temp_divisors.push_back(-i);
                    temp_divisors.push_back(abs_x / i);
                    temp_divisors.push_back(-(abs_x / i));
                }
            }
            // Check each divisor
            bool found = false;
            for (long long d : temp_divisors)
            {
                if (S1.find(d) != S1.end())
                {
                    long long y = x / d;
                    if (S2.find(y) != S2.end())
                    {
                        found = true;
                        break;
                    }
                }
            }
            cout << (found ? "YES" : "NO") << endl;
            continue;
        }
        // Use precomputed divisors
        bool found = false;
        for (long long d : divisors[abs_x])
        {
            if (x / d != 0 && d * (x / d) == x)
            {
                if (S1.find(d) != S1.end())
                {
                    long long y = x / d;
                    if (S2.find(y) != S2.end())
                    {
                        found = true;
                        break;
                    }
                }
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}