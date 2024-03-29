/*
 ▄▀▀▄ ▄▄   ▄▀▀█▄   ▄▀▀▄ ▄▀▄  ▄▀▀▀▀▄   ▄▀▀▀▀▄   ▄▀▀█▄▄  
█  █   ▄▀ ▐ ▄▀ ▀▄ █  █ ▀  █ █      █ █      █ █ ▄▀   █ 
▐  █▄▄▄█    █▄▄▄█ ▐  █    █ █      █ █      █ ▐ █    █ 
   █   █   ▄▀   █   █    █  ▀▄    ▄▀ ▀▄    ▄▀   █    █ 
  ▄▀  ▄▀  █   ▄▀  ▄▀   ▄▀     ▀▀▀▀     ▀▀▀▀    ▄▀▄▄▄▄▀ 
 █   █    ▐   ▐   █    █                      █     ▐  
 ▐   ▐            ▐    ▐                      ▐        
*/


#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;


const double EPS = 0.00000001;
const ll MOD = 1e9+7;
int gcd (ll a, ll b) { return b ? gcd (b, a % b) : a;}
int lcm (int a, int b) { return a * (b / gcd(a, b));}
 

 
int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3));

        string period = (hour < 12) ? "AM" : "PM";

        if (hour == 0) {
            hour = 12;
        } else if (hour > 12) {
            hour -= 12;
        }

        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << period << endl;
    }

    return 0;
}