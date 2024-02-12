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
// ll n, tab[N], dp[N][2];
// vector<int> adj[N];
// bool vis[N][2];
int gcd (ll a, ll b) { return b ? gcd (b, a % b) : a;}
int lcm (int a, int b) { return a * (b / gcd(a, b));}
char grid[26][26];
bool visited[26][26];
// void dfs(vector<vector<int>>& graph, bool visited[], int s, vector<int>& component) {
//     visited[s] = true;
//     component.push_back(s);
//     for (unsigned i = 0; i < graph[s].size(); i++) {
//         if (!visited[graph[s][i]]) {
//             dfs(graph, visited, graph[s][i], component);
//         }
//     }
// }
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int n;
bool valid(int i, int j) {
    return i < n && i >= 0 && j < n && j >= 0;
}
    
void dfs(int i, int j) {
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int xc = i + dx[k];
        int yc = j + dy[k];
        if (valid(xc, yc) && !visited[xc][yc] && grid[xc][yc] == '1') {
            dfs(xc, yc);
        }
    }
}


int main(){
    FAST;
    int number = 1;
    
    // cout << "heelo";
    while(scanf("%d",&n)!=EOF){
    
    
    memset(visited, false, sizeof(visited)); // Set all elements of visited to false
    for (int i = 0; i < n; i++)
    {
        scanf("%s",grid[i]);      
    }
    int count =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            
        { 
            if(!visited[i][j] && grid[i][j]=='1' )
                {   
                    dfs(i,j);
                    count ++;                 
                }
        }
        
        
        
        
    }
    
     cout <<"Image number "<< number++<< " contains "<<  count <<" war eagles." << endl;
    }
    return 0;
}