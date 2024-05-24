#include<bits/stdc++.h>
using namespace std;

const long long Q = 1e9 + 7;
int n;

int count_N_sum_positive_int(int n){
    int a[n+1];
    memset(a, 0, sizeof(a));
    a[0] = 1;
    for(int i=1; i<n; i++){
        for(int j=i; j<=n; j++){
            a[j] += a[j-i];
        }
    }
    return a[n]+1;
}

int main(){
    cin >> n;
    int res = count_N_sum_positive_int(n)+1;
    cout << res % Q;
    return 0;
}