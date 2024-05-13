#include<bits/stdc++.h>
using namespace std;

int INF = 1e9;
int D[11];
int iMem[11][10001];

// To find the minimum of coins to make x with i coins:{D[1], D[2], ..., D[i]}
int MinCoin(int i, int x){
    if(x<0) return INF;
    if(x==0) return 0;
    if(i==0) return INF;

    if(iMem[i][x] != -1) return iMem[i][x];
    int res = INF;
    res = min(res, 1 + MinCoin(i, x-D[i]));
    res = min(res, MinCoin(i-1, x));
    iMem[i][x] = res;
    return res;
}

void Trace(int i, int x){
    if(x<0) return;
    if(x==0) return;
    if(i==0) return;

    int res = INF;
    if(iMem[i][x]== 1+MinCoin(i, x-D[i])){
        cout << D[i] << " ";
        Trace(i, x-D[i]);
    }
    else{
        Trace(i-1, x);
    }
}

int main(){
    memset(iMem, -1, sizeof(iMem));


    return 0;
}