#include<bits/stdc++.h>
using namespace std;
#define MAX 25

int n, num_pass=0;
int c[MAX][MAX];
int visited[MAX] = {false};
int best = INT_MAX;
int curr = 0;
// int mark[MAX];

void Try(int k){
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            if(curr + c[k][i] + c[i][0] >= best)    continue;
            visited[i] = true;
            num_pass++;
            curr += (c[k][i] + c[i][i+n]);
            if(num_pass==n)
                best = min(best, curr + c[i+n][0]);
            else Try(i+n);
            visited[i] = false;
            num_pass--;
            curr -= (c[k][i] + c[i][i+n]);
        }
    }
}

int main(){
    cin >> n;
    for (int i=0; i<2*n+1; i++){
        for (int j=0; j<2*n+1; j++){
            cin >> c[i][j];
        }
    }
    Try(0);
    cout << best;
    return 0;
}