// // Bạn cần kiểm tra một chu trình Hamilton cho bài toán người du lịch (Traveling Salesman Problem - TSP) với một số ràng buộc trước và tính tổng chi phí của chu trình nếu nó hợp lệ. Nếu chu trình không hợp lệ, in ra -1.

// // Chi tiết:

// // Đầu vào:

// // Số lượng đỉnh n của đồ thị.
// // Một chuỗi part gồm n đỉnh, biểu thị thứ tự các đỉnh trong chu trình Hamilton.
// // Ma trận chi phí c kích thước n x n, trong đó c[i][j] biểu thị chi phí từ đỉnh i đến đỉnh j.
// // Số lượng ràng buộc k.
// // k cặp ràng buộc (c1, c2) biểu thị rằng đỉnh c1 phải được thăm trước đỉnh c2.
// // Đầu ra:

// // Tổng chi phí của chu trình Hamilton nếu hợp lệ.
// // -1 nếu chu trình không thỏa mãn các ràng buộc.
// Input:
// 4
// 1 2 3 4
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0
// 2
// 2 3
// 1 4

// Output:
// 80

#include <bits/stdc++.h>
using namespace std;

int n;
int part[1005];
int visited[1005];
int c[1005][1005];


int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        cin >> part[i];
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>>c[i][j];
        }
    }
    vector<vector<int>> before(n+1);
    int k;
    int c1, c2;
    cin>>k;
    for(int j=0; j<k; j++){
        cin >> c1 >> c2;
        before[c2].push_back(c1);
    }
    int sum=0;
    for(int c_before:before[part[1]]){
        if (visited[c_before]!=1){
            cout<<-1;
            return 0;
        }
    }
    visited[part[1]]=1;
    for(int i=2; i<=n; i++){
        for(int c_before:before[part[i]]){
            if (visited[c_before]!=1){
                cout<<-1;
                return 0;
            }
        }
        visited[part[i]]=1;
        sum=sum+c[part[i-1]][part[i]];
    }
    sum+=c[part[n]][part[1]];
    cout<<sum;

}
