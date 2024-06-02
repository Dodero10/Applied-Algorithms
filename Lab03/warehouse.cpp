#include<bits/stdc++.h>
using namespace std;

int N, T, D, res=0;
vector<int> a;
vector<int> t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> T >> D;
    a.resize(N);
    t.resize(N);
    
    for(int& x : a) cin >> x;
    for(int& y : t) cin >> y;
    
    vector<vector<int>> dp(N, vector<int>(T+1, 0));
    
    for(int i=0; i<N; i++){
        if(t[i]<=T){
            dp[i][t[i]] = max(dp[i][t[i]], a[i]);
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=1; j<=T; j++){
            if(dp[i][j]){
                for(int k=i+1; k<=min(N-1, i+D); k++){
                    if(j+t[k] <= T){
                        dp[k][j+t[k]] = max(dp[k][j+t[k]], dp[i][j] + a[k]);
                    }
                }
            }
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=1; j<=T; j++){
            res = max(dp[i][j], res);
        }
    }
    
    cout << res;
    
    return 0;
}