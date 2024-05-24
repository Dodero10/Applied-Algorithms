#include<bits/stdc++.h>
using namespace std;

int m, n;
vector<int> res;

void gen(int start){
    if(res.size() == m){
        for(int re : res){
            cout << re << " ";
        }
        cout << endl;
    }
    for(int i=start; i<=n; i++){
        res.push_back(i);
        gen(i+1);
        res.pop_back();
    }
}

int main(){
    cin >> m >> n;
    gen(1);
    return 0;
}