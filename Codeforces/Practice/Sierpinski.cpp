#include <iostream>
#include <vector>
using namespace std;

// Function to brute-force check if a point is red or blue
int isRedBruteForce(long long x, long long y)
{
    while (x > 2)
    {
        long long halfSize = (x + 1) / 2;

        if (y > halfSize)
        {
            // If y is in the right triangle, adjust y to the new coordinate space
            y -= halfSize;
        }
        else if (y <= x - halfSize)
        {
            // If y is within the inverted blue triangle, return 0 (blue)
            return 0;
        }

        // Move to the next level down
        x = halfSize;
    }
    return 1; // The top level points are red
}

int main()
{
    int Q;
    cin >> Q;
    vector<int> results;
    for (int i = 0; i < Q; ++i)
    {
        long long x, y;
        cin >> x >> y;
        results.push_back(isRedBruteForce(x, y));
    }

    // Output all results
    for (int result : results)
    {
        cout << result << endl;
    }

    return 0;
}
