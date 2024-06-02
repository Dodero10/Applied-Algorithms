#include<bits/stdc++.h>
using namespace std;

int n, K1, K2;
int rest[1001] = {0};
int work[1001] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> K1 >> K2;
    
    rest[1] = 1;
    // work[K1+1] = 1;
    work[K1] = 1;
    
    for(int i=K1+1; i<=n; i++){
        for(int j=K1+1; j<=K2+1; j++){
            if(i-j>=1){
                rest[i] += rest[i-j];
            }else{
                rest[i]++;
                break;
            }
        }
        
        for(int j=K1; j<=K2; j++){
            if(i-j>=1){
                work[i] += rest[i-j];
            }else{
                work[i]++;
                break;
            }
        }
        
    }
    
    cout << rest[n] + work[n];
    
    return 0;
}