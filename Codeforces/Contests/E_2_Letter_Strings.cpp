#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> strings(n);
        
        // Read all strings
        for (int i = 0; i < n; i++) {
            cin >> strings[i];
        }

        long long result = 0;
        unordered_map<string, int> mask_count;

        for (int i = 0; i < n; i++) {
            string s = strings[i];
            
            // Generate masked versions
            for (int pos = 0; pos < 2; pos++) {
                string masked = s;
                masked[pos] = '*'; // Mask one character
                
                // Count how many times this masked version has been seen
                result += mask_count[masked];
                
                // Update the count for this masked version
                mask_count[masked]++;
            }
        }

        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
