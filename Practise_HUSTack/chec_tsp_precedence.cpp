#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int x[1005];
    int x1[1005];
    
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        x1[i] = a;
        x[a] = i;
    }
    
    int d[n+1][n+1];
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> d[i][j];
        }
    }
    
    int m;
    cin >> m;
    bool isValid = true;
    int cost = 0;
    
    for(int i=0; i<m; i++){
        int b, c;
        cin >> b >> c;
        if(x[b]>x[c]){
            isValid = false;
            break;
        }
    }
    
    if(!isValid)    cout << -1;
    else{
        for(int i=2; i<=n; i++){
            cost += d[x1[i-1]][x1[i]];
        }
        cout << cost + d[x1[n]][x1[1]];
    }
    return 0;
}