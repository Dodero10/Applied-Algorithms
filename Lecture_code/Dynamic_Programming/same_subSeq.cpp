#include<bits/stdc++.h>
using namespace std;

string X = "abcb";
string Y = "bdcab";
int iMem[1001][1001];

int LCS(int i, int j){
    if(i==0 || j==0) return 0;

    if(iMem[i][j] != -1) return iMem[i][j];
    else{
        int res = 0;
        res = max(res, LCS(i-1, j));
        res = max(res, LCS(i, j-1));
        if(X[i] == y[j]){
            res = max(res, 1 + LCS(i-1, j-1));
        }
        iMem[i][j] = res;
        return res;
    }
}

void Trace(int i, int j){
    if(i==0 || j==0) return;
    if(iMem[i][j] == iMem[i-1][j]){
        Trace(i-1, j);
        return;
    }
    if(iMem[i][j] == iMem[i][j-1]){
        Trace(i, j-1);
        return;
    }
    if(iMem[i][j] = 1 + iMem[i-1][j-1]){
        Trace(i-1, j-1);
        cout << X[i] << " ";
        return;
    }
}

int main(){
    memset(iMem, -1, sizeof(iMem));

    return 0;
} 