#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#define FAst                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
struct Point
{
    int x, y;
};
using namespace std;

// Calculate Euclidean distance between two points
double getDistance(const Point &p1, const Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Calculate stability for a triumvirate
double getStability(const Point &p1, const Point &p2, const Point &p3)
{
    double d1 = getDistance(p1, p2);
    double d2 = getDistance(p2, p3);
    double d3 = getDistance(p3, p1);

    double maxDist = max({d1, d2, d3});
    double minDist = min({d1, d2, d3});

    return maxDist - minDist;
}

// Structure to store a solution
struct Solution
{
    vector<vector<int>> groups;
    double totalStability;
};

Solution findBestSolution(const vector<Point> &points)
{
    int N = points.size();
    vector<int> indices(N);
    for (int i = 0; i < N; i++)
        indices[i] = i;

    Solution bestSolution;
    bestSolution.totalStability = numeric_limits<double>::max();

    do
    {
        // Generate groups of three
        vector<vector<int>> currentGroups;
        double currentTotalStability = 0;

        for (int i = 0; i < N; i += 3)
        {
            vector<int> group = {indices[i], indices[i + 1], indices[i + 2]};
            currentGroups.push_back(group);

            double stability = getStability(
                points[indices[i]],
                points[indices[i + 1]],
                points[indices[i + 2]]);
            currentTotalStability += stability;
        }

        if (currentTotalStability < bestSolution.totalStability)
        {
            bestSolution.groups = currentGroups;
            bestSolution.totalStability = currentTotalStability;
        }

    } while (next_permutation(indices.begin(), indices.end()));

    return bestSolution;
}

int main()
{
    FAst;
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    Solution solution = findBestSolution(points);

    // Output the groups
    for (const auto &group : solution.groups)
    {
        cout << group[0] << " " << group[1] << " " << group[2] << "\n";
    }

    return 0;
}