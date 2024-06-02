#include<bits/stdc++.h>
using namespace std;

int n, k;
int c[30][30];
int A[30];
vector<int> mark(40, 0);
vector<int> inBus(40, 0);
// int inBus[40] = {0};
int passInBus = 0;
int res = INT_MAX;
int curr = 0;

bool check(int i){
    if(curr>res) return false;
    
    if(mark[i] == 0){
        if(i>n){
            if(inBus[i-n]==1) return true;
        }else{
            if(inBus[i]==0 && passInBus<k) return true;
        }
    }
    return false;
}

void Try(int x){
    for(int i=1; i<=2*n; i++){
        if(check(i) && (curr+c[A[x-1]][i]+2*n-x)<=res){
            mark[i] = 1;
            A[x] = i;
            curr = curr + c[A[x-1]][A[x]];
            
            if(i>n){
                passInBus--;
                inBus[i-n]=0;
            }else{
                passInBus++;
                inBus[i] = 1;
            }
            
            if(x==2*n){
                res = min(res, curr + c[A[x]][0]);
            }else{
                Try(x+1);
            }

            curr = curr - c[A[x-1]][A[x]];
            mark[i] = 0;
            
            if(i>n){
                passInBus++;
                inBus[i-n]=1;
            }else{
                passInBus--;
                inBus[i]=0;
            }
            
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    
    for(int i=0; i<=2*n; i++){
        for(int j=0; j<=2*n; j++){
            cin >> c[i][j];
        }
    }
    
    A[0] = 0;
    Try(1);
    cout << res;
    
    return 0;
}
