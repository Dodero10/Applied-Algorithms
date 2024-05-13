#include<bits/stdc++.h>

using namespace std;

int n;
int a[1000];

int MidMaxLeft(int i, int j){
    int s = 0;
    int maxL = a[j];
    for(int left=j; left>=i; left--){
        s += a[left];
        maxL = max(maxL, s);
    }
    return maxL;
}

int MidMaxRight(int i, int j){
    int s = 0;
    int maxR = a[i];
    for(int r = i; r <= j; r++) {
        s+= a[r];
        maxR = max(maxR, s);
    }
    return maxR;
}

int subSeqMax(int i, int j){
    if(i==j)    return a[i];
    int mid = (i+j)/2;
    int wL = subSeqMax(i, mid);
    int wR = subSeqMax(mid+1, j);
    int midL = MidMaxLeft(i, mid);
    int midR = MidMaxRight(mid+1, j);
    int rs = max(max(wL, wR), midL + midR);
    return rs;
}

int main(){

    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int rs = subSeqMax(0, n-1);
    cout << rs;
}