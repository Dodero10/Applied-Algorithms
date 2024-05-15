#include<bits/stdc++.h>
using namespace std;

int A[1001];
int iMem[1001];
int n;

int LIS(int i){
    if(iMem[i] == -1) return iMem[i];
    int res = 1;

    for(int j=1; j<i; j++){
        if(A[j] < A[i]){
            res = max(res, 1 + LIS(j));
        }
    }
    iMem[i] = res;
    return res;
}

void Trace(int i){
    int res = 1;
    for(int j = i-1; j<=n; j++){
        if(A[j] < A[i]  && iMem[j] + 1 == iMem[i]){
            Trace(j);
            break;
        }
    }
    cout << i << " ";
}

int main(){
    memset(iMem, -1, sizeof(iMem));
    int ans;
    for(int i=1;i<=n; i++){
        ans = max(ans, LIS(i));
    }
    cout << ans;
    return 0;
}