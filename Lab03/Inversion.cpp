#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

vector<int> a;
int n;
vector<int> d(100001, 0);
int res = 0;

void update(vector<int>& a, int idx, int u){
    while(idx<=n){
        a[idx] += u;
        idx += (idx & -idx);
    }
}

int query(vector<int>& a, int idx){
    int sum = 0;
    while(idx>0){
        sum += a[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main(){
    cin >> n;
    
    a.resize(n);
    
    for(int & x : a){
        cin >> x;
    }
    
    
    for(int i=n-1; i>=0; i--){
        res += query(d, a[i]-1);
        res %= MOD;
        update(d, a[i], 1);
    }
    
    cout << res;
    
}