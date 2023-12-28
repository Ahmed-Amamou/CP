#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;

        char frst = s[0];
        char second = '0';
        for (int j = 1; j < s.size(); ++j) {
            if (s[j] != '0') {
                second = s[j];
                break;
            }
        }
        size_t ind_second = s.find(second, 1);

        if (stoi(s.substr(0, ind_second)) < stoi(s.substr(ind_second))) {
            cout << s.substr(0, ind_second) << " " << s.substr(ind_second) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
