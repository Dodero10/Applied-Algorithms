#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;

int main() {
    cin >> n >> m;
    a.resize(n+1, vector<int>(m+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    int dp[n+1][m+1];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            dp[i][j] = INT_MAX;
        }
    }
    
    dp[1][1] = a[1][1];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) continue;

            if (i > 1 && dp[i-1][j] != INT_MAX) 
                dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i][j]);
            
            if (j > 1 && dp[i][j-1] != INT_MAX) 
                dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i][j]);
            
            if (i > 1 && j > 1 && dp[i-1][j-1] != INT_MAX) 
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i][j]);
        }
    }
    
    int res = dp[n][m];
    
    if (res == INT_MAX) cout << -1;
    else cout << res;
    
    return 0;
}
