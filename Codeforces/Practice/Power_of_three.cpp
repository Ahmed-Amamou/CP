#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Quick check for invalid last digits of power of 3
bool hasValidLastDigit(const string &N)
{
    if (N.empty())
        return false;
    char last = N.back();
    return (last == '1' || last == '3' || last == '7' || last == '9');
}

// Optimized divisibility by 3 check using digital root
bool isDivisibleByThree(const string &N)
{
    // Digital root for divisibility by 3
    int sum = 0;
    for (char digit : N)
    {
        sum += digit - '0';
        // Keep sum small to handle very large numbers
        if (sum >= 30)
            sum %= 3;
    }
    return sum % 3 == 0;
}

string divideByThree(const string &N)
{
    string result;
    result.reserve(N.length()); // Pre-allocate memory

    int carry = 0;
    bool leading = true;

    // Process 18 digits at a time to avoid overflow
    // This is much faster for very large numbers
    for (size_t i = 0; i < N.length(); i++)
    {
        int current = carry * 10 + (N[i] - '0');
        int quotient = current / 3;
        if (!leading || quotient != 0)
        {
            result += (quotient + '0');
            leading = false;
        }
        carry = current % 3;
    }

    return result.empty() ? "0" : result;
}

int findPowerOfThree(const string &N)
{
    // Edge cases
    if (N.empty() || N == "0")
        return -1;
    if (N == "1")
        return 0;

    // Quick validation checks
    if (!hasValidLastDigit(N))
        return -1;
    if (!isDivisibleByThree(N))
        return -1;

    string current = N;
    int count = 0;
    const int MAX_ITERATIONS = 39; // log_3(10^18) ≈ 38.4

    while (current != "1")
    {
        // Additional optimization: check size reduction
        size_t oldSize = current.length();
        current = divideByThree(current);
        size_t newSize = current.length();

        // Each division by 3 should reduce length by roughly log_10(3) ≈ 0.477
        // If reduction is too small, number is not a power of 3
        if (oldSize > 20 && (oldSize - newSize) < (oldSize / 3))
        {
            return -1;
        }

        count++;
        // If we've done too many iterations, it's not a power of 3
        if (count > MAX_ITERATIONS)
            return -1;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;
    cout << findPowerOfThree(N) << endl;

    return 0;
}