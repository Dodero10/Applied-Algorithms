#include<bits/stdc++.h>
using namespace std;

struct Node{
    int node;   // số hiệu thành phố
    int cost;   // chi phí đến thành phố
};

struct cmp{
    bool operator()(Node a, Node b){
        return a.cost > b.cost;
    }
};

int n, m;   // n: số lượng thành phố, m: số lượng đường kết nối giữa các thành phố
vector<int> graph[5005];    // danh sách kề lưu các đường nối giữa các thành phố
int cost[5005][5005];   // cost[i][j] lưu chi phí từ thành phố i đến thành phố j
int d[5005];    // lưu trữ giới hạn số thành phố tối đa mà tuyết xe buýt đi trong 1 hành trình
vector<pair<int, int>> bus_map[5005];   // lữu trữ các kết nối trong cùng 1 thành phố thông qua các tuyết xe buýt
// first: số hiệu thành phố đích
// second: chi phí đến thành phố đích
int dist[5005]; // lưu trữ khoảng cách từ 1 thành phố nguồn đến các thành phố khác (bfs)
vector<int> D(5005, INT_MAX);   // chi phí tối thiểu để đi từ thành phố 1 đến thành phố i (dijsktra)
int visited[5005];  // các thành phố được xử lí trong dijsktra





int main(){

    return 0;
}