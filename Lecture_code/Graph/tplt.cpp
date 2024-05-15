#include<bits/stdc++.h>
using namespace std;

vector<int> Adj[1001];
vector<int> iComponent(1001, -1);

void findComponent(int curr_com, int u){
    if(iComponent[u] != -1) return;
    iComponent[u] = curr_com;
    for(int v: Adj[u]){
        findComponent(curr_com, v);
    }
}

int main(){
    int n, m;
    int num_comp = 0;
    for(int u = 1; u<=n; u++){
        if(iComponent[u] == -1){
            findComponent(num_comp, u);
            num_comp++;
        }
    }

    return 0;
}