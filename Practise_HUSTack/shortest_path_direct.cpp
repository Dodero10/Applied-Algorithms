#include<bits/stdc++.h>

using namespace std;

const long long MAX = 100010;

struct comp{
    bool operator() (pair<long long, long long> a, pair<long long, long long> b){
        return a.second > b.second;
    }
};

long long n, m;
vector< vector<pair<long long, long long> > > Graph;
long long s, t;

void inputData(){
    cin >> n >> m;
    Graph.resize(n+1);
    for (long long i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }

    cin >> s >> t;
}

long long DijkstraAlgorithm(){
    priority_queue<pair<long long, long long>, vector< pair<long long, long long> >, comp> q;
    long long dist[MAX];

    for (long long i = 1; i <= n; i++){
        dist[i] = 1e9;
    }
    dist[s] = 0;
    for (long long i = 1; i <= n; i++){
        q.push({i, dist[i]});
    }

    // dijkstra algorithm
    while (!q.empty()){
        pair<long long, long long> x = q.top(); 
        q.pop();
        long long x_point = x.first;

        for (auto v : Graph[x_point]){
            long long v_point = v.first;
            long long v_dist = v.second;

            if (dist[v_point] > dist[x_point] + v_dist){
                dist[v_point] = dist[x_point] + v_dist;
                q.push({v_point, dist[v_point]});
            }
        }
    }

    return dist[t];
}

int main(int argc, const char** argv) {
    inputData();
    cout << DijkstraAlgorithm();
    return 0;
}
