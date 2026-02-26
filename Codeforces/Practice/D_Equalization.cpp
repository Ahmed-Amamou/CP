#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;

        // Find the largest common ancestor T
        ll tx = x, ty = y;
        ll a = 0, b = 0;
        while (tx != ty)
        {
            if (tx > ty)
            {
                tx >>= 1;
                a++;
            }
            else
            {
                ty >>= 1;
                b++;
            }
        }

        // Assign shifts greedily
        ll cost = 0;
        ll shift = 1;
        while (a > 0 || b > 0)
        {
            if (a > 0)
            {
                cost += shift;
                a--;
            }
            if (b > 0)
            {
                cost += shift;
                b--;
            }
            shift <<= 1;
        }

        cout << cost << '\n';
    }
    return 0;
}