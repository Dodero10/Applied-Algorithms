#include<bits/stdc++.h>
using namespace std;

int n, M;

int sol(vector<int>& a, int currSum, int idx){
    if(currSum > M) return 0;
    if(idx==n) return (currSum==M) ? 1 : 0;
    int sumSol = 0;
    for(int i=1; i<= (M-currSum)/a[idx]; i++){
        sumSol += sol(a, currSum + a[idx]*i, idx+1);
    }
    return sumSol;
}


int main(){
    cin >> n >> M;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    cout << sol(a, 0, 0);
    
    return 0;
}