#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> d;  // Time to complete each task
vector<vector<int>> graph; // Adjacency list of the graph
vector<int> indegree; // Indegree of each node
vector<int> completion_time; // Earliest time to complete each task

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1);
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> completion_time(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }

    // Topological sorting using Kahn's algorithm
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            completion_time[i] = d[i];  // Starting point for the schedule
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
            // Calculate the earliest time the task can be completed
            completion_time[neighbor] = max(completion_time[neighbor], completion_time[node] + d[neighbor]);
        }
    }

    // Get the maximum completion time
    int result = *max_element(completion_time.begin(), completion_time.end());
    cout << result << endl;

    return 0;
}
