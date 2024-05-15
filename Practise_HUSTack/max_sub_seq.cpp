#include<bits/stdc++.h>
using namespace std;

int A[1000000];
int n;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    int sum = A[0];
    int res = A[0];

    for(int i=0; i<n; i++){
        sum = max(sum, 0) + A[i];
        res = max(res, sum);
    }

    return 0;
}