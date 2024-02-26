#include <iostream>
    #include <vector>
    #include <map>

    typedef long long ll;
    typedef vector<ll> v32;

    void solve(){
        ll n,k;
        cin >> n >> k;
        v32 y(n);
        map<ll,ll> p;
        ll s = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> y[i];
        }

        for(int j = 0; j < n; j++) {
            ll k;
            cin >> k;
            p[abs(k)] += y[j];
        }

        for(auto& dddd : p) {
            s += dddd.second;
            dddd.second = s;
        }

        bool ans = true;
        for(const auto& pair : p) {
            if(pair.first * k < pair.second) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    int main() {
        ll t;
        cin >> t;
        for(int it = 1; it <= t; it++) {
            solve();
        }
        return 0;
    }