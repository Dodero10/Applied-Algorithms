#include<bits/stdc++.h>
using namespace std;

int timeDfs=0;
int num[100005];
int low[100005];
vector<int> g[100005];
int tail[100005];

void dfs(int u, int pre){
    num[u] = low[u] = ++timeDfs;
    for(int v:g[u]){
        if(v==pre) continue;
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    tail[u] = timeDfs;
}