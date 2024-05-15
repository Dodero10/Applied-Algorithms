#include<bits/stdc++.h>
using namespace std;

int parti[1001][1001];
int n;



int main(){
    cin >> n;
    for(int i=0; i<=n; i++){
        parti[0][i] = 0;
        parti[i][0] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j>=i){
                parti[i][j] = parti[i-j][j] + parti[i][j-1];
            }
            else{
                parti[i][j] = parti[i][j-1];
            }
        }
    }

    return 0;
}