#include <bits/stdc++.h>

using namespace std;

const int maxN = 110;

int n, m;   // Số đỉnh và số cung của đồ thị
int visited[maxN], ans[maxN]; // visited[u] = 0: chưa thăm, 1: đang thăm, 2: đã thăm
vector <int> g[maxN]; // Danh sách cạnh kề của mỗi đỉnh
stack <int> topo; // Danh sách thứ tự topo

void dfs(int u) {
    visited[u] = 1;
    for (auto v : g[u]) {
        if (visited[v] == 1) {
            cout << "Error: graph contains a cycle";
            exit(0);
        }
        if (!visited[v]) dfs(v);
    }
    topo.push(u);
    visited[u] = 2;
}

main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs(i);

    /* Sau khi xác định được thứ tự Tô-pô của đồ thị, ta sử dụng
       mảng ans để đánh số lại các đỉnh */
    int cnt = 0;
    while (!topo.empty()) {
        ans[topo.top()] = ++cnt; 
        topo.pop();
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}