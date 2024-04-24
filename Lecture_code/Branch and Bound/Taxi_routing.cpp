#include<bits/stdc++.h>
using namespace std;

#define MAX 20
int n, c[MAX][MAX];
int c_min = INT_MAX;
int best = INT_MAX;
int mark[MAX] = {0};
int x[MAX];
int curr = 0;

int check(int i){
    return x[i];
}

int input(){
    cin >> n;
    for(int i=1; i<=2*n+1; ++i){
        for(int j=1; j<=2*n+1; ++j){
            cin >> c[i][j];
            }
        }
    }

bool check(int k, int v){
    if(mark[v]) return false;
    if(v!=1 && v<=n && !mark[v+n]) return false;    // Không thể ghé đến điểm trả khách trước khi đón
    return true;
}

void Try(int k){
    for(int i=1; i<2*n+1; i++){
        if(check(k, i)){
            x[k] = i;
            mark[i] = k;
            curr += c[x[k-1]][i];
            if(k==2*n){
                if(curr + c[i][0] < best)   best = curr + c[i][0];
            }else{
                Try(k+1);
            }
            curr -= c[x[k-1]][i];
            mark[i] = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    x[0] = 0;
    mark[0] = 1;

    Try(1);
    cout << best << endl;
    return 0;

    return 0;
}