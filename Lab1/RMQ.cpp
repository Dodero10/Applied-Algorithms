#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int n;
int a[maxN];
int rmq[maxN][30];
int res = 0;

void RMQ(){
    for(int i=0; i<n; i++){
        rmq[i][0] = a[i];
    }
    
    for(int j=1; 1<<j <=n; j++){
        for(int i=0; i + (1<<j) -1 <n; i++){
            rmq[i][j] = min(rmq[i][j-1], rmq[i + (1<<(j-1))][j-1]);
        }
    }
}

int req(int l, int r){
    int i = (int)log2(r-l+1);
    if(rmq[l][i] < rmq[r-(1<<i)+1][i]) 
        return rmq[l][i];
    else return rmq[r-(1<<i)+1][i];
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    RMQ();
    
    int q; cin >> q;
    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        res += req(l, r);
    }
    
    cout << res;
    
    return 0;
}