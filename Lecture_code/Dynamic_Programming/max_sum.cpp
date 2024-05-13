#include<bits/stdc++.h>
using namespace std;

int A[1001];
int iMem[1001];
bool bMark[1001];

int MaxSum(int i){
    if(i==1) return A[i];
    if(bMark[i]) return iMem[i];
    int res = max(A[i], A[i]+MaxSum(i-1));
    iMem[i] = res;
    bMark[i] = true;
    return res;
}

void Trace(int i){
    if(i!=1 && iMem[i] == A[i]+iMem[i-1]){
        Trace(i-1);
    }
    cout << A[i] << " ";
}

int main(){
    memset(bMark, 0, sizeof(bMark));
    int n;
    int ans;
    for(int i=0; i<n; i++){
        ans = max(ans, iMem[i]);
    }
    return 0;
}