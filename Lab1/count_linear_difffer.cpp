#include<bits/stdc++.h>
using namespace std;

int n, M;

int main(){
    cin >> n >> M;
    int a[n+1];
    for(int i=1; i<=n; i++)  cin >> a[i];
    
    vector<vector<int>> dp(n+1, vector<int> (M+1, 0));
    
    int j=0;
    while(j<=M){
        dp[1][j] = 1;
        j += a[1];
    }
    
    for(int i=1; i<=n; i++){
        dp[i][0] = 1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=M; j++){
            int k = j;
            while(k>=0){
                dp[i][j] = (dp[i][j] + dp[i-1][k]);
                k = k - a[i];
            }
        }
    }
    
    cout << dp[n][M];
    
    return 0;
}