#include<bits/stdc++.h>
using namespace std;

int n, L;

int main(){
    cin >> n >> L;
    for(int i=0; i<n; i++){
        int ai;
        cin >> ai;
        string key = to_string(ai);
        key = string(L-key.length(), '0') + key;
        cout << key << endl;
    }
    
    
    return 0;
}