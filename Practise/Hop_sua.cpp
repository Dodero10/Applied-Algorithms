#include<bits/stdc++.h>
using namespace std;

int n, S;
vector<int> a;
vector<int> visited;
int res = 0;
int sum = 0;

void Try(int k){
    for(int i=k; i<n; i++){
        if(1){
            sum += a[i];
            if(sum >= S && sum%5==0){
                res += pow(2, n-i-1);
            }
            else {
                cout << k+1 << i+1 << " ";
                Try(i+1);
            }
            sum -= a[i];
        }
    }
}

int main(){
    cin >> n;
    a.resize(n);
    visited.resize(n, 0);
    
    for(int& x : a) cin >> x;
    
    cin >> S;
    
    Try(0);
    
    cout << res;
    
    return 0;
}