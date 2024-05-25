#include <bits/stdc++.h>
#include <algorithm> // Include the necessary header file

using namespace std;
//Longest Increasing Subsequence
int main(){
    string s;
    cin >> s;
    int n = s.size(); 
    vector<int> DP(n,1);
    for(int i=n-1;i>=0;i-- ){
        for(int j= i;j<n;j++){
            if(s[i]<s[j]){
                DP[i]=max(DP[i],1+DP[j]);
            }
        }
    }
    cout << 26 - *max_element(DP.begin(),DP.end()); 
    
    return 0;
    
}