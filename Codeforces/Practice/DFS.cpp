#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
 
const double EPS = 0.00000001;
const ll N = 5e5 + 20, MOD = 1e9+7;
ll n, tab[N], dp[N][2];
vector<int> adj[N];
bool vis[N][2];
int gcd (ll a, ll b) { return b ? gcd (b, a % b) : a;}
int lcm (int a, int b) { return a * (b / gcd(a, b));}

vector<vector<int>> read_graph(int n,int e){
    vector<vector<int>> v(n);
    while (e--){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    return v;
} 




void dfs(vector<vector<int>>& graph, bool visited[], int s, vector<int>& component) {
    visited[s] = true;
    component.push_back(s);
    for (unsigned i = 0; i < graph[s].size(); i++) {
        if (!visited[graph[s][i]]) {
            dfs(graph, visited, graph[s][i], component);
        }
    }
}

vector<vector<int>> findConnectedComponents(vector<vector<int>>& graph) {
    int n = graph.size();
    bool visited[n] = {false};
    vector<vector<int>> components;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(graph, visited, i, component);
            components.push_back(component);
        }
    }
    return components;
}




 
signed main(){
  FAST;
  ll tt = 1;
  // freopen("input.in", "r", stdin);
//   cin >> tt;
//   while (tt--) 
    vector<vector<int>> v= read_graph(9,11);
    // for(int i = 0; i < 6; i++)
    // {   cout<<i<<": ";
    //     for (unsigned j = 0; j < v[i].size(); j++)
    //     {
    //         cout<< v[i][j]<< " ";
    //     }
    //     cout<< endl;
    // }
    
     cout <<" the connected components are :"<<endl;
     bool visited[9]={false};
     vector<vector<int>> components;
     components=findConnectedComponents(v);
     for(unsigned i =0 ; i< components.size(); i++){
            cout << "-------"<< endl;
            for(unsigned j = 0; j < components[i].size();j++ ) 
                cout << components[i][j]<< " ";
     }      cout << endl;
     

     

    
   
  return 0;
}