// Cho đồ thị có hướng không chu trình (Directed Acyclic Graph - DAG) G(V,E). Hãy đánh số lại các đỉnh của G
//  sao cho chỉ có cung nối từ đỉnh có chỉ số nhỏ đến đỉnh có chỉ số lớn hơn

// Input

// Dòng đầu chứa hai số nguyên n và m là số đỉnh và số cung của đồ thị G
// m dòng tiếp theo, mỗi dòng chứa một cặp số u,v cho biết một cung nối từ u tới v trong G

// Output
// Ghi ra n số nguyên dương, số thứ i là chỉ số của đỉnh thứ i sau khi đánh số lại. Hai số trên cùng một dòng được ghi cách nhau một dấu cách.

#include<bits/stdc++.h>
using namespace std;

const int maxN = 110;

int n, m;
int indegree[maxN] = {0} ;// Lưu số lượng cung vào mỗi đỉnh
int ans[maxN] = {0};    //  Nảng đánh số lại các đỉnh
vector<int> g[maxN];  //  Danh sách cạnh kề của mỗi đỉnh
vector<int> topo;        // Danh sách thứ tự topo
queue<int> listSource;   // Danh sách các đỉnh không có cung vào


int main(){
    cin >> n >> m;
    while (m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indegree[v]++;
    }

    for(int u=1; u<=n; u++){
        if(indegree[u] == 0){
            listSource.push(u);
        }
    }

    while(!listSource.empty()){
        int u = listSource.front();
        listSource.pop();
        topo.push_back(u);

        for(auto v : g[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                listSource.push(v);
            }
        }
    }

    int cnt = 0;
    for(auto x : topo){
        ans[x] = ++cnt;
    }

    for(int i=0; i<=n; ++i) cout << ans[i] << " ";

    return 0;
}