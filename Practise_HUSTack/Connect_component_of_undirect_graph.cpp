#include<bits/stdc++.h>

using namespace std;

// Hàm duyệt bfs từ một đỉnh
void bfs(int start, vector<bool>& visited, const vector<vector<int>>& adj){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Hàm duyệt dfs từ một đỉnh
void dfs(int start, vector<bool>& visited, const vector<vector<int>>& adj){
    visited[start] = true;
    
    for(int neighbor : adj[start]){
        if(!visited[neighbor]){
            dfs(neighbor, visited, adj);
        }
    }
}


// Hàm đếm số thành phần liên thông của đồ thị
int countConnectedComponents(int N, const vector<vector<int>>& adj){
    vector<bool> visited(N+1, false);
    int numComponents = 0;

    for(int i=0; i<=N; ++i){
        if(!visited[i]){
            bfs(i, visited, adj);
            numComponents++;
        }
    }

    return numComponents;
}


int main(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> adj(N+1);

    for (int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << countConnectedComponents(N, adj) << endl;

    return 0;
}