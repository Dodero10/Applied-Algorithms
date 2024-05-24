#include<bits/stdc++.h>
using namespace std;

int n, K, Q;
int cost[100][100];
int d[15];    // d[i] là khối lượng hàng hóa của khách hàng i

vector<int> a[15]; // a[i] là tập các khách hàng mà xe i đang chở
int path[15][15]; // path[i][j] là khách hàng thứ j mà xe i đang chở
int workload[15]; // workload[i] là khối lượng hàng hóa mà xe i đang chở
int curr[15];      // curr[i] là chi phí hiện tại của xe i (cost distance)
int visited[15]; // visited[i] = 1 nếu khách hàng i đã được phục vụ, 0 nếu chưa
int res = INT_MAX;
int res_x[15];     // res_x[i] là chi phi của xe i trong lời giải tốt nhất

bool is_x_visited(int x){    // kiểm tra xem khách hàng x đã được chở chưa
    if (visited[x]==1)  return false;
    return true;
}

bool check(int i, int x){   // kiểm tra xem khách hàng i có thể được chở bởi xe x không
    if(workload[x] + d[i] > Q) return false;
    return true;
}

void Try_x(int x, int k){   // thử tất cả các khách hàng k có thể được chở bởi xe x
    for(int i : a[x]){
        if(is_x_visited(i)){
            path[x][k] = i; // khách hàng thứ k mà xe x đang chở là i
            curr[x] += cost[path[x][k-1]][i]; // cập nhật chi phí của xe x
            visited[i] = 1; // đánh dấu khách hàng i đã được phục vụ

            if(k==a[x].size()){
                res_x[x] = min(res_x[x], curr[x] + cost[i][0]); // nếu đã chở hết khách hàng thì cập nhật kết quả
            }
            else{
                Try_x(x, k+1); // thử chở khách hàng tiếp theo
            }
            visited[i] = 0; // bỏ đánh dấu khách hàng i
            curr[x] -= cost[path[x][k-1]][i]; // bỏ cập nhật chi phí của xe x

        }
    }
}

void Try(int k){
    for(int i=0; i< K; i++){
        if(check(k, i)){
            a[i].push_back(k);
            workload[i] += d[k];

            if(k==n){   // nếu đã chở hết khách hàng
                int curr = 0;
                for(int j=0; j< K; j++){    
                    if(a[j].size() > 0){
                        res_x[j] = INT_MAX;
                        path[j][0] = 0; // xe j xuất phát từ kho
                        Try_x(j, 1);    // thử chở khách hàng cho xe j
                        curr += res_x[j];   // cập nhật chi phí của lời giải
                    }
                }
                res = min(res, curr);   // cập nhật kết quả
            }
            else{
                Try(k+1);
            }

            a[i].pop_back();
            workload[i] -= d[k];
        }
    }
}




int main(){
    cin >> n >> K >> Q;
    for(int i=1; i<=n; i++){
        cin >> d[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> cost[i][j];
        }
    }

    Try(1);
    cout << res;

    return 0;
}