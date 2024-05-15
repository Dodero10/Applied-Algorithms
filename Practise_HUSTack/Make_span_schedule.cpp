#include<bits/stdc++.h>
using namespace std;

int n, m;   
vector<int> duration(1001);
vector<vector<int>> adj(1001);
vector<int> inDegree(1001);
vector<int> completeTime(1001, 0);

int main(){
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> duration[i];
        completeTime[i] = duration[i];
    }

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        ++inDegree[v];
    }

    // Topological sort
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            --inDegree[v];
            completeTime[v] = max(completeTime[v], completeTime[u] + duration[v]);
            if(--inDegree[v]==0){
                q.push(v);
            }
        }
    }

    int res = *max_element(completeTime.begin(), completeTime.end());
    cout << res;


    return 0;
}