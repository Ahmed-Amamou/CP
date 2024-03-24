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
double euclideanDistance(pair<double, double> p1, pair<double, double> p2)
{
    double xDiff = p2.first - p1.first;
    double yDiff = p2.second - p1.second;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
} 
void solve(){
    double  x, y;
    int n;
    cin >> n >> x >> y;
    ll count =0;
    vector<string> winners; 
    while(n--){
        string name;
        double x1,y1,d;
        cin >> name>>x1 >>y1>>d;
        // cout <<" " <<x1 <<" "<< y1 <<" "<<d;
        // cout << euclideanDistance(make_pair(x,y),make_pair(x1,y1))<<endl;
        if(euclideanDistance(make_pair(x,y),make_pair(x1,y1))<=d){
            count ++;
            winners.push_back(name);
        }
    }
    sort(winners.begin(),winners.end());
    if(count ==0){
        cout << "I WIN!!!"<<endl;
        return;
    }
    cout << count <<endl;
    for (int i = 0; i < count; i++)
    {
        cout << winners[i]<<endl;
    }
    
}
 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
//   cin >> tt;
//   while (tt--) 
  solve();
  return 0;
}