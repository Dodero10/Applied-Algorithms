#include<bits/stdc++.h>
using namespace std;

int res = 0;
int n, m;
int a[1005][1005];

int maxLeft(int i, int j){
    int tmp = j;
    while(tmp>0 && a[i][j] <=a[i][tmp]){
        tmp--;
    }
    return tmp+1;
}

int maxRight(int i, int j){
    int tmp = j;
    while(tmp<=m && a[i][j] <=a[i][tmp]){
        tmp++;
    }
    return tmp-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j]!=0)  a[i][j] += a[i-1][j];
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            res = max(res, a[i][j]*(-maxLeft(i, j) +maxRight(i, j)+1));
        }
    }
    
    cout << res;
}