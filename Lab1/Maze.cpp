#include<bits/stdc++.h>
using namespace std;

struct state{
    int i, j, c;
    state(int _i=0, int _j=0, int _c=0): i(_i), j(_j), c(_c) {}
};

int maze[1005][1005];
int visited[1005][1005];

int main(){
    int m, n, r, c;
    cin >> m >> n >> r >> c;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> maze[i][j];
        }
    }
    
    visited[r][c] = 1;
    queue<state> q;
    q.push(state(r, c));
    
    //bfs
    while(!q.empty()){
        state u = q.front();
        q.pop();
        
        vector<state> g = {};
        
        if(u.i-1>0 && maze[u.i-1][u.j] != 1){
            g.push_back(state(u.i-1, u.j));
        }
        
        if(u.i+1<=m && maze[u.i+1][u.j] != 1){
            g.push_back(state(u.i+1, u.j));
        }
        
        if(u.j-1>0 && maze[u.i][u.j-1] != 1){
            g.push_back(state(u.i, u.j-1));
        }
        
        if(u.j+1<=n && maze[u.i][u.j+1] != 1){
            g.push_back(state(u.i, u.j+1));
        }
        
        // Duyet qua cac o lan can
        for(state v : g){
            if(!visited[v.i][v.j]){
                v.c = u.c+1;
                visited[v.i][v.j] = 1;
                q.push(v);
                
                if((v.i==1 || v.i==m) || (v.j==1 || v.j==n)){
                    cout << v.c + 1;
                    exit(1);
                }
            }
        }

        
    }
    
    cout << -1;
    return 0;
}