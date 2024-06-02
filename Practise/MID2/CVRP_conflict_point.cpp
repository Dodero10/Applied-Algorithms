// ### Đề bài: LẬP LỊCH GIAO HÀNG PEPSI

// **Mô tả:**

// Một đội gồm K xe tải giống hệt nhau có tải trọng Q cần được lên lịch để giao các kiện hàng Pepsi từ kho trung tâm 0 đến các khách hàng 1,2,…, n. Mỗi khách hàng i yêu cầu d[i] kiện hàng. Khoảng cách từ vị trí i đến vị trí j là c[i,j], 0≤i,j≤n. Do một số hạn chế kỹ thuật, có một danh sách F các cặp khách hàng (i,j) không thể được phục vụ bởi cùng một xe tải. Một giải pháp giao hàng là một tập hợp các tuyến đường: mỗi xe tải được gắn với một tuyến đường, bắt đầu từ kho, ghé thăm một số khách hàng và quay lại kho để giao các kiện hàng Pepsi được yêu cầu sao cho:

// - Mỗi khách hàng được ghé thăm đúng một lần bởi một tuyến đường.
// - Tổng số kiện hàng được yêu cầu bởi các khách hàng của mỗi xe tải không vượt quá tải trọng của nó.
// - Nếu (i,j) nằm trong F, thì khách hàng i và j phải được ghé thăm bởi các xe tải khác nhau.

// **Mục tiêu:** Tìm giải pháp có tổng khoảng cách di chuyển nhỏ nhất.

// **Lưu ý:**

// - Có thể có trường hợp một xe tải không ghé thăm bất kỳ khách hàng nào (tuyến đường trống).
// - Thứ tự của các khách hàng trong một tuyến đường là quan trọng, ví dụ: các tuyến 0 -> 1 -> 2 -> 3 -> 0 và 0 -> 3 -> 2 -> 1 -> 0 là khác nhau.

// **Đầu vào:**

// - Dòng 1: n, K, Q (2≤n≤12, 1≤K≤5, 1≤Q≤50)
// - Dòng 2: d[1],...,d[n] (1≤d[i]≤10)
// - Dòng i+3 (i=0,…,n): dòng thứ i của ma trận khoảng cách c (1≤c[i,j]≤30)
// - Dòng n+4: chứa một số nguyên M là số cặp trong danh sách F (0 ≤ M ≤ n*(n-1)/2)
// - Dòng m + n + 4 (m = 1,...,M): chứa 2 số nguyên dương i và j: (i,j) là cặp thứ m trong danh sách F

// **Đầu ra:**

// - Tổng khoảng cách di chuyển nhỏ nhất hoặc in ra -1 nếu bài toán không có giải pháp nào.

// **Ví dụ:**

// Đầu vào:

// 3 2 7
// 3 2 3
// 0 2 3 1  
// 4 0 1 3  
// 2 3 0 4 
// 3 2 4 0
// 1  
// 1 2


// Đầu ra:

// 13

#include<bits/stdc++.h>
using namespace std;
int n, m ,q,p;
int d[15];
vector<int> a[15];
int c[15][15];
int path[15][15];
int workload[15];
int curr[15];
int visited[15];
int res=INT_MAX;
int res_x[15];
vector<int> except[15];

bool check_x(int x){
    if (visited[x]==1){
        return false;
     }
     else{
	         return true;
			      }
}

void Try_x(int x, int k){
  	for(int i : a[x]){
         if(check_x(i)){
        	path[x][k]=i;
        	curr[x]+=c[path[x][k-1]][i];
			visited[i]=1;

           if (k==a[x].size()){
                res_x[x]=min(res_x[x], curr[x]+c[i][0]);
            }

            else{
                Try_x(x, k+1);
             }

            visited[i]=0;
           curr[x]-=c[path[x][k-1]][i];
        }
    }
}



bool check(int i, int x){
    if (workload[x]+d[i]>q){
        return false;
   }
    for(int k: except[i]){
        for (int k1: a[x]){
            if(k==k1) 
                return false;
        }
    }
   return true;
}

void Try(int k){
     for(int i=0; i<m; i++){
       if(check(k, i)){
           a[i].push_back(k);
           workload[i]+=d[k];

           if(k==n){
               int curr=0;
              for(int i=0; i<m; i++){
                   if (a[i].size()>0){
                        res_x[i]=INT_MAX;
                       path[i][0]=0;
                       Try_x(i, 1);
                       curr+=res_x[i];
                    }
               }
               res=min(res, curr);          
			}
            else Try(k+1);

           a[i].pop_back();
          workload[i]-=d[k];
       }
   }
}

int main(){
    cin >> n >>m >>q;
    for(int i=1; i<=n; i++){
        cin >>d[i];
    }
    
     for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> c[i][j];
        }
    }
    cin >>p;
    int node1, node2;
    for(int i=0; i<p; i++){
        cin >>node1 >>node2;
        except[node1].push_back(node2);
        except[node2].push_back(node1);
    }

	Try(1);

    cout<<res;

}