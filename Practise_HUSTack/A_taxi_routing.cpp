#include<bits/stdc++.h>

using namespace std;

const int INF= 1e9;
const int MAX_N= 11;
int c[2*MAX_N+1][2*MAX_N+1];        // c[i][j] là chi phí từ i -> j
int dp[1<<(2*MAX_N)][2*MAX_N+1];    // dp[mask][i] là chi phí nhỏ nhất để đi qua tất cả các thành phố trong mask và kết thúc ở i

int main(){
    int n;  cin >> n;
    int N = 2*n +1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> c[i][j];
        }
    }

    for (int mask=0; mask<(1<<N); ++mask){
        fill(dp[mask], dp[mask]+N, INF);
    }

    // Start from point 0
    dp[1][0] = 0;

    for(int mask=1; mask<(1<<N); ++mask){
        for(int i=0; i<N; ++i){
            if(!mask&(1<<i))    continue;   // i không thuộc mask, bỏ qua
        
            for(int j=0; j<N; ++j){
                if(i==j || !mask&(1<<j))    continue;   // i==j hoặc j không thuộc mask, bỏ qua
                dp[mask][i] = min(dp[mask][i], dp[mask^(1<<i)][j] + c[j][i]);
            }
        }
    }

    int min_cost = INF;
    int final_mask = (1<<N)-1;
    
    for (int i=1; i<N; ++i){
        min_cost = min(min_cost, dp[final_mask][i] + c[i][0]);
    }

    cout << min_cost;
    return 0;
}